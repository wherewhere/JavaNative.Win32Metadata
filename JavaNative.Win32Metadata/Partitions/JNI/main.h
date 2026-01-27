#include "jni.h"

// JNIInvokeInterface

typedef jint(JNICALL* InputJavaVM)(JavaVM* vm);
typedef jint(JNICALL* InputJavaVMWithArgs)(JavaVM* vm, JNIEnv* penv, JavaVMAttachArgs* args);
typedef jint(JNICALL* InputJavaVMWithVersion)(JavaVM* vm, JNIEnv* penv, jint version);