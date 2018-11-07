	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_mallocIntArray
	.p2align	4, 0x90
_mallocIntArray:                        ## @mallocIntArray
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$12, %esp
	movl	8(%ebp), %ebx
	movl	$8, (%esp)
	calll	_malloc
	movl	%eax, %esi
	movl	%ebx, (%esi)
	leal	(,%ebx,4), %edi
	movl	%edi, (%esp)
	calll	_malloc
	movl	%eax, 4(%esi)
	testl	%ebx, %ebx
	jle	LBB0_2
## BB#1:
	movl	4(%esi), %eax
	movl	%edi, 4(%esp)
	movl	%eax, (%esp)
	calll	___bzero
LBB0_2:
	movl	%esi, %eax
	addl	$12, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl

	.globl	_freeIntArray
	.p2align	4, 0x90
_freeIntArray:                          ## @freeIntArray
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	calll	L1$pb
L1$pb:
	popl	%eax
	movl	8(%ebp), %esi
	testl	%esi, %esi
	je	LBB1_8
## BB#1:
	movl	(%esi), %ecx
	testl	%ecx, %ecx
	je	LBB1_8
## BB#2:
	cmpl	$0, 4(%ecx)
	je	LBB1_8
## BB#3:
	movl	(%esi), %eax
	cmpl	$0, (%eax)
	leal	4(%eax), %eax
	jle	LBB1_7
## BB#4:
	movl	(%esi), %edx
	leal	4(%edx), %ecx
	xorl	%edi, %edi
	.p2align	4, 0x90
LBB1_5:                                 ## =>This Inner Loop Header: Depth=1
	movl	(%eax), %eax
	movl	$0, (%eax,%edi,4)
	incl	%edi
	cmpl	(%edx), %edi
	movl	%ecx, %eax
	jl	LBB1_5
## BB#6:
	movl	%ecx, %eax
LBB1_7:
	subl	$12, %esp
	pushl	(%eax)
	calll	_free
	addl	$16, %esp
	movl	(%esi), %eax
	movl	$0, 4(%eax)
	movl	(%esi), %eax
	movl	$0, (%eax)
	subl	$12, %esp
	pushl	(%esi)
	calll	_free
	addl	$16, %esp
	movl	$0, (%esi)
	popl	%esi
	popl	%edi
	popl	%ebp
	retl
LBB1_8:
	movl	L___stderrp$non_lazy_ptr-L1$pb(%eax), %ecx
	leal	L_.str-L1$pb(%eax), %eax
	pushl	(%ecx)
	pushl	$1
	pushl	$30
	pushl	%eax
	calll	_fwrite$UNIX2003
	addl	$4, %esp
	pushl	$-1
	calll	_exit
	addl	$12, %esp

	.globl	_readIntArray
	.p2align	4, 0x90
_readIntArray:                          ## @readIntArray
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$28, %esp
	calll	L2$pb
L2$pb:
	popl	%eax
	movl	8(%ebp), %esi
	movl	(%esi), %edi
	testl	%edi, %edi
	jle	LBB2_3
## BB#1:
	incl	%edi
	xorl	%ebx, %ebx
	leal	L_.str.1-L2$pb(%eax), %ecx
	movl	%ecx, -20(%ebp)         ## 4-byte Spill
	leal	L_.str.2-L2$pb(%eax), %eax
	movl	%eax, -16(%ebp)         ## 4-byte Spill
	.p2align	4, 0x90
LBB2_2:                                 ## =>This Inner Loop Header: Depth=1
	movl	-20(%ebp), %eax         ## 4-byte Reload
	movl	%eax, (%esp)
	calll	_printf
	leal	-24(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax         ## 4-byte Reload
	movl	%eax, (%esp)
	calll	_scanf
	movl	-24(%ebp), %eax
	movl	4(%esi), %ecx
	movl	%eax, (%ecx,%ebx)
	decl	%edi
	addl	$4, %ebx
	cmpl	$1, %edi
	jg	LBB2_2
LBB2_3:
	addl	$28, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl

	.globl	_swap
	.p2align	4, 0x90
_swap:                                  ## @swap
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	movl	12(%ebp), %eax
	movl	8(%ebp), %ecx
	movl	(%ecx), %edx
	movl	(%eax), %esi
	movl	%esi, (%ecx)
	movl	%edx, (%eax)
	popl	%esi
	popl	%ebp
	retl

	.globl	_sortIntArray
	.p2align	4, 0x90
_sortIntArray:                          ## @sortIntArray
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$12, %esp
	movl	8(%ebp), %esi
	movl	(%esi), %eax
	movl	%eax, -20(%ebp)         ## 4-byte Spill
	xorl	%eax, %eax
	.p2align	4, 0x90
LBB4_2:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB4_3 Depth 2
                                        ##       Child Loop BB4_4 Depth 3
	incl	%eax
	movl	-20(%ebp), %edi         ## 4-byte Reload
	movl	%eax, -24(%ebp)         ## 4-byte Spill
	subl	%eax, %edi
	movl	$0, -16(%ebp)           ## 4-byte Folded Spill
	xorl	%ebx, %ebx
	jmp	LBB4_3
	.p2align	4, 0x90
LBB4_6:                                 ##   in Loop: Header=BB4_3 Depth=2
	leal	(%edx,%ecx), %eax
	leal	-4(%edx,%ecx), %ecx
	subl	$8, %esp
	pushl	%eax
	pushl	%ecx
	calll	_swap
	addl	$16, %esp
	movl	$1, -16(%ebp)           ## 4-byte Folded Spill
LBB4_3:                                 ##   Parent Loop BB4_2 Depth=1
                                        ## =>  This Loop Header: Depth=2
                                        ##       Child Loop BB4_4 Depth 3
	leal	(,%ebx,4), %ecx
	.p2align	4, 0x90
LBB4_4:                                 ##   Parent Loop BB4_2 Depth=1
                                        ##     Parent Loop BB4_3 Depth=2
                                        ## =>    This Inner Loop Header: Depth=3
	cmpl	%edi, %ebx
	jge	LBB4_1
## BB#5:                                ##   in Loop: Header=BB4_4 Depth=3
	movl	4(%esi), %edx
	movl	(%edx,%ecx), %eax
	incl	%ebx
	cmpl	4(%edx,%ecx), %eax
	leal	4(%ecx), %ecx
	jle	LBB4_4
	jmp	LBB4_6
	.p2align	4, 0x90
LBB4_1:                                 ##   in Loop: Header=BB4_2 Depth=1
	cmpl	$1, -16(%ebp)           ## 4-byte Folded Reload
	movl	-24(%ebp), %eax         ## 4-byte Reload
	je	LBB4_2
## BB#7:
	addl	$12, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl

	.globl	_printIntArray
	.p2align	4, 0x90
_printIntArray:                         ## @printIntArray
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$28, %esp
	calll	L5$pb
L5$pb:
	popl	%eax
	movl	8(%ebp), %ecx
	movl	(%ecx), %edi
	testl	%edi, %edi
	jle	LBB5_5
## BB#1:
	leal	-1(%edi), %ebx
	xorl	%esi, %esi
	leal	L_.str.2-L5$pb(%eax), %ecx
	movl	%ecx, -20(%ebp)         ## 4-byte Spill
	leal	L_.str.3-L5$pb(%eax), %eax
	movl	%eax, -16(%ebp)         ## 4-byte Spill
	.p2align	4, 0x90
LBB5_2:                                 ## =>This Inner Loop Header: Depth=1
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	movl	(%eax,%esi,4), %eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax         ## 4-byte Reload
	movl	%eax, (%esp)
	calll	_printf
	cmpl	%ebx, %esi
	jge	LBB5_4
## BB#3:                                ##   in Loop: Header=BB5_2 Depth=1
	movl	-16(%ebp), %eax         ## 4-byte Reload
	movl	%eax, (%esp)
	calll	_printf
LBB5_4:                                 ##   in Loop: Header=BB5_2 Depth=1
	incl	%esi
	cmpl	%esi, %edi
	jne	LBB5_2
LBB5_5:
	addl	$28, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	subl	$20, %esp
	calll	L6$pb
L6$pb:
	popl	%esi
	leal	L_.str.4-L6$pb(%esi), %eax
	movl	%eax, (%esp)
	calll	_printf
	leal	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	L_.str.2-L6$pb(%esi), %eax
	movl	%eax, (%esp)
	calll	_scanf
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	calll	_mallocIntArray
	movl	%eax, -8(%ebp)
	movl	%eax, (%esp)
	calll	_readIntArray
	movl	-8(%ebp), %eax
	movl	%eax, (%esp)
	calll	_sortIntArray
	movl	$91, (%esp)
	calll	_putchar
	movl	-8(%ebp), %eax
	movl	%eax, (%esp)
	calll	_printIntArray
	leal	L_str-L6$pb(%esi), %eax
	movl	%eax, (%esp)
	calll	_puts
	leal	-8(%ebp), %eax
	movl	%eax, (%esp)
	calll	_freeIntArray
	xorl	%eax, %eax
	addl	$20, %esp
	popl	%esi
	popl	%ebp
	retl

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Invalid pointer found, Error.\n"

L_.str.1:                               ## @.str.1
	.asciz	"Enter int: "

L_.str.2:                               ## @.str.2
	.asciz	"%d"

L_.str.3:                               ## @.str.3
	.asciz	", "

L_.str.4:                               ## @.str.4
	.asciz	"Enter length: "

L_.str.5:                               ## @.str.5
	.asciz	"["

L_.str.6:                               ## @.str.6
	.asciz	"]\n"

L_str:                                  ## @str
	.asciz	"]"


	.section	__IMPORT,__pointers,non_lazy_symbol_pointers
L___stderrp$non_lazy_ptr:
	.indirect_symbol	___stderrp
	.long	0

.subsections_via_symbols
