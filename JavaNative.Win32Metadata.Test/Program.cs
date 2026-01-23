using Java;
using Java.Runtime.Native;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation;

unsafe
{
    JavaVM* jvm = null;
    JNIEnv* env = null;
    JavaVMOption* options = stackalloc JavaVMOption[2];
    options[0].optionString = new PSTR(Marshal.StringToHGlobalAnsi("-Djava.class.path=.:C:/Users/qq251/Downloads/GitHub/new/CPPTest/CPPTest/test.jar"));
    options[1].optionString = new PSTR(Marshal.StringToHGlobalAnsi("-Xlog:verification=info"));
    JavaVMInitArgs vm_args;
    vm_args = new JavaVMInitArgs()
    {
        version = JNI_VERSION.JNI_VERSION_21,
        nOptions = 2,
        options = options,
        ignoreUnrecognized = 1
    };
    //using var a = PInvoke.LoadLibrary("C:/Program Files/Microsoft/jdk-21.0.8.9-hotspot/bin/server/jvm.dll");
    //var b = PInvoke.GetProcAddress(a, "JNI_CreateJavaVM");
    //var c = (delegate* unmanaged<JavaVM**, JNIEnv**, JavaVMInitArgs*, JNI_ERROR>)b.Value;
    //var d = c(&jvm, &env, &vm_args);
    var d = PInvoke.JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
    Console.WriteLine(d);
    //JNI.Initialize(new JavaVMInitArgs(
    //    JNI.Version.V1_8,
    //    [
    //        new JavaVMOption("-Djava.class.path=.:C:/Users/qq251/Downloads/GitHub/new/CPPTest/CPPTest/test.jar")
    //    ],
    //    true));
}