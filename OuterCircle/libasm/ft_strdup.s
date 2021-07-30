section .text
	global	_ft_strdup
	extern	_malloc
	extern	_ft_strlen
	extern	_ft_strcpy

_ft_strdup:				; rdi = src
    mov	rax, 0
    push rdi
    call _ft_strlen		; rax = _ft_strlen(rdi)
    pop rdi
    mov r8, rax
    inc r8
    push rdi
    mov rdi, r8
    call _malloc		; rax = _malloc(rdi)
    pop rdi
    cmp rax, 0
    jz error
    mov rsi, rdi
    mov rdi, rax
    call _ft_strcpy		; _ft_strcpy(rdi, rsi)
    jmp return

error:
	mov	rax, 0

return:
    ret
