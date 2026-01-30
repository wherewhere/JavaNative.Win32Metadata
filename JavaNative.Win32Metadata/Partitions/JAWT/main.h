#include "jawt.h"

// JAWT_DrawingSurface

typedef jint(JNICALL* LockDrawingSurface)(struct jawt_DrawingSurface* ds);
typedef JAWT_DrawingSurfaceInfo* (JNICALL* GetDrawingSurfaceInfo)(struct jawt_DrawingSurface* ds);
typedef void (JNICALL* FreeDrawingSurfaceInfo)(JAWT_DrawingSurfaceInfo* dsi);
typedef void (JNICALL* UnlockDrawingSurface)(struct jawt_DrawingSurface* ds);

// JAWT

typedef JAWT_DrawingSurface* (JNICALL* GetDrawingSurface)(JNIEnv* env, jobject target);
typedef void (JNICALL* FreeDrawingSurface)(JAWT_DrawingSurface* ds);
typedef void (JNICALL* LockJNIEnv)(JNIEnv* env);
typedef void (JNICALL* UnlockJNIEnv)(JNIEnv* env);
typedef jobject(JNICALL* GetComponent)(JNIEnv* env, void* platformInfo);
typedef jobject(JNICALL* CreateEmbeddedFrame) (JNIEnv* env, void* platformInfo);
typedef void (JNICALL* SetBounds) (JNIEnv* env, jobject embeddedFrame, jint x, jint y, jint w, jint h);
typedef void (JNICALL* SynthesizeWindowActivation) (JNIEnv* env, jobject embeddedFrame, jboolean doActivate);