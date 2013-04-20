#!/bin/bash

rm *~

gcc -Wall challenge.c -o challenge

printf "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"

#./challenge challenge.bin

./challenge "test"

