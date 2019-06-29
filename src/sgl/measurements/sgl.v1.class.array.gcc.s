	.file	"sgl.v1.class.array.cpp"
	.text
	.p2align 4,,15
	.type	_ZN3sgl2v111generate_bmIN9__gnu_cxx17__normal_iteratorIPjSt6vectorIjSaIjEEEElEEvT_S9_RKT0_.isra.49, @function
_ZN3sgl2v111generate_bmIN9__gnu_cxx17__normal_iteratorIPjSt6vectorIjSaIjEEEElEEvT_S9_RKT0_.isra.49:
.LFB6607:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	%edx, %ecx
	movl	$1, %edx
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$4896, %rsp
	.cfi_offset 3, -24
	movq	%rcx, -5024(%rbp)
	.p2align 4,,10
	.p2align 3
.L2:
	movq	%rcx, %rax
	shrq	$30, %rax
	xorq	%rcx, %rax
	imulq	$1812433253, %rax, %rax
	leal	(%rax,%rdx), %ecx
	movq	%rcx, -5024(%rbp,%rdx,8)
	addq	$1, %rdx
	cmpq	$624, %rdx
	jne	.L2
	leaq	-5024(%rbp), %rax
	movl	$2567483615, %r8d
	leaq	1816(%rax), %r10
	leaq	3168(%rax), %r9
	cmpq	%rsi, %rdi
	jne	.L15
	jmp	.L1
	.p2align 4,,10
	.p2align 3
.L25:
	movq	-5024(%rbp,%rdx,8), %r11
	addq	$1, %rdx
.L5:
	movq	%r11, %rcx
	addq	$4, %rdi
	shrq	$11, %rcx
	movl	%ecx, %eax
	xorq	%r11, %rax
	movq	%rax, %rcx
	salq	$7, %rcx
	andl	$2636928640, %ecx
	xorq	%rcx, %rax
	movq	%rax, %rcx
	salq	$15, %rcx
	andl	$4022730752, %ecx
	xorq	%rcx, %rax
	movq	%rax, %rcx
	shrq	$18, %rcx
	xorq	%rcx, %rax
	movl	%eax, -4(%rdi)
	cmpq	%rdi, %rsi
	je	.L1
.L15:
	cmpq	$624, %rdx
	jne	.L25
	leaq	-5024(%rbp), %rax
	movq	-5024(%rbp), %rbx
	movq	%rax, %rdx
	.p2align 4,,10
	.p2align 3
.L6:
	andq	$-2147483648, %rbx
	movq	%rbx, %rcx
	movq	8(%rdx), %rbx
	movq	%rbx, %r11
	andl	$2147483647, %r11d
	orq	%rcx, %r11
	movq	%r11, %rcx
	shrq	%rcx
	xorq	3176(%rdx), %rcx
	andl	$1, %r11d
	je	.L7
	xorq	%r8, %rcx
	addq	$8, %rdx
	movq	%rcx, -8(%rdx)
	cmpq	%rdx, %r10
	jne	.L6
.L8:
	movq	-3208(%rbp), %r11
	.p2align 4,,10
	.p2align 3
.L10:
	movq	%r11, %rdx
	movq	1824(%rax), %r11
	andq	$-2147483648, %rdx
	movq	%r11, %rcx
	andl	$2147483647, %ecx
	orq	%rdx, %rcx
	movq	%rcx, %rdx
	shrq	%rdx
	xorq	(%rax), %rdx
	andl	$1, %ecx
	je	.L11
	xorq	%r8, %rdx
	addq	$8, %rax
	movq	%rdx, 1808(%rax)
	cmpq	%r9, %rax
	jne	.L10
.L12:
	movq	-5024(%rbp), %r11
	movq	-40(%rbp), %rax
	movq	%r11, %rdx
	andq	$-2147483648, %rax
	andl	$2147483647, %edx
	orq	%rdx, %rax
	movq	%rax, %rdx
	shrq	%rdx
	xorq	-1856(%rbp), %rdx
	testb	$1, %al
	je	.L14
	xorq	%r8, %rdx
.L14:
	movq	%rdx, -40(%rbp)
	movl	$1, %edx
	jmp	.L5
	.p2align 4,,10
	.p2align 3
.L11:
	movq	%rdx, 1816(%rax)
	addq	$8, %rax
	cmpq	%r9, %rax
	jne	.L10
	jmp	.L12
	.p2align 4,,10
	.p2align 3
.L7:
	movq	%rcx, (%rdx)
	addq	$8, %rdx
	cmpq	%rdx, %r10
	jne	.L6
	jmp	.L8
	.p2align 4,,10
	.p2align 3
.L1:
	addq	$4896, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6607:
	.size	_ZN3sgl2v111generate_bmIN9__gnu_cxx17__normal_iteratorIPjSt6vectorIjSaIjEEEElEEvT_S9_RKT0_.isra.49, .-_ZN3sgl2v111generate_bmIN9__gnu_cxx17__normal_iteratorIPjSt6vectorIjSaIjEEEElEEvT_S9_RKT0_.isra.49
	.p2align 4,,15
	.type	_ZSt13__adjust_heapIPmlmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_.constprop.78, @function
_ZSt13__adjust_heapIPmlmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_.constprop.78:
.LFB6627:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	leaq	-1(%rdx), %rax
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	.cfi_offset 12, -24
	movq	%rdx, %r12
	pushq	%rbx
	.cfi_offset 3, -32
	movq	%rax, %rbx
	andl	$1, %r12d
	shrq	$63, %rbx
	addq	%rax, %rbx
	sarq	%rbx
	cmpq	%rbx, %rsi
	jge	.L27
	movq	%rsi, %r10
	jmp	.L28
	.p2align 4,,10
	.p2align 3
.L42:
	subq	$1, %r8
	leaq	(%rdi,%r8,8), %r9
	movq	(%r9), %rax
	movq	%rax, (%rdi,%r10,8)
	cmpq	%rbx, %r8
	jge	.L30
.L31:
	movq	%r8, %r10
.L28:
	leaq	1(%r10), %rax
	leaq	(%rax,%rax), %r8
	salq	$4, %rax
	leaq	(%rdi,%rax), %r9
	movq	(%r9), %r11
	cmpq	-8(%rdi,%rax), %r11
	jb	.L42
	movq	%r11, (%rdi,%r10,8)
	cmpq	%rbx, %r8
	jl	.L31
.L30:
	testq	%r12, %r12
	je	.L36
.L32:
	leaq	-1(%r8), %rax
	movq	%rax, %rdx
	shrq	$63, %rdx
	addq	%rax, %rdx
	sarq	%rdx
	cmpq	%rsi, %r8
	jle	.L33
	movq	(%rdi,%rdx,8), %r10
	cmpq	%r10, %rcx
	ja	.L34
	jmp	.L33
	.p2align 4,,10
	.p2align 3
.L35:
	movq	(%rdi,%rax,8), %r10
	movq	%rdx, %r8
	movq	%rax, %rdx
	cmpq	%rcx, %r10
	jnb	.L33
.L34:
	movq	%r10, (%rdi,%r8,8)
	leaq	-1(%rdx), %r8
	leaq	(%rdi,%rdx,8), %r9
	movq	%r8, %rax
	shrq	$63, %rax
	addq	%r8, %rax
	sarq	%rax
	cmpq	%rdx, %rsi
	jl	.L35
.L33:
	movq	%rcx, (%r9)
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
	.p2align 4,,10
	.p2align 3
.L27:
	.cfi_restore_state
	leaq	(%rdi,%rsi,8), %r9
	movq	%rsi, %r8
	testq	%r12, %r12
	jne	.L33
	.p2align 4,,10
	.p2align 3
.L36:
	leaq	-2(%rdx), %rax
	movq	%rax, %rdx
	shrq	$63, %rdx
	addq	%rax, %rdx
	sarq	%rdx
	cmpq	%rdx, %r8
	jne	.L32
	leaq	2(%r8,%r8), %r8
	movq	-8(%rdi,%r8,8), %rax
	subq	$1, %r8
	movq	%rax, (%r9)
	leaq	(%rdi,%r8,8), %r9
	jmp	.L32
	.cfi_endproc
.LFE6627:
	.size	_ZSt13__adjust_heapIPmlmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_.constprop.78, .-_ZSt13__adjust_heapIPmlmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_.constprop.78
	.p2align 4,,15
	.type	_ZSt13__introselectIPmlN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_T1_.isra.67, @function
_ZSt13__introselectIPmlN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_T1_.isra.67:
.LFB6625:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	movq	%rsi, %r13
	pushq	%r12
	.cfi_offset 12, -48
	movq	%rdx, %r12
	pushq	%rbx
	movq	%r12, %rax
	.cfi_offset 3, -56
	movq	%rdi, %rbx
	subq	%rbx, %rax
	subq	$24, %rsp
	cmpq	$24, %rax
	jle	.L45
	.p2align 4,,10
	.p2align 3
.L88:
	testq	%rcx, %rcx
	je	.L86
	sarq	$4, %rax
	movq	8(%rbx), %rdi
	subq	$1, %rcx
	movq	(%rbx), %rsi
	leaq	(%rbx,%rax,8), %r9
	movq	-8(%r12), %r8
	leaq	8(%rbx), %rax
	movq	(%r9), %rdx
	cmpq	%rdx, %rdi
	jnb	.L55
	cmpq	%r8, %rdx
	jb	.L61
	cmpq	%r8, %rdi
	jnb	.L85
.L84:
	movq	%r8, (%rbx)
	movq	%rsi, -8(%r12)
	movq	(%rbx), %rdi
.L57:
	movq	%r12, %rdx
	.p2align 4,,10
	.p2align 3
.L60:
	movq	(%rax), %r8
	cmpq	%rdi, %r8
	jb	.L62
	subq	$8, %rdx
	cmpq	%rsi, %rdi
	jnb	.L63
	.p2align 4,,10
	.p2align 3
.L64:
	subq	$8, %rdx
	movq	(%rdx), %rsi
	cmpq	%rdi, %rsi
	ja	.L64
.L63:
	cmpq	%rdx, %rax
	jnb	.L87
	movq	%rsi, (%rax)
	movq	-8(%rdx), %rsi
	movq	%r8, (%rdx)
	movq	(%rbx), %rdi
.L62:
	addq	$8, %rax
	jmp	.L60
	.p2align 4,,10
	.p2align 3
.L87:
	cmpq	%rax, %r13
	cmovb	%rax, %r12
	cmovnb	%rax, %rbx
	movq	%r12, %rax
	subq	%rbx, %rax
	cmpq	$24, %rax
	jg	.L88
.L45:
	cmpq	%rbx, %r12
	je	.L43
	leaq	8(%rbx), %r14
	cmpq	%r14, %r12
	je	.L43
	movl	$8, %r13d
	jmp	.L74
	.p2align 4,,10
	.p2align 3
.L89:
	cmpq	%r14, %rbx
	je	.L70
	movq	%r14, %rdx
	leaq	(%rbx,%r13), %rdi
	movq	%rbx, %rsi
	subq	%rbx, %rdx
	call	memmove
.L70:
	addq	$8, %r14
	movq	%r15, (%rbx)
	cmpq	%r14, %r12
	je	.L43
.L74:
	movq	(%r14), %r15
	cmpq	(%rbx), %r15
	jb	.L89
	movq	-8(%r14), %rdx
	leaq	-8(%r14), %rax
	cmpq	%r15, %rdx
	ja	.L73
	jmp	.L90
	.p2align 4,,10
	.p2align 3
.L77:
	movq	%rcx, %rax
.L73:
	movq	%rdx, 8(%rax)
	movq	-8(%rax), %rdx
	leaq	-8(%rax), %rcx
	cmpq	%rdx, %r15
	jb	.L77
.L72:
	addq	$8, %r14
	movq	%r15, (%rax)
	cmpq	%r14, %r12
	jne	.L74
.L43:
	addq	$24, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
	.p2align 4,,10
	.p2align 3
.L55:
	.cfi_restore_state
	cmpq	%r8, %rdi
	jb	.L85
	cmpq	%r8, %rdx
	jb	.L84
.L61:
	movq	%rdx, (%rbx)
	movq	%rsi, (%r9)
	movq	(%rbx), %rdi
	movq	-8(%r12), %rsi
	jmp	.L57
	.p2align 4,,10
	.p2align 3
.L85:
	movq	%rdi, -56(%rbp)
	movq	-56(%rbp), %xmm0
	movq	%rsi, -56(%rbp)
	movhps	-56(%rbp), %xmm0
	movups	%xmm0, (%rbx)
	movq	-8(%r12), %rsi
	jmp	.L57
.L86:
	leaq	8(%r13), %r15
	movq	%r15, %rax
	subq	%rbx, %rax
	movq	%rax, -64(%rbp)
	cmpq	$8, %rax
	jle	.L50
	movq	-64(%rbp), %rax
	movl	$2, %ecx
	sarq	$3, %rax
	movq	%rax, -56(%rbp)
	subq	$2, %rax
	cqto
	idivq	%rcx
	movq	%rax, %r14
	jmp	.L51
	.p2align 4,,10
	.p2align 3
.L91:
	subq	$1, %r14
.L51:
	movq	(%rbx,%r14,8), %rcx
	movq	-56(%rbp), %rdx
	movq	%r14, %rsi
	movq	%rbx, %rdi
	call	_ZSt13__adjust_heapIPmlmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_.constprop.78
	testq	%r14, %r14
	jne	.L91
.L50:
	movq	-64(%rbp), %r14
	movq	(%rbx), %rax
	sarq	$3, %r14
	cmpq	%r15, %r12
	ja	.L54
	jmp	.L53
	.p2align 4,,10
	.p2align 3
.L52:
	addq	$8, %r15
	cmpq	%r15, %r12
	jbe	.L53
.L54:
	movq	(%r15), %rcx
	cmpq	%rax, %rcx
	jnb	.L52
	movq	%rax, (%r15)
	movq	%r14, %rdx
	xorl	%esi, %esi
	movq	%rbx, %rdi
	addq	$8, %r15
	call	_ZSt13__adjust_heapIPmlmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_T0_S5_T1_T2_.constprop.78
	movq	(%rbx), %rax
	cmpq	%r15, %r12
	ja	.L54
.L53:
	movq	0(%r13), %rdx
	movq	%rdx, (%rbx)
	movq	%rax, 0(%r13)
	jmp	.L43
.L90:
	movq	%r14, %rax
	jmp	.L72
	.cfi_endproc
.LFE6625:
	.size	_ZSt13__introselectIPmlN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_T1_.isra.67, .-_ZSt13__introselectIPmlN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_T1_.isra.67
	.section	.text._ZNSt11char_traitsIcE6lengthEPKc,"axG",@progbits,_ZNSt11char_traitsIcE6lengthEPKc,comdat
	.p2align 4,,15
	.weak	_ZNSt11char_traitsIcE6lengthEPKc
	.type	_ZNSt11char_traitsIcE6lengthEPKc, @function
_ZNSt11char_traitsIcE6lengthEPKc:
.LFB403:
	.cfi_startproc
	jmp	strlen
	.cfi_endproc
.LFE403:
	.size	_ZNSt11char_traitsIcE6lengthEPKc, .-_ZNSt11char_traitsIcE6lengthEPKc
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC2:
	.string	"median"
.LC3:
	.string	"\t\t"
.LC4:
	.string	"avg"
.LC5:
	.string	"dev"
.LC6:
	.string	"\t"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB7:
	.section	.text.startup,"ax",@progbits
.LHOTB7:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB5646:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA5646
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$40000000, %edi
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
.LEHB0:
	call	_Znwm
.LEHE0:
	movl	$40000000, %edx
	xorl	%esi, %esi
	movq	%rax, %rbx
	movq	%rax, %rdi
	call	memset
	movq	%rbx, %rdi
	movl	$10000000, %edx
	leaq	40000000(%rbx), %rsi
	call	_ZN3sgl2v111generate_bmIN9__gnu_cxx17__normal_iteratorIPjSt6vectorIjSaIjEEEElEEvT_S9_RKT0_.isra.49
	call	_ZNSt6chrono3_V212system_clock3nowEv
	movl	$800, %edi
.LEHB1:
	call	_Znwm
.LEHE1:
	movq	%rax, %r14
	movl	$800, %edi
	leaq	800(%rax), %rax
	movq	%rax, -56(%rbp)
.LEHB2:
	call	_Znwm
.LEHE2:
	movq	%rax, %r15
	leaq	800(%rax), %rax
	xorl	%r12d, %r12d
	movq	%rax, -64(%rbp)
.L96:
	call	_ZNSt6chrono3_V212system_clock3nowEv
	movl	$40000000, %edi
	movq	%rax, %r13
.LEHB3:
	call	_Znwm
	movl	$40000000, %edx
	xorl	%esi, %esi
	movq	%rax, %rdi
	call	memset
	movq	%rax, %rcx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L94:
	movdqu	(%rbx,%rax), %xmm6
	movups	%xmm6, (%rcx,%rax)
	addq	$16, %rax
	cmpq	$40000000, %rax
	jne	.L94
	movq	%rcx, %rdi
	call	_ZdlPv
	call	_ZNSt6chrono3_V212system_clock3nowEv
	subq	%r13, %rax
	movq	%rax, (%r14,%r12,8)
	call	_ZNSt6chrono3_V212system_clock3nowEv
	movl	$40000000, %edi
	movq	%rax, %r13
	call	_Znwm
	xorl	%edx, %edx
	.p2align 4,,10
	.p2align 3
.L95:
	movdqu	(%rbx,%rdx), %xmm7
	movups	%xmm7, (%rax,%rdx)
	addq	$16, %rdx
	cmpq	$40000000, %rdx
	jne	.L95
	movq	%rax, %rdi
	call	_ZdlPv
	call	_ZNSt6chrono3_V212system_clock3nowEv
	subq	%r13, %rax
	movq	%rax, (%r15,%r12,8)
	addq	$1, %r12
	cmpq	$100, %r12
	jne	.L96
	movq	%r14, %r12
	movq	%r14, %rax
	pxor	%xmm0, %xmm0
.L97:
	movdqu	(%rax), %xmm5
	addq	$16, %rax
	paddq	%xmm5, %xmm0
	cmpq	%rax, -56(%rbp)
	jne	.L97
	movdqa	%xmm0, %xmm1
	movq	%r15, %r13
	movabsq	$2951479051793528259, %rcx
	psrldq	$8, %xmm1
	paddq	%xmm1, %xmm0
	movq	%xmm0, %rdx
	pxor	%xmm0, %xmm0
	shrq	$2, %rdx
	movq	%rdx, %rax
	mulq	%rcx
	movq	%r15, %rax
	shrq	$2, %rdx
	movq	%rdx, -72(%rbp)
.L98:
	movdqu	(%rax), %xmm5
	addq	$16, %rax
	paddq	%xmm5, %xmm0
	cmpq	%rax, -64(%rbp)
	jne	.L98
	movdqa	%xmm0, %xmm1
	leaq	400(%r14), %rsi
	movq	%r14, %rdi
	movabsq	$2951479051793528259, %rcx
	psrldq	$8, %xmm1
	paddq	%xmm1, %xmm0
	movq	%xmm0, %rdx
	shrq	$2, %rdx
	movq	%rdx, %rax
	mulq	%rcx
	movl	$12, %ecx
	shrq	$2, %rdx
	movq	%rdx, -80(%rbp)
	movq	-56(%rbp), %rdx
	call	_ZSt13__introselectIPmlN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_T1_.isra.67
	movq	-64(%rbp), %rdx
	movl	$12, %ecx
	movq	%r15, %rdi
	leaq	400(%r15), %rsi
	call	_ZSt13__introselectIPmlN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_T1_.isra.67
	movq	400(%r14), %rax
	movq	-72(%rbp), %xmm4
	pxor	%xmm0, %xmm0
	movq	%rax, -88(%rbp)
	movq	400(%r15), %rax
	punpcklqdq	%xmm4, %xmm4
	movq	%rax, -96(%rbp)
.L99:
	movdqu	(%r12), %xmm2
	addq	$16, %r12
	psubq	%xmm4, %xmm2
	movdqa	%xmm2, %xmm1
	movdqa	%xmm2, %xmm3
	psrlq	$32, %xmm1
	pmuludq	%xmm2, %xmm3
	pmuludq	%xmm2, %xmm1
	paddq	%xmm1, %xmm1
	psllq	$32, %xmm1
	paddq	%xmm3, %xmm1
	paddq	%xmm1, %xmm0
	cmpq	%r12, -56(%rbp)
	jne	.L99
	movdqa	%xmm0, %xmm1
	pxor	%xmm5, %xmm5
	movabsq	$2951479051793528259, %rcx
	psrldq	$8, %xmm1
	paddq	%xmm1, %xmm0
	movq	%xmm0, %rdx
	pxor	%xmm0, %xmm0
	shrq	$2, %rdx
	movq	%rdx, %rax
	mulq	%rcx
	shrq	$2, %rdx
	cvtsi2sdq	%rdx, %xmm0
	ucomisd	%xmm0, %xmm5
	sqrtsd	%xmm0, %xmm1
	ja	.L123
.L100:
	movsd	.LC1(%rip), %xmm3
	comisd	%xmm3, %xmm1
	jnb	.L101
	cvttsd2siq	%xmm1, %r12
.L102:
	movq	-80(%rbp), %xmm5
	pxor	%xmm0, %xmm0
	punpcklqdq	%xmm5, %xmm5
.L103:
	movdqu	0(%r13), %xmm2
	addq	$16, %r13
	psubq	%xmm5, %xmm2
	movdqa	%xmm2, %xmm1
	movdqa	%xmm2, %xmm4
	psrlq	$32, %xmm1
	pmuludq	%xmm2, %xmm4
	pmuludq	%xmm2, %xmm1
	paddq	%xmm1, %xmm1
	psllq	$32, %xmm1
	paddq	%xmm4, %xmm1
	paddq	%xmm1, %xmm0
	cmpq	%r13, -64(%rbp)
	jne	.L103
	movdqa	%xmm0, %xmm1
	pxor	%xmm5, %xmm5
	movabsq	$2951479051793528259, %rcx
	psrldq	$8, %xmm1
	paddq	%xmm1, %xmm0
	movq	%xmm0, %rdx
	pxor	%xmm0, %xmm0
	shrq	$2, %rdx
	movq	%rdx, %rax
	mulq	%rcx
	shrq	$2, %rdx
	cvtsi2sdq	%rdx, %xmm0
	ucomisd	%xmm0, %xmm5
	sqrtsd	%xmm0, %xmm1
	ja	.L124
.L104:
	comisd	%xmm3, %xmm1
	jnb	.L105
	cvttsd2siq	%xmm1, %r13
.L106:
	movl	$.LC2, %edi
	call	_ZNSt11char_traitsIcE6lengthEPKc
	movl	$.LC2, %esi
	movl	$_ZSt4cout, %edi
	movq	%rax, %rdx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movl	$.LC3, %edi
	call	_ZNSt11char_traitsIcE6lengthEPKc
	movl	$.LC3, %esi
	movl	$_ZSt4cout, %edi
	movq	%rax, %rdx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movl	$.LC4, %edi
	call	_ZNSt11char_traitsIcE6lengthEPKc
	movl	$.LC4, %esi
	movl	$_ZSt4cout, %edi
	movq	%rax, %rdx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movl	$.LC3, %edi
	call	_ZNSt11char_traitsIcE6lengthEPKc
	movl	$.LC3, %esi
	movl	$_ZSt4cout, %edi
	movq	%rax, %rdx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movl	$.LC5, %edi
	call	_ZNSt11char_traitsIcE6lengthEPKc
	movl	$.LC5, %esi
	movl	$_ZSt4cout, %edi
	movq	%rax, %rdx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movl	$_ZSt4cout, %edi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movq	-88(%rbp), %rsi
	movl	$_ZSt4cout, %edi
	call	_ZNSo9_M_insertImEERSoT_
	movl	$.LC6, %edi
	movq	%rax, -56(%rbp)
	call	_ZNSt11char_traitsIcE6lengthEPKc
	movq	-56(%rbp), %rdi
	movl	$.LC6, %esi
	movq	%rax, %rdx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movq	-72(%rbp), %rsi
	movq	-56(%rbp), %rdi
	call	_ZNSo9_M_insertImEERSoT_
	movl	$.LC6, %edi
	movq	%rax, -56(%rbp)
	call	_ZNSt11char_traitsIcE6lengthEPKc
	movq	-56(%rbp), %rdi
	movl	$.LC6, %esi
	movq	%rax, %rdx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movq	-56(%rbp), %rdi
	movq	%r12, %rsi
	call	_ZNSo9_M_insertImEERSoT_
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movq	-96(%rbp), %rsi
	movl	$_ZSt4cout, %edi
	call	_ZNSo9_M_insertImEERSoT_
	movl	$.LC6, %edi
	movq	%rax, %r12
	call	_ZNSt11char_traitsIcE6lengthEPKc
	movl	$.LC6, %esi
	movq	%r12, %rdi
	movq	%rax, %rdx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movq	-80(%rbp), %rsi
	movq	%r12, %rdi
	call	_ZNSo9_M_insertImEERSoT_
	movl	$.LC6, %edi
	movq	%rax, %r12
	call	_ZNSt11char_traitsIcE6lengthEPKc
	movl	$.LC6, %esi
	movq	%r12, %rdi
	movq	%rax, %rdx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movq	%r13, %rsi
	movq	%r12, %rdi
	call	_ZNSo9_M_insertImEERSoT_
	movq	%rax, %rdi
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
.LEHE3:
	movq	%r15, %rdi
	call	_ZdlPv
	movq	%r14, %rdi
	call	_ZdlPv
	movq	%rbx, %rdi
	call	_ZdlPv
	addq	$56, %rsp
	xorl	%eax, %eax
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
.L101:
	.cfi_restore_state
	subsd	%xmm3, %xmm1
	cvttsd2siq	%xmm1, %r12
	btcq	$63, %r12
	jmp	.L102
.L105:
	subsd	%xmm3, %xmm1
	cvttsd2siq	%xmm1, %r13
	btcq	$63, %r13
	jmp	.L106
.L123:
	movsd	%xmm1, -56(%rbp)
	call	sqrt
	movsd	-56(%rbp), %xmm1
	jmp	.L100
.L124:
	movsd	%xmm1, -56(%rbp)
	call	sqrt
	movsd	.LC1(%rip), %xmm3
	movsd	-56(%rbp), %xmm1
	jmp	.L104
.L110:
	movq	%rax, %r12
	jmp	.L109
.L112:
	movq	%rax, %r12
	jmp	.L107
.L111:
	movq	%rax, %r12
	jmp	.L108
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA5646:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE5646-.LLSDACSB5646
.LLSDACSB5646:
	.uleb128 .LEHB0-.LFB5646
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB5646
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L110-.LFB5646
	.uleb128 0
	.uleb128 .LEHB2-.LFB5646
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L111-.LFB5646
	.uleb128 0
	.uleb128 .LEHB3-.LFB5646
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L112-.LFB5646
	.uleb128 0
.LLSDACSE5646:
	.section	.text.startup
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDAC5646
	.type	main.cold.80, @function
main.cold.80:
.LFSB5646:
.L107:
	.cfi_def_cfa 6, 16
	.cfi_offset 3, -56
	.cfi_offset 6, -16
	.cfi_offset 12, -48
	.cfi_offset 13, -40
	.cfi_offset 14, -32
	.cfi_offset 15, -24
	movq	%r15, %rdi
	call	_ZdlPv
.L108:
	movq	%r14, %rdi
	call	_ZdlPv
.L109:
	movq	%rbx, %rdi
	call	_ZdlPv
	movq	%r12, %rdi
.LEHB4:
	call	_Unwind_Resume
.LEHE4:
	.cfi_endproc
.LFE5646:
	.section	.gcc_except_table
.LLSDAC5646:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC5646-.LLSDACSBC5646
.LLSDACSBC5646:
	.uleb128 .LEHB4-.LCOLDB7
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
.LLSDACSEC5646:
	.section	.text.unlikely
	.section	.text.startup
	.size	main, .-main
	.section	.text.unlikely
	.size	main.cold.80, .-main.cold.80
.LCOLDE7:
	.section	.text.startup
.LHOTE7:
	.p2align 4,,15
	.type	_GLOBAL__sub_I__ZN3sgl2v124instrumented_base_countsE, @function
_GLOBAL__sub_I__ZN3sgl2v124instrumented_base_countsE:
.LFB6557:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$_ZStL8__ioinit, %edi
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	popq	%rbp
	.cfi_def_cfa 7, 8
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	jmp	__cxa_atexit
	.cfi_endproc
.LFE6557:
	.size	_GLOBAL__sub_I__ZN3sgl2v124instrumented_base_countsE, .-_GLOBAL__sub_I__ZN3sgl2v124instrumented_base_countsE
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__ZN3sgl2v124instrumented_base_countsE
	.globl	_ZN3sgl2v131instrumented_base_counter_namesE
	.section	.rodata.str1.1
.LC8:
	.string	"n"
.LC9:
	.string	"copy"
.LC10:
	.string	"assignment"
.LC11:
	.string	"destructor"
.LC12:
	.string	"default_constructor"
.LC13:
	.string	"equality"
.LC14:
	.string	"comparison"
.LC15:
	.string	"construction"
	.data
	.align 32
	.type	_ZN3sgl2v131instrumented_base_counter_namesE, @object
	.size	_ZN3sgl2v131instrumented_base_counter_namesE, 64
_ZN3sgl2v131instrumented_base_counter_namesE:
	.quad	.LC8
	.quad	.LC9
	.quad	.LC10
	.quad	.LC11
	.quad	.LC12
	.quad	.LC13
	.quad	.LC14
	.quad	.LC15
	.globl	_ZN3sgl2v124instrumented_base_countsE
	.bss
	.align 32
	.type	_ZN3sgl2v124instrumented_base_countsE, @object
	.size	_ZN3sgl2v124instrumented_base_countsE, 64
_ZN3sgl2v124instrumented_base_countsE:
	.zero	64
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	0
	.long	1138753536
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 8.3.1 20190223 (Red Hat 8.3.1-2)"
	.section	.note.GNU-stack,"",@progbits
