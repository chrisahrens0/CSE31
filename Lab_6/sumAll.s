	.data	
input:		.asciiz "\nPlease enter a number: "
pos_sum:	.asciiz	"\nSum of positive numbers is: "
neg_sum:	.asciiz "\nSum of negative numbers is: "	
	
	.text
	
	li 	$t0, 0	#negative numbers
	li	$t1, 0	#positive numbers
	
askInput:
	li 	$v0, 4
	la 	$a0, input 	#ask for user input
	syscall
	li 	$v0, 5		#get input
	syscall
	move 	$s0, $v0
	beqz 	$s0, finish 	#check if 0 was entered, end program
	
	bltz 	$s0, neg_sums
	j	pos_sums
	
neg_sums:
	add	$t0, $t0, $s0
	j	iter

pos_sums:
	add	$t1, $t1, $s0
	j	iter
	
iter:
	j 	askInput
	
	
finish:
	li 	$v0, 4
	la 	$a0, pos_sum
	syscall
	move 	$a0, $t1
	li 	$v0, 1
	syscall
	
	li 	$v0, 4
	la 	$a0, neg_sum
	syscall
	move 	$a0, $t0
	li 	$v0, 1
	syscall
	
	li	$v0, 10
	syscall
	