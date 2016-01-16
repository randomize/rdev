; tiny.asm
; vim: ft=nasm
BITS 64

GLOBAL _start

SECTION .text

_start:
; print
;   xor rax, rax
;   inc rax
;   xor rdi, rdi
;   inc rdi
;   mov rsi, msg
;   mov rdx, len
;   syscall


; exit ( rax = 60, rdi = 42, means exit(42) syscall )
; 12 bytes so far is record here - can we do better?
    
    mov rdi, 42
    xor rax, rax
    add al, 60
    syscall

; msg     db  'Hello, world!',0xa                 ;our dear string
; len     equ $ - msg                             ;length of our dear string

