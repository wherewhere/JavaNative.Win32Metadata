using MessagePack;
using Microsoft.Windows.SDK.Win32Docs;

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

    Dictionary<string, ApiDetails> results = new()
    {
        #region jawt.h
        {
            "JAWT_GetAWT",
            new ApiDetails
            {
                HelpLink = new Uri("https://docs.oracle.com/en/java/javase/25/docs/specs/AWT_Native_Interface.html"),
                Description =
                    """
                    Get the AWT native structure. This function returns JNI_FALSE if
                    an error occurs.
                    """
            }
        },
        #endregion
        #region jni.h
        {
            "JNI_GetDefaultJavaVMInitArgs",
            new ApiDetails
            {
                HelpLink = new Uri("https://docs.oracle.com/en/java/javase/25/docs/specs/jni/invocation.html#jni_getdefaultjavavminitargs"),
                Description = "Returns a default configuration for the Java VM. Before calling this function, native code must set the <c>vm_args->version</c> field to the JNI version it expects the VM to support. After this function returns, <c>vm_args->version</c> will be set to the actual JNI version the VM supports.",
                Remarks = "Exported from the native library that implements the Java virtual machine.",
                Parameters = new Dictionary<string, string>
                {
                    {
                        "args",
                        "a pointer to a <see cref=\"Java.Runtime.Native.JavaVMInitArgs\"/> structure in to which the default arguments are filled, must not be <see langword=\"NULL\"/>."
                    }
                },
                ReturnValue = "Returns <c>JNI_OK</c> if the requested version is supported; returns a JNI error code (a negative number) if the requested version is not supported."
            }
        },
        {
            "JNI_GetCreatedJavaVMs",
            new ApiDetails
            {
                HelpLink = new Uri("https://docs.oracle.com/en/java/javase/25/docs/specs/jni/invocation.html#jni_getcreatedjavavms"),
                Description =
                    """
                    Returns all Java VMs that have been created. Pointers to VMs are written in the buffer <paramref name="param0"/> in the order they are created. At most bufLen number of entries will be written. The total number of created VMs is returned in <paramref name="param2"/>.<br/>
                    Creation of multiple VMs in a single process is not supported.
                    """,
                Remarks = "Exported from the native library that implements the Java virtual machine.",
                Parameters = new Dictionary<string, string>
                {
                    {
                        "param0",
                        "pointer to the buffer where the VM structures will be placed, must not be <see langword=\"NULL\"/>."
                    },
                    {
                        "param1",
                        "the length of the buffer."
                    },
                    {
                        "param2",
                        "a pointer to an integer. May be a <see langword=\"NULL\"/> value."
                    }
                },
                ReturnValue = "Returns <c>JNI_OK</c> on success; returns a suitable JNI error code (a negative number) on failure."
            }
        },
        {
            "JNI_CreateJavaVM",
            new ApiDetails
            {
                HelpLink = new Uri("https://docs.oracle.com/en/java/javase/25/docs/specs/jni/invocation.html#jni_createjavavm"),
                Description =
                    """
                    <para>Loads and initializes a Java VM. The current thread is attached to the Java VM and becomes the main thread. Sets the <paramref name="penv"/> argument to the JNI interface pointer of the main thread.</para>
                    <para>Creation of multiple VMs in a single process is not supported.</para>
                    <para>The second argument to <see cref="JNI_CreateJavaVM"/> is always a pointer to <see cref="Java.Runtime.Native.JNIEnv*"/>, while the third argument is a pointer to a <see cref="Java.Runtime.Native.JavaVMInitArgs"/> structure which uses option strings to encode arbitrary VM start up options:
                    <code>typedef struct JavaVMInitArgs {
                    <br/>    jint version;
                    <br/>
                    <br/>    jint nOptions;
                    <br/>    JavaVMOption *options;
                    <br/>    jboolean ignoreUnrecognized;
                    <br/>} JavaVMInitArgs;</code></para>
                    <para>The options field is an array of the following type:
                    <code>typedef struct JavaVMOption {
                    <br/>    char *optionString;  /* the option as a string in the default platform encoding */
                    <br/>    void *extraInfo;
                    <br/>} JavaVMOption;</code></para>
                    <para>The size of the array is denoted by the <see cref="Java.Runtime.Native.JavaVMInitArgs.nOptions"/> field in <see cref="Java.Runtime.Native.JavaVMInitArgs"/>. If ignoreUnrecognized is <c>JNI_TRUE</c>, <see cref="JNI_CreateJavaVM"/> ignores all unrecognized option strings that begin with "<c>-X</c>" or "<c>_</c>". If ignoreUnrecognized is <c>JNI_FALSE</c>, <see cref="JNI_CreateJavaVM"/> returns <c>JNI_ERR</c> as soon as it encounters any unrecognized option strings.</para>
                    <para>The module related options, <c>--add-reads</c>, <c>--add-exports</c>, <c>--add-opens</c>, <c>--add-modules</c>, <c>--limit-modules</c>, <c>--module-path</c>, <c>--patch-module</c>, and <c>--upgrade-module-path</c> must be passed as option strings using their "<c>option=value</c>" format instead of their "option value" format. (Note the required = between "<c>option</c>" and "<c>value</c>".) For example, to export <c>java.management/sun.management</c> to <c>ALL-UNNAMED</c> pass option string "<c>--add-exports=java.management/sun.management=ALL-UNNAMED</c>".</para>
                    <para>In addition, each VM implementation may support its own set of non-standard option strings. Non-standard option names must begin with "<c>-X</c>" or an underscore ("<c>_</c>"). For example, the JDK/JRE supports <c>-Xms</c> and <c>-Xmx</c> options to allow programmers specify the initial and maximum heap size. Options that begin with "<c>-X</c>" are accessible from the "<c>java</c>" command line.</para>
                    <para>Here is the example code that creates a Java VM in the JDK/JRE:
                    <code>JavaVMInitArgs vm_args;
                    <br/>JavaVMOption options[3];
                    <br/>
                    <br/>options[0].optionString = "-Djava.class.path=c:\myclasses"; /* user classes */
                    <br/>options[1].optionString = "-Djava.library.path=c:\mylibs";  /* set native library path */
                    <br/>options[2].optionString = "-verbose:jni";                   /* print JNI-related messages */
                    <br/>
                    <br/>vm_args.version = JNI_VERSION_1_2;
                    <br/>vm_args.options = options;
                    <br/>vm_args.nOptions = 3;
                    <br/>vm_args.ignoreUnrecognized = TRUE;
                    <br/>
                    <br/>/* Note that in the JDK/JRE, there is no longer any need to call
                    <br/> * JNI_GetDefaultJavaVMInitArgs.
                    <br/> */
                    <br/>res = JNI_CreateJavaVM(&amp;vm, (void **)&amp;env, &amp;vm_args);
                    <br/>if (res &lt; 0) ...</code></para>
                    """,
                Remarks = "Exported from the native library that implements the Java virtual machine.",
                Parameters = new Dictionary<string, string>
                {
                    {
                        "pvm",
                        "pointer to the location where the resulting VM structure will be placed. It must not be <see langword=\"NULL\"/>."
                    },
                    {
                        "penv",
                        "pointer to the location where the JNI interface pointer for the main thread will be placed. It must not be <see langword=\"NULL\"/>."
                    },
                    {
                        "args",
                        " Java VM initialization arguments. It must not be <see langword=\"NULL\"/>."
                    }
                },
                ReturnValue = "Returns <c>JNI_OK</c> on success; returns a suitable JNI error code (a negative number) on failure."
            }
        }
        #endregion
    };

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