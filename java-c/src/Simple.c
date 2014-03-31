#include <stdio.h>
#include "Simple.h"

JNIEXPORT void JNICALL
Java_Simple_print(JNIEnv* env, jobject obj){
  printf("Well this was easy\n");
  return;
}
