#include "jni.h"

//JNINativeInterface

typedef jint(JNICALL* GetVersion)(JNIEnv* env);

typedef jclass(JNICALL* DefineClass)(JNIEnv* env, const char* name, jobject loader, const jbyte* buf, jsize len);
typedef jclass(JNICALL* FindClass)(JNIEnv* env, const char* name);

typedef jmethodID(JNICALL* FromReflectedMethod)(JNIEnv* env, jobject method);
typedef jfieldID(JNICALL* FromReflectedField)(JNIEnv* env, jobject field);

typedef jobject(JNICALL* ToReflectedMethod)(JNIEnv* env, jclass cls, jmethodID methodID, jboolean isStatic);

typedef jclass(JNICALL* GetSuperclass)(JNIEnv* env, jclass sub);
typedef jboolean(JNICALL* IsAssignableFrom)(JNIEnv* env, jclass sub, jclass sup);

typedef jobject(JNICALL* ToReflectedField)(JNIEnv* env, jclass cls, jfieldID fieldID, jboolean isStatic);

typedef jint(JNICALL* Throw)(JNIEnv* env, jthrowable obj);
typedef jint(JNICALL* ThrowNew)(JNIEnv* env, jclass clazz, const char* msg);
typedef jthrowable(JNICALL* ExceptionOccurred)(JNIEnv* env);
typedef void (JNICALL* ExceptionDescribe)(JNIEnv* env);
typedef void (JNICALL* ExceptionClear)(JNIEnv* env);
typedef void (JNICALL* FatalError)(JNIEnv* env, const char* msg);

typedef jint(JNICALL* PushLocalFrame)(JNIEnv* env, jint capacity);
typedef jobject(JNICALL* PopLocalFrame)(JNIEnv* env, jobject result);

typedef jobject(JNICALL* NewGlobalRef)(JNIEnv* env, jobject lobj);
typedef void (JNICALL* DeleteGlobalRef)(JNIEnv* env, jobject gref);
typedef void (JNICALL* DeleteLocalRef)(JNIEnv* env, jobject obj);
typedef jboolean(JNICALL* IsSameObject)(JNIEnv* env, jobject obj1, jobject obj2);
typedef jobject(JNICALL* NewLocalRef)(JNIEnv* env, jobject ref);
typedef jint(JNICALL* EnsureLocalCapacity)(JNIEnv* env, jint capacity);

typedef jobject(JNICALL* AllocObject)(JNIEnv* env, jclass clazz);
typedef jobject(JNICALL* NewObject)(JNIEnv* env, jclass clazz, jmethodID methodID, ...);
typedef jobject(JNICALL* NewObjectV)(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args);
typedef jobject(JNICALL* NewObjectA)(JNIEnv* env, jclass clazz, jmethodID methodID, const jvalue* args);

typedef jclass(JNICALL* GetObjectClass)(JNIEnv* env, jobject obj);
typedef jboolean(JNICALL* IsInstanceOf)(JNIEnv* env, jobject obj, jclass clazz);

typedef jmethodID(JNICALL* GetMethodID)(JNIEnv* env, jclass clazz, const char* name, const char* sig);

typedef jobject(JNICALL* CallObjectMethod)(JNIEnv* env, jobject obj, jmethodID methodID, ...);
typedef jobject(JNICALL* CallObjectMethodV)(JNIEnv* env, jobject obj, jmethodID methodID, va_list args);
typedef jobject(JNICALL* CallObjectMethodA)(JNIEnv* env, jobject obj, jmethodID methodID, const jvalue* args);

typedef jboolean(JNICALL* CallBooleanMethod)(JNIEnv* env, jobject obj, jmethodID methodID, ...);
typedef jboolean(JNICALL* CallBooleanMethodV)(JNIEnv* env, jobject obj, jmethodID methodID, va_list args);
typedef jboolean(JNICALL* CallBooleanMethodA)(JNIEnv* env, jobject obj, jmethodID methodID, const jvalue* args);

typedef jbyte(JNICALL* CallByteMethod)(JNIEnv* env, jobject obj, jmethodID methodID, ...);
typedef jbyte(JNICALL* CallByteMethodV)(JNIEnv* env, jobject obj, jmethodID methodID, va_list args);
typedef jbyte(JNICALL* CallByteMethodA)(JNIEnv* env, jobject obj, jmethodID methodID, const jvalue* args);

typedef jchar(JNICALL* CallCharMethod)(JNIEnv* env, jobject obj, jmethodID methodID, ...);
typedef jchar(JNICALL* CallCharMethodV)(JNIEnv* env, jobject obj, jmethodID methodID, va_list args);
typedef jchar(JNICALL* CallCharMethodA)(JNIEnv* env, jobject obj, jmethodID methodID, const jvalue* args);

typedef jshort(JNICALL* CallShortMethod)(JNIEnv* env, jobject obj, jmethodID methodID, ...);
typedef jshort(JNICALL* CallShortMethodV)(JNIEnv* env, jobject obj, jmethodID methodID, va_list args);
typedef jshort(JNICALL* CallShortMethodA)(JNIEnv* env, jobject obj, jmethodID methodID, const jvalue* args);

typedef jint(JNICALL* CallIntMethod)(JNIEnv* env, jobject obj, jmethodID methodID, ...);
typedef jint(JNICALL* CallIntMethodV)(JNIEnv* env, jobject obj, jmethodID methodID, va_list args);
typedef jint(JNICALL* CallIntMethodA)(JNIEnv* env, jobject obj, jmethodID methodID, const jvalue* args);

typedef jlong(JNICALL* CallLongMethod)(JNIEnv* env, jobject obj, jmethodID methodID, ...);
typedef jlong(JNICALL* CallLongMethodV)(JNIEnv* env, jobject obj, jmethodID methodID, va_list args);
typedef jlong(JNICALL* CallLongMethodA)(JNIEnv* env, jobject obj, jmethodID methodID, const jvalue* args);

typedef jfloat(JNICALL* CallFloatMethod)(JNIEnv* env, jobject obj, jmethodID methodID, ...);
typedef jfloat(JNICALL* CallFloatMethodV)(JNIEnv* env, jobject obj, jmethodID methodID, va_list args);
typedef jfloat(JNICALL* CallFloatMethodA)(JNIEnv* env, jobject obj, jmethodID methodID, const jvalue* args);

typedef jdouble(JNICALL* CallDoubleMethod)(JNIEnv* env, jobject obj, jmethodID methodID, ...);
typedef jdouble(JNICALL* CallDoubleMethodV)(JNIEnv* env, jobject obj, jmethodID methodID, va_list args);
typedef jdouble(JNICALL* CallDoubleMethodA)(JNIEnv* env, jobject obj, jmethodID methodID, const jvalue* args);

typedef void (JNICALL* CallVoidMethod)(JNIEnv* env, jobject obj, jmethodID methodID, ...);
typedef void (JNICALL* CallVoidMethodV)(JNIEnv* env, jobject obj, jmethodID methodID, va_list args);
typedef void (JNICALL* CallVoidMethodA)(JNIEnv* env, jobject obj, jmethodID methodID, const jvalue* args);

typedef jobject(JNICALL* CallNonvirtualObjectMethod)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...);
typedef jobject(JNICALL* CallNonvirtualObjectMethodV)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args);
typedef jobject(JNICALL* CallNonvirtualObjectMethodA)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, const jvalue* args);

typedef jboolean(JNICALL* CallNonvirtualBooleanMethod)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...);
typedef jboolean(JNICALL* CallNonvirtualBooleanMethodV)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args);
typedef jboolean(JNICALL* CallNonvirtualBooleanMethodA)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, const jvalue* args);

typedef jbyte(JNICALL* CallNonvirtualByteMethod)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...);
typedef jbyte(JNICALL* CallNonvirtualByteMethodV)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args);
typedef jbyte(JNICALL* CallNonvirtualByteMethodA)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, const jvalue* args);

typedef jchar(JNICALL* CallNonvirtualCharMethod)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...);
typedef jchar(JNICALL* CallNonvirtualCharMethodV)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args);
typedef jchar(JNICALL* CallNonvirtualCharMethodA)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, const jvalue* args);

typedef jshort(JNICALL* CallNonvirtualShortMethod)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...);
typedef jshort(JNICALL* CallNonvirtualShortMethodV)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args);
typedef jshort(JNICALL* CallNonvirtualShortMethodA)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, const jvalue* args);

typedef jint(JNICALL* CallNonvirtualIntMethod)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...);
typedef jint(JNICALL* CallNonvirtualIntMethodV)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args);
typedef jint(JNICALL* CallNonvirtualIntMethodA)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, const jvalue* args);

typedef jlong(JNICALL* CallNonvirtualLongMethod)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...);
typedef jlong(JNICALL* CallNonvirtualLongMethodV)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args);
typedef jlong(JNICALL* CallNonvirtualLongMethodA)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, const jvalue* args);

typedef jfloat(JNICALL* CallNonvirtualFloatMethod)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...);
typedef jfloat(JNICALL* CallNonvirtualFloatMethodV)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args);
typedef jfloat(JNICALL* CallNonvirtualFloatMethodA)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, const jvalue* args);

typedef jdouble(JNICALL* CallNonvirtualDoubleMethod)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...);
typedef jdouble(JNICALL* CallNonvirtualDoubleMethodV)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args);
typedef jdouble(JNICALL* CallNonvirtualDoubleMethodA)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, const jvalue* args);

typedef void (JNICALL* CallNonvirtualVoidMethod)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, ...);
typedef void (JNICALL* CallNonvirtualVoidMethodV)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, va_list args);
typedef void (JNICALL* CallNonvirtualVoidMethodA)(JNIEnv* env, jobject obj, jclass clazz, jmethodID methodID, const jvalue* args);

typedef jfieldID(JNICALL* GetFieldID)(JNIEnv* env, jclass clazz, const char* name, const char* sig);

typedef jobject(JNICALL* GetObjectField)(JNIEnv* env, jobject obj, jfieldID fieldID);
typedef jboolean(JNICALL* GetBooleanField)(JNIEnv* env, jobject obj, jfieldID fieldID);
typedef jbyte(JNICALL* GetByteField)(JNIEnv* env, jobject obj, jfieldID fieldID);
typedef jchar(JNICALL* GetCharField)(JNIEnv* env, jobject obj, jfieldID fieldID);
typedef jshort(JNICALL* GetShortField)(JNIEnv* env, jobject obj, jfieldID fieldID);
typedef jint(JNICALL* GetIntField)(JNIEnv* env, jobject obj, jfieldID fieldID);
typedef jlong(JNICALL* GetLongField)(JNIEnv* env, jobject obj, jfieldID fieldID);
typedef jfloat(JNICALL* GetFloatField)(JNIEnv* env, jobject obj, jfieldID fieldID);
typedef jdouble(JNICALL* GetDoubleField)(JNIEnv* env, jobject obj, jfieldID fieldID);

typedef void (JNICALL* SetObjectField)(JNIEnv* env, jobject obj, jfieldID fieldID, jobject val);
typedef void (JNICALL* SetBooleanField)(JNIEnv* env, jobject obj, jfieldID fieldID, jboolean val);
typedef void (JNICALL* SetByteField)(JNIEnv* env, jobject obj, jfieldID fieldID, jbyte val);
typedef void (JNICALL* SetCharField)(JNIEnv* env, jobject obj, jfieldID fieldID, jchar val);
typedef void (JNICALL* SetShortField)(JNIEnv* env, jobject obj, jfieldID fieldID, jshort val);
typedef void (JNICALL* SetIntField)(JNIEnv* env, jobject obj, jfieldID fieldID, jint val);
typedef void (JNICALL* SetLongField)(JNIEnv* env, jobject obj, jfieldID fieldID, jlong val);
typedef void (JNICALL* SetFloatField)(JNIEnv* env, jobject obj, jfieldID fieldID, jfloat val);
typedef void (JNICALL* SetDoubleField)(JNIEnv* env, jobject obj, jfieldID fieldID, jdouble val);

typedef jmethodID(JNICALL* GetStaticMethodID)(JNIEnv* env, jclass clazz, const char* name, const char* sig);

typedef jobject(JNICALL* CallStaticObjectMethod)(JNIEnv* env, jclass clazz, jmethodID methodID, ...);
typedef jobject(JNICALL* CallStaticObjectMethodV)(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args);
typedef jobject(JNICALL* CallStaticObjectMethodA)(JNIEnv* env, jclass clazz, jmethodID methodID, const jvalue* args);

typedef jboolean(JNICALL* CallStaticBooleanMethod)(JNIEnv* env, jclass clazz, jmethodID methodID, ...);
typedef jboolean(JNICALL* CallStaticBooleanMethodV)(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args);
typedef jboolean(JNICALL* CallStaticBooleanMethodA)(JNIEnv* env, jclass clazz, jmethodID methodID, const jvalue* args);

typedef jbyte(JNICALL* CallStaticByteMethod)(JNIEnv* env, jclass clazz, jmethodID methodID, ...);
typedef jbyte(JNICALL* CallStaticByteMethodV)(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args);
typedef jbyte(JNICALL* CallStaticByteMethodA)(JNIEnv* env, jclass clazz, jmethodID methodID, const jvalue* args);

typedef jchar(JNICALL* CallStaticCharMethod)(JNIEnv* env, jclass clazz, jmethodID methodID, ...);
typedef jchar(JNICALL* CallStaticCharMethodV)(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args);
typedef jchar(JNICALL* CallStaticCharMethodA)(JNIEnv* env, jclass clazz, jmethodID methodID, const jvalue* args);

typedef jshort(JNICALL* CallStaticShortMethod)(JNIEnv* env, jclass clazz, jmethodID methodID, ...);
typedef jshort(JNICALL* CallStaticShortMethodV)(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args);
typedef jshort(JNICALL* CallStaticShortMethodA)(JNIEnv* env, jclass clazz, jmethodID methodID, const jvalue* args);

typedef jint(JNICALL* CallStaticIntMethod)(JNIEnv* env, jclass clazz, jmethodID methodID, ...);
typedef jint(JNICALL* CallStaticIntMethodV)(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args);
typedef jint(JNICALL* CallStaticIntMethodA)(JNIEnv* env, jclass clazz, jmethodID methodID, const jvalue* args);

typedef jlong(JNICALL* CallStaticLongMethod)(JNIEnv* env, jclass clazz, jmethodID methodID, ...);
typedef jlong(JNICALL* CallStaticLongMethodV)(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args);
typedef jlong(JNICALL* CallStaticLongMethodA)(JNIEnv* env, jclass clazz, jmethodID methodID, const jvalue* args);

typedef jfloat(JNICALL* CallStaticFloatMethod)(JNIEnv* env, jclass clazz, jmethodID methodID, ...);
typedef jfloat(JNICALL* CallStaticFloatMethodV)(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args);
typedef jfloat(JNICALL* CallStaticFloatMethodA)(JNIEnv* env, jclass clazz, jmethodID methodID, const jvalue* args);

typedef jdouble(JNICALL* CallStaticDoubleMethod)(JNIEnv* env, jclass clazz, jmethodID methodID, ...);
typedef jdouble(JNICALL* CallStaticDoubleMethodV)(JNIEnv* env, jclass clazz, jmethodID methodID, va_list args);
typedef jdouble(JNICALL* CallStaticDoubleMethodA)(JNIEnv* env, jclass clazz, jmethodID methodID, const jvalue* args);

typedef void (JNICALL* CallStaticVoidMethod)(JNIEnv* env, jclass cls, jmethodID methodID, ...);
typedef void (JNICALL* CallStaticVoidMethodV)(JNIEnv* env, jclass cls, jmethodID methodID, va_list args);
typedef void (JNICALL* CallStaticVoidMethodA)(JNIEnv* env, jclass cls, jmethodID methodID, const jvalue* args);

typedef jfieldID(JNICALL* GetStaticFieldID)(JNIEnv* env, jclass clazz, const char* name, const char* sig);

typedef jobject(JNICALL* GetStaticObjectField)(JNIEnv* env, jclass clazz, jfieldID fieldID);
typedef jboolean(JNICALL* GetStaticBooleanField)(JNIEnv* env, jclass clazz, jfieldID fieldID);
typedef jbyte(JNICALL* GetStaticByteField)(JNIEnv* env, jclass clazz, jfieldID fieldID);
typedef jchar(JNICALL* GetStaticCharField)(JNIEnv* env, jclass clazz, jfieldID fieldID);
typedef jshort(JNICALL* GetStaticShortField)(JNIEnv* env, jclass clazz, jfieldID fieldID);
typedef jint(JNICALL* GetStaticIntField)(JNIEnv* env, jclass clazz, jfieldID fieldID);
typedef jlong(JNICALL* GetStaticLongField)(JNIEnv* env, jclass clazz, jfieldID fieldID);
typedef jfloat(JNICALL* GetStaticFloatField)(JNIEnv* env, jclass clazz, jfieldID fieldID);
typedef jdouble(JNICALL* GetStaticDoubleField)(JNIEnv* env, jclass clazz, jfieldID fieldID);

typedef void (JNICALL* SetStaticObjectField)(JNIEnv* env, jclass clazz, jfieldID fieldID, jobject value);
typedef void (JNICALL* SetStaticBooleanField)(JNIEnv* env, jclass clazz, jfieldID fieldID, jboolean value);
typedef void (JNICALL* SetStaticByteField)(JNIEnv* env, jclass clazz, jfieldID fieldID, jbyte value);
typedef void (JNICALL* SetStaticCharField)(JNIEnv* env, jclass clazz, jfieldID fieldID, jchar value);
typedef void (JNICALL* SetStaticShortField)(JNIEnv* env, jclass clazz, jfieldID fieldID, jshort value);
typedef void (JNICALL* SetStaticIntField)(JNIEnv* env, jclass clazz, jfieldID fieldID, jint value);
typedef void (JNICALL* SetStaticLongField)(JNIEnv* env, jclass clazz, jfieldID fieldID, jlong value);
typedef void (JNICALL* SetStaticFloatField)(JNIEnv* env, jclass clazz, jfieldID fieldID, jfloat value);
typedef void (JNICALL* SetStaticDoubleField)(JNIEnv* env, jclass clazz, jfieldID fieldID, jdouble value);

typedef jstring(JNICALL* NewString)(JNIEnv* env, const jchar* unicode, jsize len);
typedef jsize(JNICALL* GetStringLength)(JNIEnv* env, jstring str);
typedef const jchar* (JNICALL* GetStringChars)(JNIEnv* env, jstring str, jboolean* isCopy);
typedef void (JNICALL* ReleaseStringChars)(JNIEnv* env, jstring str, const jchar* chars);

typedef jstring(JNICALL* NewStringUTF)(JNIEnv* env, const char* utf);
typedef jsize(JNICALL* GetStringUTFLength)(JNIEnv* env, jstring str);
typedef const char* (JNICALL* GetStringUTFChars)(JNIEnv* env, jstring str, jboolean* isCopy);
typedef void (JNICALL* ReleaseStringUTFChars)(JNIEnv* env, jstring str, const char* chars);

typedef jsize(JNICALL* GetArrayLength)(JNIEnv* env, jarray array);

typedef jobjectArray(JNICALL* NewObjectArray)(JNIEnv* env, jsize len, jclass clazz, jobject init);
typedef jobject(JNICALL* GetObjectArrayElement)(JNIEnv* env, jobjectArray array, jsize index);
typedef void (JNICALL* SetObjectArrayElement)(JNIEnv* env, jobjectArray array, jsize index, jobject val);

typedef jbooleanArray(JNICALL* NewBooleanArray)(JNIEnv* env, jsize len);
typedef jbyteArray(JNICALL* NewByteArray)(JNIEnv* env, jsize len);
typedef jcharArray(JNICALL* NewCharArray)(JNIEnv* env, jsize len);
typedef jshortArray(JNICALL* NewShortArray)(JNIEnv* env, jsize len);
typedef jintArray(JNICALL* NewIntArray)(JNIEnv* env, jsize len);
typedef jlongArray(JNICALL* NewLongArray)(JNIEnv* env, jsize len);
typedef jfloatArray(JNICALL* NewFloatArray)(JNIEnv* env, jsize len);
typedef jdoubleArray(JNICALL* NewDoubleArray)(JNIEnv* env, jsize len);

typedef jboolean* (JNICALL* GetBooleanArrayElements)(JNIEnv* env, jbooleanArray array, jboolean* isCopy);
typedef jbyte* (JNICALL* GetByteArrayElements)(JNIEnv* env, jbyteArray array, jboolean* isCopy);
typedef jchar* (JNICALL* GetCharArrayElements)(JNIEnv* env, jcharArray array, jboolean* isCopy);
typedef jshort* (JNICALL* GetShortArrayElements)(JNIEnv* env, jshortArray array, jboolean* isCopy);
typedef jint* (JNICALL* GetIntArrayElements)(JNIEnv* env, jintArray array, jboolean* isCopy);
typedef jlong* (JNICALL* GetLongArrayElements)(JNIEnv* env, jlongArray array, jboolean* isCopy);
typedef jfloat* (JNICALL* GetFloatArrayElements)(JNIEnv* env, jfloatArray array, jboolean* isCopy);
typedef jdouble* (JNICALL* GetDoubleArrayElements)(JNIEnv* env, jdoubleArray array, jboolean* isCopy);

typedef void (JNICALL* ReleaseBooleanArrayElements)(JNIEnv* env, jbooleanArray array, jboolean* elems, jint mode);
typedef void (JNICALL* ReleaseByteArrayElements)(JNIEnv* env, jbyteArray array, jbyte* elems, jint mode);
typedef void (JNICALL* ReleaseCharArrayElements)(JNIEnv* env, jcharArray array, jchar* elems, jint mode);
typedef void (JNICALL* ReleaseShortArrayElements)(JNIEnv* env, jshortArray array, jshort* elems, jint mode);
typedef void (JNICALL* ReleaseIntArrayElements)(JNIEnv* env, jintArray array, jint* elems, jint mode);
typedef void (JNICALL* ReleaseLongArrayElements)(JNIEnv* env, jlongArray array, jlong* elems, jint mode);
typedef void (JNICALL* ReleaseFloatArrayElements)(JNIEnv* env, jfloatArray array, jfloat* elems, jint mode);
typedef void (JNICALL* ReleaseDoubleArrayElements)(JNIEnv* env, jdoubleArray array, jdouble* elems, jint mode);

typedef void (JNICALL* GetBooleanArrayRegion)(JNIEnv* env, jbooleanArray array, jsize start, jsize l, jboolean* buf);
typedef void (JNICALL* GetByteArrayRegion)(JNIEnv* env, jbyteArray array, jsize start, jsize len, jbyte* buf);
typedef void (JNICALL* GetCharArrayRegion)(JNIEnv* env, jcharArray array, jsize start, jsize len, jchar* buf);
typedef void (JNICALL* GetShortArrayRegion)(JNIEnv* env, jshortArray array, jsize start, jsize len, jshort* buf);
typedef void (JNICALL* GetIntArrayRegion)(JNIEnv* env, jintArray array, jsize start, jsize len, jint* buf);
typedef void (JNICALL* GetLongArrayRegion)(JNIEnv* env, jlongArray array, jsize start, jsize len, jlong* buf);
typedef void (JNICALL* GetFloatArrayRegion)(JNIEnv* env, jfloatArray array, jsize start, jsize len, jfloat* buf);
typedef void (JNICALL* GetDoubleArrayRegion)(JNIEnv* env, jdoubleArray array, jsize start, jsize len, jdouble* buf);

typedef void (JNICALL* SetBooleanArrayRegion)(JNIEnv* env, jbooleanArray array, jsize start, jsize l, const jboolean* buf);
typedef void (JNICALL* SetByteArrayRegion)(JNIEnv* env, jbyteArray array, jsize start, jsize len, const jbyte* buf);
typedef void (JNICALL* SetCharArrayRegion)(JNIEnv* env, jcharArray array, jsize start, jsize len, const jchar* buf);
typedef void (JNICALL* SetShortArrayRegion)(JNIEnv* env, jshortArray array, jsize start, jsize len, const jshort* buf);
typedef void (JNICALL* SetIntArrayRegion)(JNIEnv* env, jintArray array, jsize start, jsize len, const jint* buf);
typedef void (JNICALL* SetLongArrayRegion)(JNIEnv* env, jlongArray array, jsize start, jsize len, const jlong* buf);
typedef void (JNICALL* SetFloatArrayRegion)(JNIEnv* env, jfloatArray array, jsize start, jsize len, const jfloat* buf);
typedef void (JNICALL* SetDoubleArrayRegion)(JNIEnv* env, jdoubleArray array, jsize start, jsize len, const jdouble* buf);

typedef jint(JNICALL* RegisterNatives)(JNIEnv* env, jclass clazz, const JNINativeMethod* methods, jint nMethods);
typedef jint(JNICALL* UnregisterNatives)(JNIEnv* env, jclass clazz);

typedef jint(JNICALL* MonitorEnter)(JNIEnv* env, jobject obj);
typedef jint(JNICALL* MonitorExit)(JNIEnv* env, jobject obj);

typedef jint(JNICALL* GetJavaVM)(JNIEnv* env, JavaVM** vm);

typedef void (JNICALL* GetStringRegion)(JNIEnv* env, jstring str, jsize start, jsize len, jchar* buf);
typedef void (JNICALL* GetStringUTFRegion)(JNIEnv* env, jstring str, jsize start, jsize len, char* buf);

typedef void* (JNICALL* GetPrimitiveArrayCritical)(JNIEnv* env, jarray array, jboolean* isCopy);
typedef void (JNICALL* ReleasePrimitiveArrayCritical)(JNIEnv* env, jarray array, void* carray, jint mode);

typedef const jchar* (JNICALL* GetStringCritical)(JNIEnv* env, jstring string, jboolean* isCopy);
typedef void (JNICALL* ReleaseStringCritical)(JNIEnv* env, jstring string, const jchar* cstring);

typedef jweak(JNICALL* NewWeakGlobalRef)(JNIEnv* env, jobject obj);
typedef void (JNICALL* DeleteWeakGlobalRef)(JNIEnv* env, jweak ref);

typedef jboolean(JNICALL* ExceptionCheck)(JNIEnv* env);

typedef jobject(JNICALL* NewDirectByteBuffer)(JNIEnv* env, void* address, jlong capacity);
typedef void* (JNICALL* GetDirectBufferAddress)(JNIEnv* env, jobject buf);
typedef jlong(JNICALL* GetDirectBufferCapacity)(JNIEnv* env, jobject buf);

/* New JNI 1.6 Features */

typedef jobjectRefType(JNICALL* GetObjectRefType)(JNIEnv* env, jobject obj);

/* Module Features */

typedef jobject(JNICALL* GetModule)(JNIEnv* env, jclass clazz);

/* Virtual threads */

typedef jboolean(JNICALL* IsVirtualThread)(JNIEnv* env, jobject obj);

// JNIInvokeInterface

typedef jint(JNICALL* InputJavaVM)(JavaVM* vm);
typedef jint(JNICALL* InputJavaVMWithArgs)(JavaVM* vm, JNIEnv* penv, JavaVMAttachArgs* args);
typedef jint(JNICALL* InputJavaVMWithVersion)(JavaVM* vm, JNIEnv* penv, jint version);