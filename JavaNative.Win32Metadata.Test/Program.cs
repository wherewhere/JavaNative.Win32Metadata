using Java.Runtime.Native;
using System.Runtime.InteropServices;
using Windows.Win32;
using Windows.Win32.Foundation;

unsafe
{
    using var _ = PInvoke.LoadLibrary("jre/bin/server/jvm.dll");
    JavaVMInitArgs vm_args = new()
    {
        version = JNI_VERSION.JNI_VERSION_21
    };
    Java.PInvoke.JNI_GetDefaultJavaVMInitArgs(ref vm_args);
    JNI_ERROR result = Java.PInvoke.JNI_CreateJavaVM(out JavaVM* jvm, out JNIEnv* env, vm_args);
    Console.WriteLine(result);

    JavaVM** array = stackalloc JavaVM*[1];
    Java.PInvoke.JNI_GetCreatedJavaVMs(ref array[0], 1, out int length);
}