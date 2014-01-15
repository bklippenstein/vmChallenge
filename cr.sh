#!/bin/bash

rm *~

gcc -Wall -v challenge.c memory.c -o challenge

printf "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"

./challenge challenge.bin

