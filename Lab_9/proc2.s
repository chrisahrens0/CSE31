        .data
str1: .asciiz "Greater than\n"
str2: .asciiz "Less than or equal to\n"

	.text
	
	# Tps 2 part 1
	addi $s0, $zero, -15 #1
	
	li $v0, 5	#read value from user
	syscall
	move $s1, $v0	

	# Tps 2 part 2
	slt $t0, $s0, $s1 #2
	
	# Tps 2 part 3
	beq $t0, $zero, LEEQ	#3
	
	# Tps 2 part 4
	j GRT	#4

GRT:	li $v0, 4 
	la $a0, str1 
	syscall 	
	j END

LEEQ:	li $v0, 4 
	la $a0, str2 
	syscall 	
	j END
			
END:	li $v0, 10		
	syscall

