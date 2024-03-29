#include <jni.h>
#include <string>

std::string ab = "";

std::string jstring2str(JNIEnv* env, jstring jstr)
{
    char*   rtn   =   NULL;
    jclass   clsstring   =   env->FindClass("java/lang/String");
    jstring   strencode   =   env->NewStringUTF("GB2312");
    jmethodID   mid   =   env->GetMethodID(clsstring,   "getBytes",   "(Ljava/lang/String;)[B");
    jbyteArray   barr=   (jbyteArray)env->CallObjectMethod(jstr,mid,strencode);
    jsize   alen   =   env->GetArrayLength(barr);
    jbyte*   ba   =   env->GetByteArrayElements(barr,JNI_FALSE);
    if(alen   >   0)
    {
        rtn   =   (char*)malloc(alen+1);
        memcpy(rtn,ba,alen);
        rtn[alen]=0;
    }
    env->ReleaseByteArrayElements(barr,ba,0);
    std::string stemp(rtn);
    free(rtn);
    return   stemp;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_testndk_Utils_write(JNIEnv *env, jclass type, jstring password_) {
    const char *password = env->GetStringUTFChars(password_, 0);

    ab = jstring2str(env,password_);
    // TODO
    env->ReleaseStringUTFChars(password_, password);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_testndk_Utils_read(JNIEnv *env, jclass type) {

    std::string hello = ab;
    return env->NewStringUTF(hello.c_str());
}