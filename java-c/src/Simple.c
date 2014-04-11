#include <stdio.h>
#include "Simple.h"

JNIEXPORT void JNICALL Java_Simple_print(JNIEnv* env, jobject obj){
  printf("C void function invoked by java code\n");
  return;
}

JNIEXPORT void JNICALL Java_Simple_print_1arg(JNIEnv* env, jobject obj, jint a){
  printf("Integer passed from java code: %d\n", a);
  return;
}

JNIEXPORT jint JNICALL Java_Simple_sum_1array(JNIEnv* env, jobject obj, jintArray array){
  jsize len = (*env)->GetArrayLength(env, array);
  jint* body = (*env)->GetIntArrayElements(env, array, 0);
  int sum = 0;
  for(int i=0; i<len; ++i){
    sum += body[i];
  }
  return sum;
}
