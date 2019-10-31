		.data
x:		.word 5
y:		.word 10
	
		.text
	
MAIN:
	# all return values in $v0, $v1
	la $t0, x
	lw $s0, 0($t0)		# x = $s0
	la $t0, y
	lw $s1, 0($t0)		# y = $s1
	
	add $a0, $s0, $0		# m = x
	add $a1, $s1, $0		# n = y
	jal SUM
	
	
	add $s1, $s0, $s1	# y = y + x
	
	add $v0, $v0, $s1
	
	move $a0, $v0
	
	li $v0, 1
	syscall
	j END


SUB:
	# a = $a0, b = $a1
	# backup these as well
	
	#addi $sp, $sp -4
	#sw $a0, 0($sp)
	
	#addi $sp, $sp -4
	#sw $a1, 0($sp)
	
	sub $v0, $a1, $a0
	
	#lw $a1, 0($sp)
	#addi $sp, $sp 4
	
	#lw $a0, 0($sp)
	#addi $sp, $sp 4 
	
	jr $ra


SUM:
	# m = $a0, n = $a1
	# always backup
	# backup $s0 and $s1, store p -> $s0, q ->$s1
	
	addi $sp, $sp -4	#backup $s0
	sw $a0, 0($sp)
	
	addi $sp, $sp -4
	sw $a1, 0($sp)		#backup $s1
	
	# p = $s0
	
	addi $a0, $a0 1
	addi $a1, $a1 1
	
	addi $sp, $sp -4
	sw $ra, 0($sp)
	jal SUB
	lw $ra, 0($sp)
	addi $sp, $sp 4
	
	add $t0, $v0, $0
	
	#subi $s0, $s0 1
	#subi $s1, $s1 1
	
	#move $s3, $s0
	#move $s0, $s1
	#move $s1, $s3
	
	# q = $s1
	
	move $a3, $a0
	move $a0, $a1
	move $a1, $a3
	
	subi $a0, $a0, 1
	subi $a1, $a1, 1
	
	
	addi $sp, $sp -4
	sw $ra, 0($sp)
	jal SUB
	lw $ra, 0($sp)
	addi $sp, $sp 4
	
	
	
	add $t0, $t0, $v0
	move $v0, $t0
	
	lw $a1, 0($sp)		#load backup $s1
	addi $sp, $sp 4
	
	lw $a0, 0($sp)		#load backup $s0
	addi $sp, $sp 4
	
	jr $ra
	
END:
	li $v0, 10
	syscall
	