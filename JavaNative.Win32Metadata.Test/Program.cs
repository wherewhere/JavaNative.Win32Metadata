using Java.Runtime.Native;
using System.Runtime.InteropServices;
using Windows.Win32;
using Windows.Win32.Foundation;

Console.WriteLine($"Host Process .NET Version: {Environment.Version}");

unsafe
{
    using FreeLibrarySafeHandle __ = PInvoke.LoadLibrary("jre/bin/server/jvm.dll");
    JavaVMInitArgs vm_args = new()
    {
        version = JNI_VERSION.JNI_VERSION_21
    };
    Java.PInvoke.JNI_GetDefaultJavaVMInitArgs(ref vm_args);
    JNI_ERROR result = Java.PInvoke.JNI_CreateJavaVM(out JavaVM* jvm, out JNIEnv* env, vm_args);

    JNIEnv* list = stackalloc JNIEnv[1];
    InputJavaVMWithVersion GetEnv = jvm->functions->GetEnv.CreateDelegate<InputJavaVMWithVersion>();
    GetEnv(jvm, list, JNI_VERSION.JNI_VERSION_21);

    JavaVM** array = stackalloc JavaVM*[1];
    Java.PInvoke.JNI_GetCreatedJavaVMs(ref array[0], 1, out int length);

    Java.JClass system = env->functions->FindClass.CreateDelegate<FindClass>()(env, new PCSTR((byte*)Marshal.StringToHGlobalAnsi("java/lang/System")));
    if (!system.IsNull)
    {
        JMethodID getProperty = env->functions->GetStaticMethodID.CreateDelegate<GetStaticMethodID>()(env, system, new PCSTR((byte*)Marshal.StringToHGlobalAnsi("getProperty")), new PCSTR((byte*)Marshal.StringToHGlobalAnsi("(Ljava/lang/String;)Ljava/lang/String;")));
        if (!getProperty.IsNull)
        {
            JValue* _args = stackalloc JValue[1];
            _args[0] = new JValue() { l = env->functions->NewStringUTF.CreateDelegate<NewStringUTF>()(env, new PCSTR((byte*)Marshal.StringToHGlobalAnsi("java.version"))) };
            Java.JObject version = env->functions->CallStaticObjectMethodA.CreateDelegate<CallStaticObjectMethodA>()(env, system, getProperty, _args);
            if (!version.IsNull)
            {
                PCSTR str = env->functions->GetStringUTFChars.CreateDelegate<GetStringUTFChars>()(env, new Java.JString(version.Value), null);
                Console.WriteLine($"Java Version: {str}");
            }
        }
    }

    _ = Console.ReadKey();
}