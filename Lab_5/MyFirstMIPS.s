.data
	# num:.word 0
.text
	
	# lw $s0, num($0)
	# move $t1, $s1
	# move $t0, $s0
	
	# add $t0, $s0, $0
	move $t0, $s0
	add $t1, $t0, 1
	add $t2, $t1, 2
	add $t3, $t2, 3
	add $t4, $t3, 4
	add $t5, $t4, 5
	add $t6, $t5, 6
	add $t7, $t6, 7
	
	li $v0, 1
	add $a0, $0, $t7
	syscall
	