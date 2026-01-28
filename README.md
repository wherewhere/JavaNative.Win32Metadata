# JavaNative.Win32Metadata
This project contains code to build and publish the [JavaNative.Win32Metadata](https://www.nuget.org/packages/JavaNative.Win32Metadata) nuget package. The package wraps the [Java Native Interface library](https://docs.oracle.com/javase/8/docs/technotes/guides/jni) into a winmd (Windows metadata) file. If you combine it with [Microsoft.Windows.CsWin32](https://www.nuget.org/packages/Microsoft.Windows.CsWin32), it will allow you to generate signatures (PInvokes) to easily use .NET Host functions in your executable/library.

[![Issues](https://img.shields.io/github/issues/wherewhere/JavaNative.Win32Metadata.svg?label=Issues&style=flat-square)](https://github.com/wherewhere/JavaNative.Win32Metadata/issues "Issues")
[![Stargazers](https://img.shields.io/github/stars/wherewhere/JavaNative.Win32Metadata.svg?label=Stars&style=flat-square)](https://github.com/wherewhere/JavaNative.Win32Metadata/stargazers "Stargazers")
[![NuGet](https://img.shields.io/nuget/dt/JavaNative.Win32Metadata.svg?logo=NuGet&style=flat-square)](https://www.nuget.org/packages/JavaNative.Win32Metadata "NuGet")

## How to use it
1. Install the required Nuget packages:
   - [Microsoft.Windows.CsWin32](https://www.nuget.org/packages/Microsoft.Windows.CsWin32)
   - [JavaNative.Win32Metadata](https://www.nuget.org/packages/JavaNative.Win32Metadata)
2. Create a `NativeMethods.txt` file in the root folder of your project and list native functions and structures (including the one from JNI) you plan to use, for example:

   ```txt
   // Windows
   LoadLibrary

   // Java Native Interface
   JNI_TRUE

   JNI_CreateJavaVM
   JNI_GetDefaultJavaVMInitArgs
   ```

   Please also check the [CSWin32 project README file](https://github.com/microsoft/CsWin32/blob/main/README.md) for other configuration options of the PInvoke generators.
3. You are ready to use the native functions in your code :)
   ```cs
   using FreeLibrarySafeHandle __ = PInvoke.LoadLibrary($"{Environment.GetEnvironmentVariable("JAVA_HOME")}/bin/server/jvm.dll");
   JavaVMInitArgs vm_args = new()
   {
       version = JNI_VERSION.JNI_VERSION_24
   };
   _ = Java.PInvoke.JNI_GetDefaultJavaVMInitArgs(ref vm_args);
   JNI_ERROR result = Java.PInvoke.JNI_CreateJavaVM(out JavaVM* jvm, out JNIEnv* env, vm_args);
   ```

## Contributors
[![Contributors](https://contrib.rocks/image?repo=wherewhere/JavaNative.Win32Metadata)](https://github.com/wherewhere/JavaNative.Win32Metadata/graphs/contributors "Contributors")