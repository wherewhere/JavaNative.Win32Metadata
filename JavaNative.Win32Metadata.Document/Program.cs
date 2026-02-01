using AngleSharp;
using AngleSharp.Dom;
using AngleSharp.Html.Dom;
using MessagePack;
using Microsoft.Windows.SDK.Win32Docs;
using System.Collections.Concurrent;
using System.Text;

using CancellationTokenSource cts = new();
Console.CancelKeyPress += (s, e) =>
{
    Console.WriteLine("Canceling...");
    cts.Cancel();
    e.Cancel = true;
};

if (args.Length < 2)
{
    Console.Error.WriteLine("USAGE: {0} <path-to-output-pack> <path-to-rsp>");
    return 1;
}

string outputPath = args[0];
string documentationMappingsRsp = args[1];

try
{
    Console.WriteLine("Parsing documents...");

    ConcurrentDictionary<string, ApiDetails> results = [];

    IBrowsingContext context = BrowsingContext.New(Configuration.Default.WithDefaultLoader());
    const string helpLink = "https://docs.oracle.com/en/java/javase/25/docs/specs/jni/invocation.html";
    IDocument document = await context.OpenAsync(helpLink, cts.Token);
    using IEnumerator<IHtmlHrElement> enumerator = document.QuerySelectorAll<IHtmlHrElement>("main>hr").GetEnumerator();
    while (enumerator.MoveNext())
    {
        IElement current = enumerator.Current;
        ApiDetails details = new();
        StringBuilder builder = new();
        ApiKind kind = ApiKind.Description;
        string param = string.Empty;
        while (current.NextElementSibling is IElement element)
        {
            switch (current = element)
            {
                case IHtmlHeadingElement heading:
                    switch (heading)
                    {
                        case { TagName: "H1" or "H2" }:
                            continue;
                        case { TagName: "H3" }:
                            string apiName = heading.TextContent.Trim();
                            details.HelpLink = new Uri($"{helpLink}#{heading.Id}");
                            results[apiName] = details;
                            break;
                        case { TagName: "H4" }:
                            switch (kind)
                            {
                                case ApiKind.Description:
                                    details.Description = builder.ToString();
                                    break;
                                case ApiKind.Remarks:
                                    details.Remarks = builder.ToString();
                                    break;
                                case ApiKind.Parameters:
                                    if (!string.IsNullOrEmpty(param))
                                    {
                                        details.Parameters[param] = builder.ToString();
                                        _ = builder.Clear();
                                    }
                                    break;
                                case ApiKind.ReturnValue:
                                    details.ReturnValue = builder.ToString();
                                    break;
                            }
                            _ = builder.Clear();
                            switch (heading.TextContent.Trim())
                            {
                                case "LINKAGE:":
                                    kind = ApiKind.Remarks;
                                    break;
                                case "PARAMETERS:":
                                    kind = ApiKind.Parameters;
                                    details.Parameters = [];
                                    break;
                                case "RETURNS:":
                                    kind = ApiKind.ReturnValue;
                                    break;
                                default:
                                    kind = ApiKind.Unknown;
                                    break;
                            }
                            break;
                    }
                    break;
                case IHtmlParagraphElement paragraph when kind == ApiKind.Parameters:
                    if (paragraph.FirstElementChild is IHtmlElement { TagName: "CODE" } codeElement)
                    {
                        if (!string.IsNullOrEmpty(param))
                        {
                            details.Parameters[param] = builder.ToString();
                            _ = builder.Clear();
                        }
                        param = codeElement.TextContent.Trim();
                        _ = builder.AppendLine($"<para>{paragraph.RemoveElement(codeElement).InnerHtml.TrimStart(':')}</para>");
                    }
                    else
                    {
                        _ = builder.AppendLine($"<para>{paragraph.InnerHtml}</para>");
                    }
                    break;
                case IHtmlParagraphElement paragraph:
                    builder.AppendLine($"<para>{paragraph.InnerHtml}</para>");
                    break;
                case IHtmlHrElement hr:
                    goto end;

            }
        }
    end:;
    }

    Console.WriteLine($"Writing results to \"{outputPath}\" and \"{documentationMappingsRsp}\".");

    Directory.CreateDirectory(Path.GetDirectoryName(outputPath)!);
    await using FileStream outputFileStream = File.OpenWrite(outputPath);
    await MessagePackSerializer.SerializeAsync(outputFileStream, results, MessagePackSerializerOptions.Standard, cts.Token).ConfigureAwait(false);

    List<string> documentationMappingsBuilder = new(results.Count + 1)
    {
        "--memberRemap"
    };

    foreach (KeyValuePair<string, ApiDetails> api in results)
    {
        documentationMappingsBuilder.Add($"{api.Key.Replace(".", "::")}=[Documentation(\"{api.Value.HelpLink}\")]");
    }

    Directory.CreateDirectory(Path.GetDirectoryName(documentationMappingsRsp)!);
    await File.WriteAllLinesAsync(documentationMappingsRsp, documentationMappingsBuilder, cts.Token).ConfigureAwait(false);
}
catch (OperationCanceledException ex) when (ex.CancellationToken == cts.Token)
{
    return 2;
}

return 0;

file enum ApiKind
{
    Unknown,
    Description = 1,
    Remarks,
    Parameters,
    Fields,
    ReturnValue
}