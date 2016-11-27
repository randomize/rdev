 
section .text                   ;section declaration

                                ;we must export the entry point to the ELF linker or
    global  _start              ;loader. They conventionally recognize _start as their
			                          ;entry point. Use ld -e foo to override the default.

_start:
                                ;write our string to stdout

    mov     rax,1               ; syscall # - write
    mov     rdi,rax             ; write to stdout
    mov     rsi,msg             ; message
    mov     rdx,len             ; len
    syscall

                                ;and exit

    mov     rax,60              ; syscall # - exit
    xor     rdi,rdi
    syscall

section .data                   ;section declaration

msg db      "Hello, world",0xa  ;our dear string
len equ     $ - msg             ;length of our dear string
