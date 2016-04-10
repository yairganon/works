section	.rodata
LC0:
	DB	"%s", 10, 0	; Format string

section .bss
LC1:
	RESB	32

section .text
	align 16
	global my_func
	extern printf

my_func:
	push	ebp
	mov	ebp, esp	; Entry code - set up ebp and esp
	mov ecx, dword [ebp+8]	; Get argument (pointer to string)
	pushad			; Save registers
	mov edx , 0
	mov ebx , ecx
check_length:
	inc ebx
	inc edx
	cmp byte [ebx], 0xA 
	jnz check_length
	mov ebx , LC1
	mov al , 0x30
	and edx ,1
	jnz odd
my_loop:
	mov al ,[ecx]   ;al = STRING[i]
	inc ecx	
odd:
	sub al , 48		;al = int(al)
	shl al, 2		;al*=2		
	mov ah , [ecx]	;al = STRING[i]
	sub ah , 48		;ah = int(ah)
	add al , ah		;al+=ah
	cmp al , 0xA
	jb bellow_10
	add al, 7
bellow_10:
	add al, 48
	mov [ebx] , al	;STRING[i] = al
	inc ebx
	inc ecx
	cmp byte [ecx], 0xA ; check if byte pointed to is zero
	jnz my_loop
	;mov byte [ebx] , 0 
;       Your code should be here...
	
	push	LC1		; Call printf with 2 arguments: pointer to str
	push	LC0		; and pointer to format string.
	call	printf
	add 	esp, 8		; Clean up stack after call

	popad			; Restore registers
	mov	esp, ebp	; Function exit code
	pop	ebp
	ret

 ;