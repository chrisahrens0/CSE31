	.data

prompt: .asciiz "Please enter an integer: "

	.text
	
main:	li 	$v0, 4
	la 	$a0, prompt 	#print prompt
	syscall
	
	li 	$v0, 5		#get input
	syscall
	move	$a0, $v0
	
	jal recursion
	
	move 	$a0, $v0
	
	j end
	
recursion:
	addi	$sp, $sp, -16
	
	sw	$ra, 0($sp)
	sw	$v0, 4($sp)
	
	bne 	$a0, 10, else1
	li	$v0, 2
	
	j	end_recur
	
else1:
	bne 	$a0, 11, else2
	addi 	$v0, $0, 1
	j 	end_recur
	
else2:
	sw	$a0, 8($sp)
	
	addi 	$a0, $a0, 2
	jal recursion		#call recursion(m+2)
	
	sw	$v0, 12($sp)
	
	lw	$a0, 8($sp)
	addi	$a0, $a0, 1
	jal recursion		#call recursion(m+1)
	
	lw	$t0, 12($sp)
	lw	$t1, 8($sp)
	add 	$v0, $v0, $t0
	add	$v0, $v0, $t1
	
	j	end_recur
	
end_recur:
	lw $ra 0($sp)
	#lw $a0 4($sp)
	
	addi $sp, $sp, 16	# Pop stack frame 
	jr $ra

end:
	li      $v0, 1		
	syscall			
	li      $v0, 10		
	syscall	
	