#!/usr/bin/env bash

# set -e

. ~/bin/include/colors

echo_red " === Clearing ==================" 
rm -rf ./a.out ./tiny.o


echo_red " === Compiling =================" 

nasm -f elf64 tiny.asm
gcc -Wall -s -nostartfiles -nostdlib tiny.o

echo_red " === Dumping ==================="

objdump -Sr tiny.o

echo_red  " === Running ==================="

./a.out ; echo $? 

echo_red " === Result size ==============="

wc -c ./a.out
