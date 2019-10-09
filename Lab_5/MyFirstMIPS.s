.data

.text
	
	# lw $s0, num($0)
	# move $t1, $s1
	# move $t0, $s0
	
	# add $t0, $s0, $0
	
	move $t0, $s0		# load s0 before this line executes
	add $t1, $t0, 1
	add $t2, $t1, 2
	add $t3, $t2, 3
	add $t4, $t3, 4
	add $t5, $t4, 5
	add $t6, $t5, 6
	add $t7, $t6, 7		# addition using constant increments
	
	li $v0, 1 		# load v0 with instruction to print int
	add $a0, $0, $t7	# load final number into a0 to be printed
	syscall			# print a0 using v0 specification
	li $v0, 10
	syscall			# announces end of program?
	