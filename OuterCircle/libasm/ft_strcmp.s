	section .text
    global _ft_strcmp

_ft_strcmp:				; s1 = rdi, s2 = rsi
    mov rcx, 0			; i = 0
    cmp rdi, 0
    jz is_null
    cmp rsi, 0
    jz is_null

is_null:
	cmp rdi, rsi
	jz	equal
	jg	sup
	jmp	inf

loop:
	mov	dl, BYTE [rsi + rcx]
	cmp	BYTE [rdi + rcx], dl
	jne	last_char
	inc	rcx
	cmp	BYTE[rdi + rcx], 0
	je	last_char
	cmp	BYTE[rsi + rcx], 0
	je	last_char
	jmp	loop

last_char:
	mov		dl, BYTE [rdi + rcx]
	sub		dl, BYTE [rsi + rcx]
	cmp		dl, 0
	jz		equal
	jl		inf

sup:
    mov rax, 1
    ret

inf:
    mov rax, -1
    ret

equal:
    mov rax, 0
    ret
