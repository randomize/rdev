; tiny.asm
; vim: ft=nasm
BITS 64

EXTERN _exit
GLOBAL _start

SECTION .text

_start:
    xor rdi, rdi
    inc rdi
    call _exit
