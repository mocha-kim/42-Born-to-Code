section .text
   global  _ft_write

_ft_write:				; fd = rdi, buffer = rsi, bytes = rdx
    mov rax, 0x2000004	; write bsystem call
    syscall
    ret
