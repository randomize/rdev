#!/usr/bin/env bash

. ~/bin/include/colors

echo_red " === Compiling =================" 

nasm -f elf64 tiny.asm
gcc -Wall -s tiny.o

echo_red " === Dumping ==================="

objdump -Sr tiny.o

echo_red  " === Running ==================="

./a.out ; echo $?

echo_red " === Result size ==============="

wc -c ./a.out
