	.text
	.file	"sgl.v1.class.array.cpp"
	.section	.rodata.cst8,"aM",@progbits,8
	.p2align	3               # -- Begin function main
.LCPI0_0:
	.quad	4890909195324358656     # double 9.2233720368547758E+18
	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
.Lfunc_begin0:
	.cfi_startproc
	.cfi_personality 3, __gxx_personality_v0
	.cfi_lsda 3, .Lexception0
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$56, %rsp
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
.Ltmp0:
	movl	$40000000, %edi         # imm = 0x2625A00
	callq	_Znwm
.Ltmp1:
# %bb.1:
	movq	%rax, %r14
	movq	%rax, %rbx
	addq	$40000000, %rbx         # imm = 0x2625A00
	xorl	%esi, %esi
	movl	$40000000, %edx         # imm = 0x2625A00
	movq	%rax, %rdi
	callq	memset
	movq	$10000000, -88(%rbp)    # imm = 0x989680
.Ltmp3:
	leaq	-88(%rbp), %rdx
	movq	%r14, %rdi
	movq	%rbx, %rsi
	callq	_ZN3sgl2v111generate_bmIN9__gnu_cxx17__normal_iteratorIPjSt6vectorIjSaIjEEEElEEvT_S9_RKT0_
.Ltmp4:
# %bb.2:
	callq	_ZNSt6chrono3_V212system_clock3nowEv
.Ltmp6:
	movl	$800, %edi              # imm = 0x320
	callq	_Znwm
	movq	%rax, -48(%rbp)         # 8-byte Spill
.Ltmp7:
# %bb.3:
.Ltmp9:
	movl	$800, %edi              # imm = 0x320
	callq	_Znwm
.Ltmp10:
# %bb.4:
	movq	%rax, %rcx
	movq	-48(%rbp), %rax         # 8-byte Reload
	leaq	800(%rax), %rax
	movq	%rax, -64(%rbp)         # 8-byte Spill
	movq	%rcx, %r15
	movq	%rcx, -72(%rbp)         # 8-byte Spill
	leaq	800(%rcx), %rax
	movq	%rax, -56(%rbp)         # 8-byte Spill
	xorl	%r13d, %r13d
	.p2align	4, 0x90
.LBB0_5:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB0_7 Depth 2
                                        #     Child Loop BB0_10 Depth 2
	callq	_ZNSt6chrono3_V212system_clock3nowEv
	movq	%rax, %r12
.Ltmp12:
	movl	$40000000, %edi         # imm = 0x2625A00
	callq	_Znwm
.Ltmp13:
# %bb.6:                                #   in Loop: Header=BB0_5 Depth=1
	movq	%rax, %rbx
	xorl	%esi, %esi
	movl	$40000000, %edx         # imm = 0x2625A00
	movq	%rax, %rdi
	callq	memset
	movl	$36, %ecx
	.p2align	4, 0x90
.LBB0_7:                                #   Parent Loop BB0_5 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movups	-144(%r14,%rcx,4), %xmm0
	movups	-128(%r14,%rcx,4), %xmm1
	movups	%xmm0, -144(%rbx,%rcx,4)
	movups	%xmm1, -128(%rbx,%rcx,4)
	movups	-112(%r14,%rcx,4), %xmm0
	movups	-96(%r14,%rcx,4), %xmm1
	movups	%xmm0, -112(%rbx,%rcx,4)
	movups	%xmm1, -96(%rbx,%rcx,4)
	movups	-80(%r14,%rcx,4), %xmm0
	movups	-64(%r14,%rcx,4), %xmm1
	movups	%xmm0, -80(%rbx,%rcx,4)
	movups	%xmm1, -64(%rbx,%rcx,4)
	movups	-48(%r14,%rcx,4), %xmm0
	movups	-32(%r14,%rcx,4), %xmm1
	movups	%xmm0, -48(%rbx,%rcx,4)
	movups	%xmm1, -32(%rbx,%rcx,4)
	movupd	-16(%r14,%rcx,4), %xmm0
	movupd	(%r14,%rcx,4), %xmm1
	movupd	%xmm0, -16(%rbx,%rcx,4)
	movupd	%xmm1, (%rbx,%rcx,4)
	addq	$40, %rcx
	cmpq	$10000036, %rcx         # imm = 0x9896A4
	jne	.LBB0_7
# %bb.8:                                #   in Loop: Header=BB0_5 Depth=1
	movq	%rbx, %rdi
	callq	_ZdlPv
	callq	_ZNSt6chrono3_V212system_clock3nowEv
	subq	%r12, %rax
	movq	-48(%rbp), %rcx         # 8-byte Reload
	movq	%rax, (%rcx,%r13,8)
	callq	_ZNSt6chrono3_V212system_clock3nowEv
	movq	%rax, %r12
.Ltmp15:
	movl	$40000000, %edi         # imm = 0x2625A00
	callq	_Znwm
.Ltmp16:
# %bb.9:                                #   in Loop: Header=BB0_5 Depth=1
	movl	$36, %ecx
	.p2align	4, 0x90
.LBB0_10:                               #   Parent Loop BB0_5 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movups	-144(%r14,%rcx,4), %xmm0
	movups	-128(%r14,%rcx,4), %xmm1
	movups	%xmm0, -144(%rax,%rcx,4)
	movups	%xmm1, -128(%rax,%rcx,4)
	movups	-112(%r14,%rcx,4), %xmm0
	movups	-96(%r14,%rcx,4), %xmm1
	movups	%xmm0, -112(%rax,%rcx,4)
	movups	%xmm1, -96(%rax,%rcx,4)
	movups	-80(%r14,%rcx,4), %xmm0
	movups	-64(%r14,%rcx,4), %xmm1
	movups	%xmm0, -80(%rax,%rcx,4)
	movups	%xmm1, -64(%rax,%rcx,4)
	movups	-48(%r14,%rcx,4), %xmm0
	movups	-32(%r14,%rcx,4), %xmm1
	movups	%xmm0, -48(%rax,%rcx,4)
	movups	%xmm1, -32(%rax,%rcx,4)
	movupd	-16(%r14,%rcx,4), %xmm0
	movupd	(%r14,%rcx,4), %xmm1
	movupd	%xmm0, -16(%rax,%rcx,4)
	movupd	%xmm1, (%rax,%rcx,4)
	addq	$40, %rcx
	cmpq	$10000036, %rcx         # imm = 0x9896A4
	jne	.LBB0_10
# %bb.11:                               #   in Loop: Header=BB0_5 Depth=1
	movq	%rax, %rdi
	callq	_ZdlPv
	callq	_ZNSt6chrono3_V212system_clock3nowEv
	subq	%r12, %rax
	movq	%rax, (%r15,%r13,8)
	addq	$1, %r13
	cmpq	$100, %r13
	jne	.LBB0_5
# %bb.12:
	movq	-48(%rbp), %rdi         # 8-byte Reload
	movq	8(%rdi), %rax
	addq	(%rdi), %rax
	addq	16(%rdi), %rax
	addq	24(%rdi), %rax
	addq	32(%rdi), %rax
	addq	40(%rdi), %rax
	addq	48(%rdi), %rax
	addq	56(%rdi), %rax
	addq	64(%rdi), %rax
	addq	72(%rdi), %rax
	addq	80(%rdi), %rax
	addq	88(%rdi), %rax
	addq	96(%rdi), %rax
	addq	104(%rdi), %rax
	addq	112(%rdi), %rax
	addq	120(%rdi), %rax
	addq	128(%rdi), %rax
	addq	136(%rdi), %rax
	addq	144(%rdi), %rax
	addq	152(%rdi), %rax
	addq	160(%rdi), %rax
	addq	168(%rdi), %rax
	addq	176(%rdi), %rax
	addq	184(%rdi), %rax
	addq	192(%rdi), %rax
	addq	200(%rdi), %rax
	addq	208(%rdi), %rax
	addq	216(%rdi), %rax
	addq	224(%rdi), %rax
	addq	232(%rdi), %rax
	addq	240(%rdi), %rax
	addq	248(%rdi), %rax
	addq	256(%rdi), %rax
	addq	264(%rdi), %rax
	addq	272(%rdi), %rax
	addq	280(%rdi), %rax
	addq	288(%rdi), %rax
	addq	296(%rdi), %rax
	addq	304(%rdi), %rax
	addq	312(%rdi), %rax
	addq	320(%rdi), %rax
	addq	328(%rdi), %rax
	addq	336(%rdi), %rax
	addq	344(%rdi), %rax
	addq	352(%rdi), %rax
	addq	360(%rdi), %rax
	addq	368(%rdi), %rax
	addq	376(%rdi), %rax
	addq	384(%rdi), %rax
	addq	392(%rdi), %rax
	addq	400(%rdi), %rax
	addq	408(%rdi), %rax
	addq	416(%rdi), %rax
	addq	424(%rdi), %rax
	addq	432(%rdi), %rax
	addq	440(%rdi), %rax
	addq	448(%rdi), %rax
	addq	456(%rdi), %rax
	addq	464(%rdi), %rax
	addq	472(%rdi), %rax
	addq	480(%rdi), %rax
	addq	488(%rdi), %rax
	addq	496(%rdi), %rax
	addq	504(%rdi), %rax
	addq	512(%rdi), %rax
	addq	520(%rdi), %rax
	addq	528(%rdi), %rax
	addq	536(%rdi), %rax
	addq	544(%rdi), %rax
	addq	552(%rdi), %rax
	addq	560(%rdi), %rax
	addq	568(%rdi), %rax
	addq	576(%rdi), %rax
	addq	584(%rdi), %rax
	addq	592(%rdi), %rax
	addq	600(%rdi), %rax
	addq	608(%rdi), %rax
	addq	616(%rdi), %rax
	addq	624(%rdi), %rax
	addq	632(%rdi), %rax
	addq	640(%rdi), %rax
	addq	648(%rdi), %rax
	addq	656(%rdi), %rax
	addq	664(%rdi), %rax
	addq	672(%rdi), %rax
	addq	680(%rdi), %rax
	addq	688(%rdi), %rax
	addq	696(%rdi), %rax
	addq	704(%rdi), %rax
	addq	712(%rdi), %rax
	addq	720(%rdi), %rax
	addq	728(%rdi), %rax
	addq	736(%rdi), %rax
	addq	744(%rdi), %rax
	addq	752(%rdi), %rax
	addq	760(%rdi), %rax
	addq	768(%rdi), %rax
	addq	776(%rdi), %rax
	addq	784(%rdi), %rax
	addq	792(%rdi), %rax
	movq	%rdi, %rsi
	movq	8(%r15), %rcx
	addq	(%r15), %rcx
	addq	16(%r15), %rcx
	addq	24(%r15), %rcx
	addq	32(%r15), %rcx
	addq	40(%r15), %rcx
	addq	48(%r15), %rcx
	addq	56(%r15), %rcx
	addq	64(%r15), %rcx
	addq	72(%r15), %rcx
	addq	80(%r15), %rcx
	addq	88(%r15), %rcx
	addq	96(%r15), %rcx
	addq	104(%r15), %rcx
	addq	112(%r15), %rcx
	addq	120(%r15), %rcx
	addq	128(%r15), %rcx
	addq	136(%r15), %rcx
	addq	144(%r15), %rcx
	addq	152(%r15), %rcx
	addq	160(%r15), %rcx
	addq	168(%r15), %rcx
	addq	176(%r15), %rcx
	addq	184(%r15), %rcx
	addq	192(%r15), %rcx
	addq	200(%r15), %rcx
	addq	208(%r15), %rcx
	addq	216(%r15), %rcx
	addq	224(%r15), %rcx
	addq	232(%r15), %rcx
	addq	240(%r15), %rcx
	addq	248(%r15), %rcx
	addq	256(%r15), %rcx
	addq	264(%r15), %rcx
	addq	272(%r15), %rcx
	addq	280(%r15), %rcx
	addq	288(%r15), %rcx
	addq	296(%r15), %rcx
	addq	304(%r15), %rcx
	addq	312(%r15), %rcx
	addq	320(%r15), %rcx
	addq	328(%r15), %rcx
	addq	336(%r15), %rcx
	addq	344(%r15), %rcx
	addq	352(%r15), %rcx
	addq	360(%r15), %rcx
	addq	368(%r15), %rcx
	addq	376(%r15), %rcx
	addq	384(%r15), %rcx
	addq	392(%r15), %rcx
	addq	400(%r15), %rcx
	addq	408(%r15), %rcx
	addq	416(%r15), %rcx
	addq	424(%r15), %rcx
	addq	432(%r15), %rcx
	addq	440(%r15), %rcx
	addq	448(%r15), %rcx
	addq	456(%r15), %rcx
	addq	464(%r15), %rcx
	addq	472(%r15), %rcx
	addq	480(%r15), %rcx
	addq	488(%r15), %rcx
	addq	496(%r15), %rcx
	addq	504(%r15), %rcx
	addq	512(%r15), %rcx
	addq	520(%r15), %rcx
	addq	528(%r15), %rcx
	addq	536(%r15), %rcx
	addq	544(%r15), %rcx
	addq	552(%r15), %rcx
	addq	560(%r15), %rcx
	addq	568(%r15), %rcx
	addq	576(%r15), %rcx
	addq	584(%r15), %rcx
	addq	592(%r15), %rcx
	addq	600(%r15), %rcx
	addq	608(%r15), %rcx
	addq	616(%r15), %rcx
	addq	624(%r15), %rcx
	addq	632(%r15), %rcx
	addq	640(%r15), %rcx
	addq	648(%r15), %rcx
	addq	656(%r15), %rcx
	addq	664(%r15), %rcx
	addq	672(%r15), %rcx
	addq	680(%r15), %rcx
	addq	688(%r15), %rcx
	addq	696(%r15), %rcx
	addq	704(%r15), %rcx
	addq	712(%r15), %rcx
	addq	720(%r15), %rcx
	addq	728(%r15), %rcx
	addq	736(%r15), %rcx
	addq	744(%r15), %rcx
	addq	752(%r15), %rcx
	addq	760(%r15), %rcx
	addq	768(%r15), %rcx
	addq	776(%r15), %rcx
	addq	784(%r15), %rcx
	addq	792(%r15), %rcx
	shrq	$2, %rax
	movabsq	$2951479051793528259, %rbx # imm = 0x28F5C28F5C28F5C3
	mulq	%rbx
	movq	%rdx, %r13
	addq	$400, %rsi              # imm = 0x190
	shrq	$2, %rcx
	movq	%rcx, %rax
	mulq	%rbx
	movq	%rdx, %r12
.Ltmp18:
	movl	$12, %ecx
	movq	-64(%rbp), %rdx         # 8-byte Reload
	callq	_ZSt13__introselectIPmlN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_T1_
.Ltmp19:
	movq	-72(%rbp), %rbx         # 8-byte Reload
# %bb.13:
	addq	$400, %rbx              # imm = 0x190
.Ltmp20:
	movl	$12, %ecx
	movq	%r15, %rdi
	movq	%rbx, %rsi
	movq	-56(%rbp), %rdx         # 8-byte Reload
	callq	_ZSt13__introselectIPmlN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_T1_
.Ltmp21:
# %bb.14:
	shrq	$2, %r13
	shrq	$2, %r12
	movq	-48(%rbp), %rcx         # 8-byte Reload
	movq	400(%rcx), %rax
	movq	%rax, -72(%rbp)         # 8-byte Spill
	movq	(%rbx), %rax
	movq	%rax, -80(%rbp)         # 8-byte Spill
	xorl	%eax, %eax
	movq	-64(%rbp), %rdi         # 8-byte Reload
	.p2align	4, 0x90
.LBB0_15:                               # =>This Inner Loop Header: Depth=1
	movq	(%rcx), %rdx
	movq	8(%rcx), %rsi
	subq	%r13, %rdx
	imulq	%rdx, %rdx
	addq	%rax, %rdx
	subq	%r13, %rsi
	imulq	%rsi, %rsi
	addq	%rdx, %rsi
	movq	16(%rcx), %rax
	subq	%r13, %rax
	imulq	%rax, %rax
	addq	%rsi, %rax
	movq	24(%rcx), %rdx
	subq	%r13, %rdx
	imulq	%rdx, %rdx
	addq	%rax, %rdx
	movq	32(%rcx), %rax
	subq	%r13, %rax
	imulq	%rax, %rax
	addq	%rdx, %rax
	addq	$40, %rcx
	cmpq	%rdi, %rcx
	jne	.LBB0_15
# %bb.16:
	shrq	$2, %rax
	movabsq	$2951479051793528259, %rcx # imm = 0x28F5C28F5C28F5C3
	mulq	%rcx
	shrq	$2, %rdx
	cvtsi2sdq	%rdx, %xmm0
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jb	.LBB0_24
# %bb.17:
	sqrtsd	%xmm0, %xmm0
	jmp	.LBB0_25
.LBB0_24:
	callq	sqrt
.LBB0_25:
	movq	-56(%rbp), %rdi         # 8-byte Reload
	xorl	%eax, %eax
	movq	%r15, %rcx
	.p2align	4, 0x90
.LBB0_26:                               # =>This Inner Loop Header: Depth=1
	movq	(%rcx), %rdx
	movq	8(%rcx), %rsi
	subq	%r12, %rdx
	imulq	%rdx, %rdx
	addq	%rax, %rdx
	subq	%r12, %rsi
	imulq	%rsi, %rsi
	addq	%rdx, %rsi
	movq	16(%rcx), %rax
	subq	%r12, %rax
	imulq	%rax, %rax
	addq	%rsi, %rax
	movq	24(%rcx), %rdx
	subq	%r12, %rdx
	imulq	%rdx, %rdx
	addq	%rax, %rdx
	movq	32(%rcx), %rax
	subq	%r12, %rax
	imulq	%rax, %rax
	addq	%rdx, %rax
	addq	$40, %rcx
	cmpq	%rdi, %rcx
	jne	.LBB0_26
# %bb.27:
	movsd	.LCPI0_0(%rip), %xmm2   # xmm2 = mem[0],zero
	movapd	%xmm0, %xmm1
	subsd	%xmm2, %xmm1
	cvttsd2si	%xmm1, %rcx
	movabsq	$-9223372036854775808, %rbx # imm = 0x8000000000000000
	xorq	%rbx, %rcx
	cvttsd2si	%xmm0, %rdx
	ucomisd	%xmm2, %xmm0
	cmovaeq	%rcx, %rdx
	movq	%rdx, -64(%rbp)         # 8-byte Spill
	shrq	$2, %rax
	movabsq	$2951479051793528259, %rcx # imm = 0x28F5C28F5C28F5C3
	mulq	%rcx
	shrq	$2, %rdx
	xorps	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	xorpd	%xmm1, %xmm1
	ucomisd	%xmm1, %xmm0
	jb	.LBB0_29
# %bb.28:
	sqrtsd	%xmm0, %xmm0
	jmp	.LBB0_30
.LBB0_29:
	callq	sqrt
	movsd	.LCPI0_0(%rip), %xmm2   # xmm2 = mem[0],zero
.LBB0_30:
	movapd	%xmm0, %xmm1
	subsd	%xmm2, %xmm1
	cvttsd2si	%xmm1, %rax
	xorq	%rbx, %rax
	cvttsd2si	%xmm0, %rcx
	ucomisd	%xmm2, %xmm0
	cmovaeq	%rax, %rcx
	movq	%rcx, -56(%rbp)         # 8-byte Spill
.Ltmp23:
	movl	$_ZSt4cout, %edi
	movl	$.L.str.8, %esi
	movl	$6, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
.Ltmp24:
# %bb.31:
.Ltmp25:
	movl	$_ZSt4cout, %edi
	movl	$.L.str.9, %esi
	movl	$2, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
.Ltmp26:
# %bb.32:
.Ltmp27:
	movl	$_ZSt4cout, %edi
	movl	$.L.str.10, %esi
	movl	$3, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
.Ltmp28:
# %bb.33:
.Ltmp29:
	movl	$_ZSt4cout, %edi
	movl	$.L.str.9, %esi
	movl	$2, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
.Ltmp30:
# %bb.34:
.Ltmp31:
	movl	$_ZSt4cout, %edi
	movl	$.L.str.11, %esi
	movl	$3, %edx
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
.Ltmp32:
# %bb.35:
	movq	_ZSt4cout(%rip), %rax
	movq	-24(%rax), %rax
	movq	_ZSt4cout+240(%rax), %rbx
	testq	%rbx, %rbx
	je	.LBB0_36
# %bb.38:
	cmpb	$0, 56(%rbx)
	je	.LBB0_40
# %bb.39:
	movb	67(%rbx), %al
	jmp	.LBB0_42
.LBB0_40:
.Ltmp33:
	movq	%rbx, %rdi
	callq	_ZNKSt5ctypeIcE13_M_widen_initEv
.Ltmp34:
# %bb.41:
	movq	(%rbx), %rax
.Ltmp35:
	movl	$10, %esi
	movq	%rbx, %rdi
	callq	*48(%rax)
.Ltmp36:
.LBB0_42:
.Ltmp37:
	movsbl	%al, %esi
	movl	$_ZSt4cout, %edi
	callq	_ZNSo3putEc
.Ltmp38:
# %bb.43:
.Ltmp39:
	movq	%rax, %rdi
	callq	_ZNSo5flushEv
.Ltmp40:
# %bb.44:
.Ltmp41:
	movl	$_ZSt4cout, %edi
	movq	-72(%rbp), %rsi         # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_
.Ltmp42:
# %bb.45:
	movq	%rax, %rbx
.Ltmp43:
	movl	$.L.str.12, %esi
	movl	$1, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
.Ltmp44:
# %bb.46:
.Ltmp45:
	movq	%rbx, %rdi
	movq	%r13, %rsi
	callq	_ZNSo9_M_insertImEERSoT_
.Ltmp46:
# %bb.47:
	movq	%rax, %rbx
.Ltmp47:
	movl	$.L.str.12, %esi
	movl	$1, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
.Ltmp48:
# %bb.48:
.Ltmp49:
	movq	%rbx, %rdi
	movq	-64(%rbp), %rsi         # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_
.Ltmp50:
# %bb.49:
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbx
	testq	%rbx, %rbx
	je	.LBB0_50
# %bb.52:
	cmpb	$0, 56(%rbx)
	je	.LBB0_54
# %bb.53:
	movb	67(%rbx), %al
	jmp	.LBB0_56
.LBB0_54:
.Ltmp51:
	movq	%rbx, %rdi
	callq	_ZNKSt5ctypeIcE13_M_widen_initEv
.Ltmp52:
# %bb.55:
	movq	(%rbx), %rax
.Ltmp53:
	movl	$10, %esi
	movq	%rbx, %rdi
	callq	*48(%rax)
.Ltmp54:
.LBB0_56:
.Ltmp55:
	movsbl	%al, %esi
	movq	%r13, %rdi
	callq	_ZNSo3putEc
.Ltmp56:
# %bb.57:
.Ltmp57:
	movq	%rax, %rdi
	callq	_ZNSo5flushEv
.Ltmp58:
# %bb.58:
.Ltmp59:
	movl	$_ZSt4cout, %edi
	movq	-80(%rbp), %rsi         # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_
.Ltmp60:
# %bb.59:
	movq	%rax, %rbx
.Ltmp61:
	movl	$.L.str.12, %esi
	movl	$1, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
.Ltmp62:
# %bb.60:
.Ltmp63:
	movq	%rbx, %rdi
	movq	%r12, %rsi
	callq	_ZNSo9_M_insertImEERSoT_
.Ltmp64:
# %bb.61:
	movq	%rax, %rbx
.Ltmp65:
	movl	$.L.str.12, %esi
	movl	$1, %edx
	movq	%rax, %rdi
	callq	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
.Ltmp66:
# %bb.62:
.Ltmp67:
	movq	%rbx, %rdi
	movq	-56(%rbp), %rsi         # 8-byte Reload
	callq	_ZNSo9_M_insertImEERSoT_
.Ltmp68:
# %bb.63:
	movq	%rax, %r12
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r12,%rax), %rbx
	testq	%rbx, %rbx
	je	.LBB0_64
# %bb.66:
	cmpb	$0, 56(%rbx)
	je	.LBB0_68
# %bb.67:
	movb	67(%rbx), %al
	jmp	.LBB0_70
.LBB0_68:
.Ltmp69:
	movq	%rbx, %rdi
	callq	_ZNKSt5ctypeIcE13_M_widen_initEv
.Ltmp70:
# %bb.69:
	movq	(%rbx), %rax
.Ltmp71:
	movl	$10, %esi
	movq	%rbx, %rdi
	callq	*48(%rax)
.Ltmp72:
.LBB0_70:
.Ltmp73:
	movsbl	%al, %esi
	movq	%r12, %rdi
	callq	_ZNSo3putEc
.Ltmp74:
# %bb.71:
.Ltmp75:
	movq	%rax, %rdi
	callq	_ZNSo5flushEv
.Ltmp76:
# %bb.72:
	movq	%r15, %rdi
	callq	_ZdlPv
	movq	-48(%rbp), %rdi         # 8-byte Reload
	callq	_ZdlPv
	movq	%r14, %rdi
	callq	_ZdlPv
	xorl	%eax, %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.LBB0_36:
	.cfi_def_cfa %rbp, 16
.Ltmp81:
	callq	_ZSt16__throw_bad_castv
.Ltmp82:
# %bb.37:
.LBB0_50:
.Ltmp79:
	callq	_ZSt16__throw_bad_castv
.Ltmp80:
# %bb.51:
.LBB0_64:
.Ltmp77:
	callq	_ZSt16__throw_bad_castv
.Ltmp78:
# %bb.65:
.LBB0_21:
.Ltmp11:
	movq	%rax, %r12
	jmp	.LBB0_76
.LBB0_20:
.Ltmp8:
	movq	%rax, %r12
	movq	%r14, %rdi
	callq	_ZdlPv
	movq	%r12, %rdi
	callq	_Unwind_Resume
.LBB0_19:
.Ltmp5:
	movq	%rax, %r12
	movq	%r14, %rdi
	callq	_ZdlPv
	movq	%r12, %rdi
	callq	_Unwind_Resume
.LBB0_18:
.Ltmp2:
	movq	%rax, %rdi
	callq	_Unwind_Resume
.LBB0_73:
.Ltmp22:
	jmp	.LBB0_75
.LBB0_74:
.Ltmp83:
	jmp	.LBB0_75
.LBB0_23:
.Ltmp17:
	jmp	.LBB0_75
.LBB0_22:
.Ltmp14:
.LBB0_75:
	movq	%rax, %r12
	movq	%r15, %rdi
	callq	_ZdlPv
.LBB0_76:
	movq	-48(%rbp), %rdi         # 8-byte Reload
	callq	_ZdlPv
	movq	%r14, %rdi
	callq	_ZdlPv
	movq	%r12, %rdi
	callq	_Unwind_Resume
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
	.section	.gcc_except_table,"a",@progbits
	.p2align	2
GCC_except_table0:
.Lexception0:
	.byte	255                     # @LPStart Encoding = omit
	.byte	255                     # @TType Encoding = omit
	.byte	1                       # Call site Encoding = uleb128
	.uleb128 .Lcst_end0-.Lcst_begin0
.Lcst_begin0:
	.uleb128 .Ltmp0-.Lfunc_begin0   # >> Call Site 1 <<
	.uleb128 .Ltmp1-.Ltmp0          #   Call between .Ltmp0 and .Ltmp1
	.uleb128 .Ltmp2-.Lfunc_begin0   #     jumps to .Ltmp2
	.byte	0                       #   On action: cleanup
	.uleb128 .Ltmp1-.Lfunc_begin0   # >> Call Site 2 <<
	.uleb128 .Ltmp3-.Ltmp1          #   Call between .Ltmp1 and .Ltmp3
	.byte	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.uleb128 .Ltmp3-.Lfunc_begin0   # >> Call Site 3 <<
	.uleb128 .Ltmp4-.Ltmp3          #   Call between .Ltmp3 and .Ltmp4
	.uleb128 .Ltmp5-.Lfunc_begin0   #     jumps to .Ltmp5
	.byte	0                       #   On action: cleanup
	.uleb128 .Ltmp6-.Lfunc_begin0   # >> Call Site 4 <<
	.uleb128 .Ltmp7-.Ltmp6          #   Call between .Ltmp6 and .Ltmp7
	.uleb128 .Ltmp8-.Lfunc_begin0   #     jumps to .Ltmp8
	.byte	0                       #   On action: cleanup
	.uleb128 .Ltmp9-.Lfunc_begin0   # >> Call Site 5 <<
	.uleb128 .Ltmp10-.Ltmp9         #   Call between .Ltmp9 and .Ltmp10
	.uleb128 .Ltmp11-.Lfunc_begin0  #     jumps to .Ltmp11
	.byte	0                       #   On action: cleanup
	.uleb128 .Ltmp12-.Lfunc_begin0  # >> Call Site 6 <<
	.uleb128 .Ltmp13-.Ltmp12        #   Call between .Ltmp12 and .Ltmp13
	.uleb128 .Ltmp14-.Lfunc_begin0  #     jumps to .Ltmp14
	.byte	0                       #   On action: cleanup
	.uleb128 .Ltmp13-.Lfunc_begin0  # >> Call Site 7 <<
	.uleb128 .Ltmp15-.Ltmp13        #   Call between .Ltmp13 and .Ltmp15
	.byte	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
	.uleb128 .Ltmp15-.Lfunc_begin0  # >> Call Site 8 <<
	.uleb128 .Ltmp16-.Ltmp15        #   Call between .Ltmp15 and .Ltmp16
	.uleb128 .Ltmp17-.Lfunc_begin0  #     jumps to .Ltmp17
	.byte	0                       #   On action: cleanup
	.uleb128 .Ltmp18-.Lfunc_begin0  # >> Call Site 9 <<
	.uleb128 .Ltmp21-.Ltmp18        #   Call between .Ltmp18 and .Ltmp21
	.uleb128 .Ltmp22-.Lfunc_begin0  #     jumps to .Ltmp22
	.byte	0                       #   On action: cleanup
	.uleb128 .Ltmp23-.Lfunc_begin0  # >> Call Site 10 <<
	.uleb128 .Ltmp78-.Ltmp23        #   Call between .Ltmp23 and .Ltmp78
	.uleb128 .Ltmp83-.Lfunc_begin0  #     jumps to .Ltmp83
	.byte	0                       #   On action: cleanup
	.uleb128 .Ltmp78-.Lfunc_begin0  # >> Call Site 11 <<
	.uleb128 .Lfunc_end0-.Ltmp78    #   Call between .Ltmp78 and .Lfunc_end0
	.byte	0                       #     has no landing pad
	.byte	0                       #   On action: cleanup
.Lcst_end0:
	.p2align	2
                                        # -- End function
	.section	.text._ZN3sgl2v111generate_bmIN9__gnu_cxx17__normal_iteratorIPjSt6vectorIjSaIjEEEElEEvT_S9_RKT0_,"axG",@progbits,_ZN3sgl2v111generate_bmIN9__gnu_cxx17__normal_iteratorIPjSt6vectorIjSaIjEEEElEEvT_S9_RKT0_,comdat
	.weak	_ZN3sgl2v111generate_bmIN9__gnu_cxx17__normal_iteratorIPjSt6vectorIjSaIjEEEElEEvT_S9_RKT0_ # -- Begin function _ZN3sgl2v111generate_bmIN9__gnu_cxx17__normal_iteratorIPjSt6vectorIjSaIjEEEElEEvT_S9_RKT0_
	.p2align	4, 0x90
	.type	_ZN3sgl2v111generate_bmIN9__gnu_cxx17__normal_iteratorIPjSt6vectorIjSaIjEEEElEEvT_S9_RKT0_,@function
_ZN3sgl2v111generate_bmIN9__gnu_cxx17__normal_iteratorIPjSt6vectorIjSaIjEEEElEEvT_S9_RKT0_: # @_ZN3sgl2v111generate_bmIN9__gnu_cxx17__normal_iteratorIPjSt6vectorIjSaIjEEEElEEvT_S9_RKT0_
	.cfi_startproc
# %bb.0:
	pushq	%r14
	.cfi_def_cfa_offset 16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	subq	$4872, %rsp             # imm = 0x1308
	.cfi_def_cfa_offset 4896
	.cfi_offset %rbx, -24
	.cfi_offset %r14, -16
	movl	(%rdx), %ebx
	movq	%rbx, -128(%rsp)
	movl	$1, %r8d
	movl	$16, %r9d
	movl	$2, %r10d
	xorl	%r11d, %r11d
	movabsq	$945986875574848801, %r14 # imm = 0xD20D20D20D20D21
	jmp	.LBB1_1
	.p2align	4, 0x90
.LBB1_12:                               #   in Loop: Header=BB1_1 Depth=1
	shrq	%rcx
	imulq	$624, %rcx, %rcx        # imm = 0x270
	movq	%r10, %rbx
	subq	%rcx, %rbx
	movq	%rax, %rcx
	shrq	$30, %rcx
	xorl	%eax, %ecx
	imull	$1812433253, %ecx, %eax # imm = 0x6C078965
	addl	%eax, %ebx
	movq	%rbx, -128(%rsp,%r9)
	addq	$2, %r8
	addq	$16, %r9
	addq	$2, %r10
	addq	$2, %r11
.LBB1_1:                                # =>This Inner Loop Header: Depth=1
	movq	%r10, %rax
	shrq	$4, %rax
	mulq	%r14
	movq	%rdx, %rcx
	movq	%r11, %rax
	shrq	$4, %rax
	mulq	%r14
	shrq	%rdx
	imull	$624, %edx, %eax        # imm = 0x270
	movl	%r8d, %edx
	subl	%eax, %edx
	movq	%rbx, %rax
	shrq	$30, %rax
	xorl	%ebx, %eax
	imull	$1812433253, %eax, %eax # imm = 0x6C078965
	addl	%edx, %eax
	movq	%rax, -136(%rsp,%r9)
	cmpq	$4992, %r9              # imm = 0x1380
	jne	.LBB1_12
# %bb.2:
	movq	$624, 4864(%rsp)        # imm = 0x270
	cmpq	%rsi, %rdi
	je	.LBB1_11
# %bb.3:
	movl	$624, %ecx              # imm = 0x270
	movq	$-2147483648, %r8       # imm = 0x80000000
	.p2align	4, 0x90
.LBB1_4:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB1_6 Depth 2
                                        #     Child Loop BB1_8 Depth 2
	cmpq	$623, %rcx              # imm = 0x26F
	jbe	.LBB1_10
# %bb.5:                                #   in Loop: Header=BB1_4 Depth=1
	movq	-128(%rsp), %rdx
	xorl	%r9d, %r9d
	.p2align	4, 0x90
.LBB1_6:                                #   Parent Loop BB1_4 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	andq	$-2147483648, %rdx      # imm = 0x80000000
	movq	-120(%rsp,%r9,8), %rax
	movl	%eax, %ebx
	andl	$2147483646, %ebx       # imm = 0x7FFFFFFE
	orq	%rdx, %rbx
	shrq	%rbx
	xorq	3048(%rsp,%r9,8), %rbx
	movq	%rax, %rdx
                                        # kill: def $eax killed $eax killed $rax
	andl	$1, %eax
	negl	%eax
	movl	$2567483615, %ecx       # imm = 0x9908B0DF
	andl	%eax, %ecx
	xorq	%rbx, %rcx
	movq	%rcx, -128(%rsp,%r9,8)
	leaq	1(%r9), %r9
	cmpq	$227, %r9
	jne	.LBB1_6
# %bb.7:                                #   in Loop: Header=BB1_4 Depth=1
	movq	1688(%rsp), %rdx
	xorl	%r9d, %r9d
	.p2align	4, 0x90
.LBB1_8:                                #   Parent Loop BB1_4 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	andq	$-2147483648, %rdx      # imm = 0x80000000
	movq	1696(%rsp,%r9,8), %rbx
	movl	%ebx, %eax
	andl	$2147483646, %eax       # imm = 0x7FFFFFFE
	orq	%rdx, %rax
	shrq	%rax
	xorq	-128(%rsp,%r9,8), %rax
	movq	%rbx, %rdx
                                        # kill: def $ebx killed $ebx killed $rbx
	andl	$1, %ebx
	negl	%ebx
	movl	$2567483615, %ecx       # imm = 0x9908B0DF
	andl	%ebx, %ecx
	xorq	%rax, %rcx
	movq	%rcx, 1688(%rsp,%r9,8)
	addq	$1, %r9
	cmpq	$396, %r9               # imm = 0x18C
	jne	.LBB1_8
# %bb.9:                                #   in Loop: Header=BB1_4 Depth=1
	movq	4856(%rsp), %rax
	andq	%r8, %rax
	movq	-128(%rsp), %rcx
	movl	%ecx, %edx
	andl	$2147483646, %edx       # imm = 0x7FFFFFFE
	orq	%rax, %rdx
	shrq	%rdx
	xorq	3040(%rsp), %rdx
	andl	$1, %ecx
	negl	%ecx
	movl	$2567483615, %eax       # imm = 0x9908B0DF
	andl	%ecx, %eax
	xorq	%rdx, %rax
	movq	%rax, 4856(%rsp)
	movq	$0, 4864(%rsp)
	xorl	%ecx, %ecx
.LBB1_10:                               #   in Loop: Header=BB1_4 Depth=1
	leaq	1(%rcx), %rax
	movq	%rax, 4864(%rsp)
	movq	-128(%rsp,%rcx,8), %rcx
	movq	%rcx, %rdx
	shrq	$11, %rdx
	movl	%edx, %edx
	xorq	%rcx, %rdx
	movq	%rdx, %rcx
	andq	$20601005, %rcx         # imm = 0x13A58AD
	shlq	$7, %rcx
	xorq	%rdx, %rcx
	movq	%rcx, %rdx
	andq	$122764, %rdx           # imm = 0x1DF8C
	shlq	$15, %rdx
	xorq	%rcx, %rdx
	movq	%rdx, %rcx
	shrq	$18, %rcx
	xorl	%edx, %ecx
	movl	%ecx, (%rdi)
	addq	$4, %rdi
	movq	%rax, %rcx
	cmpq	%rsi, %rdi
	jne	.LBB1_4
.LBB1_11:
	addq	$4872, %rsp             # imm = 0x1308
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	retq
.Lfunc_end1:
	.size	_ZN3sgl2v111generate_bmIN9__gnu_cxx17__normal_iteratorIPjSt6vectorIjSaIjEEEElEEvT_S9_RKT0_, .Lfunc_end1-_ZN3sgl2v111generate_bmIN9__gnu_cxx17__normal_iteratorIPjSt6vectorIjSaIjEEEElEEvT_S9_RKT0_
	.cfi_endproc
                                        # -- End function
	.section	.text._ZSt13__introselectIPmlN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_T1_,"axG",@progbits,_ZSt13__introselectIPmlN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_T1_,comdat
	.weak	_ZSt13__introselectIPmlN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_T1_ # -- Begin function _ZSt13__introselectIPmlN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_T1_
	.p2align	4, 0x90
	.type	_ZSt13__introselectIPmlN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_T1_,@function
_ZSt13__introselectIPmlN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_T1_: # @_ZSt13__introselectIPmlN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_T1_
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -56
	.cfi_offset %r12, -48
	.cfi_offset %r13, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	movq	%rdx, %r14
	movq	%rdi, %r13
	movq	%rdx, %rax
	subq	%rdi, %rax
	cmpq	$25, %rax
	jl	.LBB2_23
# %bb.1:
	movq	%rsi, %r15
	.p2align	4, 0x90
.LBB2_2:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB2_16 Depth 2
                                        #       Child Loop BB2_17 Depth 3
                                        #       Child Loop BB2_19 Depth 3
	testq	%rcx, %rcx
	je	.LBB2_3
# %bb.4:                                #   in Loop: Header=BB2_2 Depth=1
	shrq	$4, %rax
	movq	8(%r13), %rsi
	movq	(%r13,%rax,8), %rdi
	movq	-8(%r14), %rdx
	cmpq	%rdi, %rsi
	jae	.LBB2_9
# %bb.5:                                #   in Loop: Header=BB2_2 Depth=1
	cmpq	%rdx, %rdi
	jae	.LBB2_7
# %bb.6:                                #   in Loop: Header=BB2_2 Depth=1
	movq	(%r13), %rdx
	movq	%rdi, (%r13)
	movq	%rdx, (%r13,%rax,8)
	jmp	.LBB2_15
	.p2align	4, 0x90
.LBB2_9:                                #   in Loop: Header=BB2_2 Depth=1
	cmpq	%rdx, %rsi
	jae	.LBB2_12
# %bb.10:                               #   in Loop: Header=BB2_2 Depth=1
	movq	(%r13), %rax
	jmp	.LBB2_11
	.p2align	4, 0x90
.LBB2_7:                                #   in Loop: Header=BB2_2 Depth=1
	movq	(%r13), %rax
	cmpq	%rdx, %rsi
	jae	.LBB2_11
# %bb.8:                                #   in Loop: Header=BB2_2 Depth=1
	movq	%rdx, (%r13)
	movq	%rax, -8(%r14)
	jmp	.LBB2_15
	.p2align	4, 0x90
.LBB2_11:                               #   in Loop: Header=BB2_2 Depth=1
	movq	%rsi, (%r13)
	movq	%rax, 8(%r13)
	jmp	.LBB2_15
	.p2align	4, 0x90
.LBB2_12:                               #   in Loop: Header=BB2_2 Depth=1
	movq	(%r13), %rsi
	cmpq	%rdx, %rdi
	jae	.LBB2_14
# %bb.13:                               #   in Loop: Header=BB2_2 Depth=1
	movq	%rdx, (%r13)
	movq	%rsi, -8(%r14)
	jmp	.LBB2_15
.LBB2_14:                               #   in Loop: Header=BB2_2 Depth=1
	movq	%rdi, (%r13)
	movq	%rsi, (%r13,%rax,8)
	.p2align	4, 0x90
.LBB2_15:                               #   in Loop: Header=BB2_2 Depth=1
	addq	$-1, %rcx
	leaq	8(%r13), %rax
	movq	%r14, %rdx
	jmp	.LBB2_16
	.p2align	4, 0x90
.LBB2_21:                               #   in Loop: Header=BB2_16 Depth=2
	movq	%rbx, (%r8)
	movq	%rsi, (%rdx)
.LBB2_16:                               #   Parent Loop BB2_2 Depth=1
                                        # =>  This Loop Header: Depth=2
                                        #       Child Loop BB2_17 Depth 3
                                        #       Child Loop BB2_19 Depth 3
	movq	(%r13), %rdi
	.p2align	4, 0x90
.LBB2_17:                               #   Parent Loop BB2_2 Depth=1
                                        #     Parent Loop BB2_16 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movq	(%rax), %rsi
	addq	$8, %rax
	cmpq	%rdi, %rsi
	jb	.LBB2_17
# %bb.18:                               #   in Loop: Header=BB2_16 Depth=2
	leaq	-8(%rax), %r8
	.p2align	4, 0x90
.LBB2_19:                               #   Parent Loop BB2_2 Depth=1
                                        #     Parent Loop BB2_16 Depth=2
                                        # =>    This Inner Loop Header: Depth=3
	movq	-8(%rdx), %rbx
	addq	$-8, %rdx
	cmpq	%rbx, %rdi
	jb	.LBB2_19
# %bb.20:                               #   in Loop: Header=BB2_16 Depth=2
	cmpq	%rdx, %r8
	jb	.LBB2_21
# %bb.22:                               #   in Loop: Header=BB2_2 Depth=1
	cmpq	%r15, %r8
	cmovaq	%r8, %r14
	cmovbeq	%r8, %r13
	movq	%r14, %rax
	subq	%r13, %rax
	cmpq	$24, %rax
	jg	.LBB2_2
.LBB2_23:
	cmpq	%r14, %r13
	je	.LBB2_33
# %bb.24:
	leaq	8(%r13), %rax
	cmpq	%r14, %rax
	je	.LBB2_33
# %bb.25:
	movq	%r13, %r15
	.p2align	4, 0x90
.LBB2_26:                               # =>This Loop Header: Depth=1
                                        #     Child Loop BB2_31 Depth 2
	movq	%r15, %rdi
	movq	%rax, %r15
	movq	8(%rdi), %r12
	cmpq	(%r13), %r12
	jae	.LBB2_29
# %bb.27:                               #   in Loop: Header=BB2_26 Depth=1
	movq	%r15, %rdx
	movq	%r13, %rax
	subq	%r13, %rdx
	je	.LBB2_32
# %bb.28:                               #   in Loop: Header=BB2_26 Depth=1
	subq	%rdx, %rdi
	addq	$16, %rdi
	movq	%r13, %rsi
	callq	memmove
	movq	%r13, %rax
	movq	%r12, (%rax)
	leaq	8(%r15), %rax
	cmpq	%r14, %rax
	jne	.LBB2_26
	jmp	.LBB2_33
	.p2align	4, 0x90
.LBB2_29:                               #   in Loop: Header=BB2_26 Depth=1
	movq	(%rdi), %rcx
	movq	%r15, %rax
	cmpq	%rcx, %r12
	jae	.LBB2_32
# %bb.30:                               #   in Loop: Header=BB2_26 Depth=1
	movq	%r15, %rax
	.p2align	4, 0x90
.LBB2_31:                               #   Parent Loop BB2_26 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	movq	%rcx, (%rax)
	movq	-16(%rax), %rcx
	addq	$-8, %rax
	cmpq	%rcx, %r12
	jb	.LBB2_31
.LBB2_32:                               #   in Loop: Header=BB2_26 Depth=1
	movq	%r12, (%rax)
	leaq	8(%r15), %rax
	cmpq	%r14, %rax
	jne	.LBB2_26
	jmp	.LBB2_33
.LBB2_3:
	leaq	8(%r15), %rsi
	movq	%r13, %rdi
	movq	%r14, %rdx
	callq	_ZSt13__heap_selectIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_
	movq	(%r13), %rax
	movq	(%r15), %rcx
	movq	%rcx, (%r13)
	movq	%rax, (%r15)
.LBB2_33:
	addq	$8, %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end2:
	.size	_ZSt13__introselectIPmlN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_T1_, .Lfunc_end2-_ZSt13__introselectIPmlN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_T1_
	.cfi_endproc
                                        # -- End function
	.section	.text._ZSt13__heap_selectIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_,"axG",@progbits,_ZSt13__heap_selectIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_,comdat
	.weak	_ZSt13__heap_selectIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_ # -- Begin function _ZSt13__heap_selectIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_
	.p2align	4, 0x90
	.type	_ZSt13__heap_selectIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_,@function
_ZSt13__heap_selectIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_: # @_ZSt13__heap_selectIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%r15
	pushq	%r14
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -40
	.cfi_offset %r14, -32
	.cfi_offset %r15, -24
	movq	%rdx, %r14
	movq	%rsi, %r15
	movq	%rdi, %rbx
	leaq	-32(%rbp), %rdx
	callq	_ZSt11__make_heapIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_
	cmpq	%r14, %r15
	jae	.LBB3_44
# %bb.1:
	movq	%r15, %r9
	subq	%rbx, %r9
	movq	%r9, %rax
	sarq	$3, %rax
	leaq	-1(%rax), %rcx
	cmpq	$17, %r9
	jl	.LBB3_19
# %bb.2:
	shrq	$63, %rcx
	addq	%rax, %rcx
	addq	$-1, %rcx
	sarq	%rcx
	leaq	-2(%rax), %rdx
	shrq	$63, %rdx
	leaq	(%rax,%rdx), %r10
	addq	$-2, %r10
	sarq	%r10
	leaq	(%r10,%r10), %r8
	addq	$1, %r8
	.p2align	4, 0x90
.LBB3_3:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB3_5 Depth 2
                                        #     Child Loop BB3_13 Depth 2
	movq	(%r15), %rdi
	movq	(%rbx), %rax
	cmpq	%rax, %rdi
	jae	.LBB3_18
# %bb.4:                                #   in Loop: Header=BB3_3 Depth=1
	movq	%rax, (%r15)
	xorl	%esi, %esi
	.p2align	4, 0x90
.LBB3_5:                                #   Parent Loop BB3_3 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	leaq	(%rsi,%rsi), %rax
	movq	16(%rbx,%rax,8), %rdx
	cmpq	8(%rbx,%rax,8), %rdx
	jb	.LBB3_7
# %bb.6:                                #   in Loop: Header=BB3_5 Depth=2
	leaq	(%rsi,%rsi), %rax
	addq	$2, %rax
	jmp	.LBB3_8
	.p2align	4, 0x90
.LBB3_7:                                #   in Loop: Header=BB3_5 Depth=2
	leaq	(%rsi,%rsi), %rax
	addq	$1, %rax
.LBB3_8:                                #   in Loop: Header=BB3_5 Depth=2
	movq	(%rbx,%rax,8), %rdx
	movq	%rdx, (%rbx,%rsi,8)
	movq	%rax, %rsi
	cmpq	%rcx, %rax
	jl	.LBB3_5
# %bb.9:                                #   in Loop: Header=BB3_3 Depth=1
	testb	$8, %r9b
	jne	.LBB3_12
# %bb.10:                               #   in Loop: Header=BB3_3 Depth=1
	cmpq	%r10, %rax
	jne	.LBB3_12
# %bb.11:                               #   in Loop: Header=BB3_3 Depth=1
	movq	(%rbx,%r8,8), %rax
	movq	%rax, (%rbx,%r10,8)
	movq	%r8, %rax
.LBB3_12:                               #   in Loop: Header=BB3_3 Depth=1
	testq	%rax, %rax
	jle	.LBB3_16
	.p2align	4, 0x90
.LBB3_13:                               #   Parent Loop BB3_3 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	leaq	-1(%rax), %rdx
	shrq	$63, %rdx
	leaq	(%rax,%rdx), %rsi
	addq	$-1, %rsi
	sarq	%rsi
	movq	(%rbx,%rsi,8), %rdx
	cmpq	%rdi, %rdx
	jae	.LBB3_16
# %bb.14:                               #   in Loop: Header=BB3_13 Depth=2
	movq	%rdx, (%rbx,%rax,8)
	cmpq	$2, %rax
	movq	%rsi, %rax
	jg	.LBB3_13
	jmp	.LBB3_17
	.p2align	4, 0x90
.LBB3_16:                               #   in Loop: Header=BB3_3 Depth=1
	movq	%rax, %rsi
.LBB3_17:                               #   in Loop: Header=BB3_3 Depth=1
	movq	%rdi, (%rbx,%rsi,8)
.LBB3_18:                               #   in Loop: Header=BB3_3 Depth=1
	addq	$8, %r15
	cmpq	%r14, %r15
	jb	.LBB3_3
	jmp	.LBB3_44
.LBB3_19:
	testb	$8, %r9b
	jne	.LBB3_28
	.p2align	4, 0x90
.LBB3_20:                               # =>This Inner Loop Header: Depth=1
	movq	(%r15), %rax
	movq	(%rbx), %rdx
	cmpq	%rdx, %rax
	jae	.LBB3_27
# %bb.21:                               #   in Loop: Header=BB3_20 Depth=1
	movq	%rdx, (%r15)
	cmpq	$2, %rcx
	ja	.LBB3_24
# %bb.22:                               #   in Loop: Header=BB3_20 Depth=1
	movq	8(%rbx), %rdx
	movq	%rdx, (%rbx)
	cmpq	%rax, %rdx
	jae	.LBB3_25
# %bb.23:                               #   in Loop: Header=BB3_20 Depth=1
	movq	%rdx, 8(%rbx)
.LBB3_24:                               #   in Loop: Header=BB3_20 Depth=1
	xorl	%edx, %edx
	jmp	.LBB3_26
.LBB3_25:                               #   in Loop: Header=BB3_20 Depth=1
	movl	$1, %edx
.LBB3_26:                               #   in Loop: Header=BB3_20 Depth=1
	movq	%rax, (%rbx,%rdx,8)
.LBB3_27:                               #   in Loop: Header=BB3_20 Depth=1
	addq	$8, %r15
	cmpq	%r14, %r15
	jb	.LBB3_20
	jmp	.LBB3_44
.LBB3_28:
	movq	(%rbx), %rdx
	movq	%r15, %rcx
	notq	%rcx
	addq	%r14, %rcx
	movl	%ecx, %esi
	shrl	$3, %esi
	addl	$1, %esi
	andq	$3, %rsi
	je	.LBB3_33
# %bb.29:
	negq	%rsi
	.p2align	4, 0x90
.LBB3_30:                               # =>This Inner Loop Header: Depth=1
	movq	(%r15), %rax
	cmpq	%rdx, %rax
	jae	.LBB3_32
# %bb.31:                               #   in Loop: Header=BB3_30 Depth=1
	movq	%rdx, (%r15)
	movq	%rax, (%rbx)
	movq	%rax, %rdx
	addq	$8, %r15
	addq	$1, %rsi
	jne	.LBB3_30
	jmp	.LBB3_34
	.p2align	4, 0x90
.LBB3_32:                               #   in Loop: Header=BB3_30 Depth=1
	movq	%rdx, %rax
	addq	$8, %r15
	addq	$1, %rsi
	jne	.LBB3_30
	jmp	.LBB3_34
.LBB3_33:
	movq	%rdx, %rax
.LBB3_34:
	cmpq	$24, %rcx
	jb	.LBB3_44
	.p2align	4, 0x90
.LBB3_35:                               # =>This Inner Loop Header: Depth=1
	movq	(%r15), %rcx
	cmpq	%rax, %rcx
	jae	.LBB3_40
# %bb.36:                               #   in Loop: Header=BB3_35 Depth=1
	movq	%rax, (%r15)
	movq	%rcx, (%rbx)
	movq	8(%r15), %rax
	cmpq	%rcx, %rax
	jb	.LBB3_41
.LBB3_37:                               #   in Loop: Header=BB3_35 Depth=1
	movq	%rcx, %rax
	movq	16(%r15), %rcx
	cmpq	%rax, %rcx
	jb	.LBB3_42
.LBB3_38:                               #   in Loop: Header=BB3_35 Depth=1
	movq	%rax, %rcx
	movq	24(%r15), %rax
	cmpq	%rcx, %rax
	jb	.LBB3_43
.LBB3_39:                               #   in Loop: Header=BB3_35 Depth=1
	movq	%rcx, %rax
	addq	$32, %r15
	cmpq	%r14, %r15
	jb	.LBB3_35
	jmp	.LBB3_44
	.p2align	4, 0x90
.LBB3_40:                               #   in Loop: Header=BB3_35 Depth=1
	movq	%rax, %rcx
	movq	8(%r15), %rax
	cmpq	%rcx, %rax
	jae	.LBB3_37
.LBB3_41:                               #   in Loop: Header=BB3_35 Depth=1
	movq	%rcx, 8(%r15)
	movq	%rax, (%rbx)
	movq	16(%r15), %rcx
	cmpq	%rax, %rcx
	jae	.LBB3_38
.LBB3_42:                               #   in Loop: Header=BB3_35 Depth=1
	movq	%rax, 16(%r15)
	movq	%rcx, (%rbx)
	movq	24(%r15), %rax
	cmpq	%rcx, %rax
	jae	.LBB3_39
.LBB3_43:                               #   in Loop: Header=BB3_35 Depth=1
	movq	%rcx, 24(%r15)
	movq	%rax, (%rbx)
	addq	$32, %r15
	cmpq	%r14, %r15
	jb	.LBB3_35
.LBB3_44:
	addq	$8, %rsp
	popq	%rbx
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end3:
	.size	_ZSt13__heap_selectIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_, .Lfunc_end3-_ZSt13__heap_selectIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_S4_T0_
	.cfi_endproc
                                        # -- End function
	.section	.text._ZSt11__make_heapIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_,"axG",@progbits,_ZSt11__make_heapIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_,comdat
	.weak	_ZSt11__make_heapIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_ # -- Begin function _ZSt11__make_heapIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_
	.p2align	4, 0x90
	.type	_ZSt11__make_heapIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_,@function
_ZSt11__make_heapIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_: # @_ZSt11__make_heapIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_
	.cfi_startproc
# %bb.0:
	subq	%rdi, %rsi
	cmpq	$16, %rsi
	jl	.LBB4_29
# %bb.1:
	movq	%rsi, %rax
	sarq	$3, %rax
	leaq	-2(%rax), %rcx
	shrq	$63, %rcx
	leaq	(%rax,%rcx), %r9
	addq	$-2, %r9
	sarq	%r9
	leaq	-1(%rax), %rcx
	shrq	$63, %rcx
	addq	%rax, %rcx
	addq	$-1, %rcx
	sarq	%rcx
	testb	$8, %sil
	jne	.LBB4_17
# %bb.2:
	leaq	(%r9,%r9), %r8
	addq	$1, %r8
	movq	%r9, %r11
	.p2align	4, 0x90
.LBB4_3:                                # =>This Loop Header: Depth=1
                                        #     Child Loop BB4_5 Depth 2
                                        #     Child Loop BB4_12 Depth 2
	movq	(%rdi,%r11,8), %r10
	movq	%r11, %rdx
	cmpq	%r11, %rcx
	jle	.LBB4_9
# %bb.4:                                #   in Loop: Header=BB4_3 Depth=1
	movq	%r11, %rax
	.p2align	4, 0x90
.LBB4_5:                                #   Parent Loop BB4_3 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	leaq	(%rax,%rax), %rdx
	movq	16(%rdi,%rdx,8), %rsi
	cmpq	8(%rdi,%rdx,8), %rsi
	jb	.LBB4_7
# %bb.6:                                #   in Loop: Header=BB4_5 Depth=2
	leaq	(%rax,%rax), %rdx
	addq	$2, %rdx
	jmp	.LBB4_8
	.p2align	4, 0x90
.LBB4_7:                                #   in Loop: Header=BB4_5 Depth=2
	leaq	(%rax,%rax), %rdx
	addq	$1, %rdx
.LBB4_8:                                #   in Loop: Header=BB4_5 Depth=2
	movq	(%rdi,%rdx,8), %rsi
	movq	%rsi, (%rdi,%rax,8)
	movq	%rdx, %rax
	cmpq	%rcx, %rdx
	jl	.LBB4_5
.LBB4_9:                                #   in Loop: Header=BB4_3 Depth=1
	cmpq	%r9, %rdx
	jne	.LBB4_11
# %bb.10:                               #   in Loop: Header=BB4_3 Depth=1
	movq	(%rdi,%r8,8), %rax
	movq	%rax, (%rdi,%r9,8)
	movq	%r8, %rdx
.LBB4_11:                               #   in Loop: Header=BB4_3 Depth=1
	cmpq	%r11, %rdx
	jle	.LBB4_15
	.p2align	4, 0x90
.LBB4_12:                               #   Parent Loop BB4_3 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	leaq	-1(%rdx), %rax
	shrq	$63, %rax
	addq	%rdx, %rax
	addq	$-1, %rax
	sarq	%rax
	movq	(%rdi,%rax,8), %rsi
	cmpq	%r10, %rsi
	jae	.LBB4_15
# %bb.13:                               #   in Loop: Header=BB4_12 Depth=2
	movq	%rsi, (%rdi,%rdx,8)
	movq	%rax, %rdx
	cmpq	%r11, %rax
	jg	.LBB4_12
	jmp	.LBB4_16
	.p2align	4, 0x90
.LBB4_15:                               #   in Loop: Header=BB4_3 Depth=1
	movq	%rdx, %rax
.LBB4_16:                               #   in Loop: Header=BB4_3 Depth=1
	movq	%r10, (%rdi,%rax,8)
	testq	%r11, %r11
	leaq	-1(%r11), %r11
	jne	.LBB4_3
	jmp	.LBB4_29
	.p2align	4, 0x90
.LBB4_17:                               # =>This Loop Header: Depth=1
                                        #     Child Loop BB4_19 Depth 2
                                        #     Child Loop BB4_24 Depth 2
	movq	(%rdi,%r9,8), %r8
	movq	%r9, %rsi
	cmpq	%r9, %rcx
	jle	.LBB4_26
# %bb.18:                               #   in Loop: Header=BB4_17 Depth=1
	movq	%r9, %rsi
	.p2align	4, 0x90
.LBB4_19:                               #   Parent Loop BB4_17 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	leaq	(%rsi,%rsi), %rax
	movq	16(%rdi,%rax,8), %rdx
	cmpq	8(%rdi,%rax,8), %rdx
	jb	.LBB4_21
# %bb.20:                               #   in Loop: Header=BB4_19 Depth=2
	leaq	(%rsi,%rsi), %rax
	addq	$2, %rax
	jmp	.LBB4_22
	.p2align	4, 0x90
.LBB4_21:                               #   in Loop: Header=BB4_19 Depth=2
	leaq	(%rsi,%rsi), %rax
	addq	$1, %rax
.LBB4_22:                               #   in Loop: Header=BB4_19 Depth=2
	movq	(%rdi,%rax,8), %rdx
	movq	%rdx, (%rdi,%rsi,8)
	movq	%rax, %rsi
	cmpq	%rcx, %rax
	jl	.LBB4_19
# %bb.23:                               #   in Loop: Header=BB4_17 Depth=1
	cmpq	%r9, %rax
	jle	.LBB4_27
	.p2align	4, 0x90
.LBB4_24:                               #   Parent Loop BB4_17 Depth=1
                                        # =>  This Inner Loop Header: Depth=2
	leaq	-1(%rax), %rdx
	shrq	$63, %rdx
	leaq	(%rax,%rdx), %rsi
	addq	$-1, %rsi
	sarq	%rsi
	movq	(%rdi,%rsi,8), %rdx
	cmpq	%r8, %rdx
	jae	.LBB4_28
# %bb.25:                               #   in Loop: Header=BB4_24 Depth=2
	movq	%rdx, (%rdi,%rax,8)
	movq	%rsi, %rax
	cmpq	%r9, %rsi
	jg	.LBB4_24
	.p2align	4, 0x90
.LBB4_26:                               #   in Loop: Header=BB4_17 Depth=1
	movq	%r8, (%rdi,%rsi,8)
	testq	%r9, %r9
	leaq	-1(%r9), %r9
	jne	.LBB4_17
	jmp	.LBB4_29
	.p2align	4, 0x90
.LBB4_27:                               #   in Loop: Header=BB4_17 Depth=1
	movq	%rax, %rsi
	movq	%r8, (%rdi,%rsi,8)
	testq	%r9, %r9
	leaq	-1(%r9), %r9
	jne	.LBB4_17
	jmp	.LBB4_29
.LBB4_28:                               #   in Loop: Header=BB4_17 Depth=1
	movq	%rax, %rsi
	movq	%r8, (%rdi,%rsi,8)
	testq	%r9, %r9
	leaq	-1(%r9), %r9
	jne	.LBB4_17
.LBB4_29:
	retq
.Lfunc_end4:
	.size	_ZSt11__make_heapIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_, .Lfunc_end4-_ZSt11__make_heapIPmN9__gnu_cxx5__ops15_Iter_less_iterEEvT_S4_RT0_
	.cfi_endproc
                                        # -- End function
	.section	.text.startup,"ax",@progbits
	.p2align	4, 0x90         # -- Begin function _GLOBAL__sub_I_sgl.v1.class.array.cpp
	.type	_GLOBAL__sub_I_sgl.v1.class.array.cpp,@function
_GLOBAL__sub_I_sgl.v1.class.array.cpp:  # @_GLOBAL__sub_I_sgl.v1.class.array.cpp
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	$_ZStL8__ioinit, %edi
	callq	_ZNSt8ios_base4InitC1Ev
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	movl	$_ZStL8__ioinit, %esi
	movl	$__dso_handle, %edx
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	jmp	__cxa_atexit            # TAILCALL
.Lfunc_end5:
	.size	_GLOBAL__sub_I_sgl.v1.class.array.cpp, .Lfunc_end5-_GLOBAL__sub_I_sgl.v1.class.array.cpp
	.cfi_endproc
                                        # -- End function
	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	__dso_handle
	.type	_ZN3sgl2v124instrumented_base_countsE,@object # @_ZN3sgl2v124instrumented_base_countsE
	.bss
	.globl	_ZN3sgl2v124instrumented_base_countsE
	.p2align	4
_ZN3sgl2v124instrumented_base_countsE:
	.zero	64
	.size	_ZN3sgl2v124instrumented_base_countsE, 64

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"n"
	.size	.L.str, 2

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"copy"
	.size	.L.str.1, 5

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"assignment"
	.size	.L.str.2, 11

	.type	.L.str.3,@object        # @.str.3
.L.str.3:
	.asciz	"destructor"
	.size	.L.str.3, 11

	.type	.L.str.4,@object        # @.str.4
.L.str.4:
	.asciz	"default_constructor"
	.size	.L.str.4, 20

	.type	.L.str.5,@object        # @.str.5
.L.str.5:
	.asciz	"equality"
	.size	.L.str.5, 9

	.type	.L.str.6,@object        # @.str.6
.L.str.6:
	.asciz	"comparison"
	.size	.L.str.6, 11

	.type	.L.str.7,@object        # @.str.7
.L.str.7:
	.asciz	"construction"
	.size	.L.str.7, 13

	.type	_ZN3sgl2v131instrumented_base_counter_namesE,@object # @_ZN3sgl2v131instrumented_base_counter_namesE
	.data
	.globl	_ZN3sgl2v131instrumented_base_counter_namesE
	.p2align	4
_ZN3sgl2v131instrumented_base_counter_namesE:
	.quad	.L.str
	.quad	.L.str.1
	.quad	.L.str.2
	.quad	.L.str.3
	.quad	.L.str.4
	.quad	.L.str.5
	.quad	.L.str.6
	.quad	.L.str.7
	.size	_ZN3sgl2v131instrumented_base_counter_namesE, 64

	.type	.L.str.8,@object        # @.str.8
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str.8:
	.asciz	"median"
	.size	.L.str.8, 7

	.type	.L.str.9,@object        # @.str.9
.L.str.9:
	.asciz	"\t\t"
	.size	.L.str.9, 3

	.type	.L.str.10,@object       # @.str.10
.L.str.10:
	.asciz	"avg"
	.size	.L.str.10, 4

	.type	.L.str.11,@object       # @.str.11
.L.str.11:
	.asciz	"dev"
	.size	.L.str.11, 4

	.type	.L.str.12,@object       # @.str.12
.L.str.12:
	.asciz	"\t"
	.size	.L.str.12, 2

	.section	.init_array,"aw",@init_array
	.p2align	3
	.quad	_GLOBAL__sub_I_sgl.v1.class.array.cpp

	.ident	"clang version 7.0.1 (Fedora 7.0.1-6.fc29)"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym __gxx_personality_v0
	.addrsig_sym _GLOBAL__sub_I_sgl.v1.class.array.cpp
	.addrsig_sym _Unwind_Resume
	.addrsig_sym _ZStL8__ioinit
	.addrsig_sym __dso_handle
	.addrsig_sym _ZSt4cout
