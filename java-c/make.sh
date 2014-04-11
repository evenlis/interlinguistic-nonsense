#!/bin/bash
if [ "$#" -eq 1 ]; then
    CALLER_NAME=$1
    javac -d ./lib -sourcepath ./src ./src/$1.java
elif [ "$#" -eq 2 ]; then
	CALLER_NAME=$2
	javac -d ./lib -sourcepath ./src ./src/$1.java ./src/$2.java
else
    printf "Usage:\n'./make.sh <Library class name> <Caller class name' or\n'./make.sh <Library & caller class name>'"
    exit
fi


javah -jni -d ./headers -classpath ./lib $1
gcc --std=c99 -fPIC -o ./lib/$1.o -c ./src/$1.c -I /usr/lib/jvm/java-7-oracle/include -I /usr/lib/jvm/java-7-oracle/include/linux -I ./headers
gcc --std=c99 ./lib/$1.o -shared -o ./lib/lib$1.so -Wl,-soname,$1
cd lib
export LD_LIBRARY_PATH=.
java $CALLER_NAME
