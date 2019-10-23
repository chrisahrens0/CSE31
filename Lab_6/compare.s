	.data
n:	.word 25
str1: .asciiz "Less than\n"
str2: .asciiz "Less than or equal to\n"
str3: .asciiz "Greater than\n"
str4: .asciiz "Greater than or equal to\n"

	.text
main:	li 	$v0, 5			#scan integer, code 5
	syscall
	lw 	$t0, n			#load $t0 with n
	move 	$t1, $v0		#load $t1 with user input
	
	#slt 	$t2, $t0, $t1
	#beq	$t1, $t0, GreaterThanEqual
	#beq 	$t2, $0, LessThan
	#slt	$t2, $t1, $t0
	#beq	$t2, $0, GreaterThanEqual		#found more efficient way, outdated code
	
	#slt	$t2, $t1, $t0
	#beq	$t2, $0, GreaterThanEqual		#questions 5, 6
	#j	LessThan
	
	slt	$t2, $t0, $t1				#questions 7, 8
	beq	$t2, $0, LessThanEqual
	j	GreaterThan
	
	j	finish
	
LessThan:
	li 	$v0, 4
	la 	$a0, str1
	syscall
	j 	finish
	
LessThanEqual:
	li 	$v0, 4
	la 	$a0, str2
	syscall
	j 	finish
	
GreaterThan:
	li 	$v0, 4
	la 	$a0, str3
	syscall
	j 	finish
	
GreaterThanEqual:
	li 	$v0, 4
	la 	$a0, str4
	syscall
	j 	finish
	
finish:
	li	$v0, 10
	syscall
	