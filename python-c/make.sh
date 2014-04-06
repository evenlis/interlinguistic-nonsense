#!/bin/bash
if [ "$#" -ne 2 ]; then
    printf "Usage: ./make.sh <Caller file name> <Module name>"
    exit
fi
gcc -shared -fPIC -I/usr/include/python2.7 -o $2.so $2.c
python $1.py
