#include "HelloJni.h"  
  
JNIEXPORT void JNICALL Java_HelloJni_hello  
  (JNIEnv *env, jobject obj)  
{  
    printf("******** Hello Jni at c++\n");  
    return;  
} 
