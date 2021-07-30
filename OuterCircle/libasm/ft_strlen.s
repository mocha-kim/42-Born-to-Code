	section .text
    global _ft_strlen

_ft_strlen:					; str = rdi
    mov rax, 0				; i = 0

loop:
    cmp byte[rdi+rax], 0x0
    jz  return
    inc rax
    jmp loop

return:
    ret						; return i(rax)
