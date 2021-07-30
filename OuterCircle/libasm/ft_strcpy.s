	section .text
    global _ft_strcpy

_ft_strcpy:					; dst = rdi, ser = rsi
    mov	rcx, 0				; i = 0

loop:
    cmp byte [rsi + rcx], 0
    jz	return
    mov	dl, BYTE [rsi + rcx]
    mov	BYTE [rdi + rcx], dl
    inc	rcx
    jmp	loop

return:
    mov	byte [rdi + rcx], 0x0
    mov	rax, rdi 			; ret = dst
    ret						; return ret
	