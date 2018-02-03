	.file	"temp.c"
	.text
	.globl	Pg_magic_func
	.type	Pg_magic_func, @function
Pg_magic_func:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$Pg_magic_data.4613, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	Pg_magic_func, .-Pg_magic_func
	.globl	add_one
	.type	add_one, @function
add_one:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	movl	-4(%rbp), %eax
	addl	$1, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	add_one, .-add_one
	.section	.rodata
	.align 16
	.type	Pg_magic_data.4613, @object
	.size	Pg_magic_data.4613, 28
Pg_magic_data.4613:
	.long	28
	.long	901
	.long	100
	.long	32
	.long	64
	.long	1
	.long	1
	.ident	"GCC: (Ubuntu 5.2.1-22ubuntu2) 5.2.1 20151010"
	.section	.note.GNU-stack,"",@progbits
