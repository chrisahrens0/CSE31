.data 

original_list: .space 100 
sorted_list: .space 100

str0: .asciiz "Enter size of list (between 1 and 25): "
str1: .asciiz "Enter one list element: \n"
str2: .asciiz "Content of original list: "
str3: .asciiz "Enter a key to search for: "
str4: .asciiz "Content of sorted list: "
strYes: .asciiz "Key found!"
strNo: .asciiz "Key not found!"



.text 

#This is the main program.
#It first asks user to enter the size of a list.
#It then asks user to input the elements of the list, one at a time.
#It then calls printList to print out content of the list.
#It then calls inSort to perform insertion sort
#It then asks user to enter a search key and calls bSearch on the sorted list.
#It then prints out search result based on return value of bSearch
main: 
	addi $sp, $sp -8
	sw $ra, 0($sp)
	li $v0, 4 
	la $a0, str0 
	syscall 
	li $v0, 5	#read size of list from user
	syscall
	move $s0, $v0
	move $t0, $0
	la $s1, original_list
loop_in:
	li $v0, 4 
	la $a0, str1 
	syscall 
	sll $t1, $t0, 2
	add $t1, $t1, $s1
	li $v0, 5	#read elements from user
	syscall
	sw $v0, 0($t1)
	addi $t0, $t0, 1
	bne $t0, $s0, loop_in
	move $a0, $s1
	move $a1, $s0
	
	jal inSort	#Call inSort to perform insertion sort in original list
	
	sw $v0, 4($sp)
	li $v0, 4 
	la $a0, str2 
	syscall 
	la $a0, original_list
	move $a1, $s0
	jal printList	#Print original list
	li $v0, 4 
	la $a0, str4 
	syscall 
	lw $a0, 4($sp)
	jal printList	#Print sorted list
	
	li $v0, 4 
	la $a0, str3 
	syscall 
	li $v0, 5	#read search key from user
	syscall
	move $a3, $v0
	lw $a0, 4($sp)
	jal bSearch	#call bSearch to perform binary search
	
	beq $v0, $0, notFound
	li $v0, 4 
	la $a0, strYes 
	syscall 
	j end
	
notFound:
	li $v0, 4 
	la $a0, strNo 
	syscall 
end:
	lw $ra, 0($sp)
	addi $sp, $sp 8
	li $v0, 10 
	syscall
	
	
#printList takes in a list and its size as arguments. 
#It prints all the elements in one line.
printList:
	#Your implementation of printList here	
	
	move $t1, $a0	#pass address of array as $a0
	add $s0, $0, $0	#printed 0 elements

printNextElement:
	slt $t0, $s0, $a1	#check if 
	beq $t0, $zero, printDone
	
	lw $a0, 0($t1)		#temp pointer to array
	addi $v0, $0, 1
	syscall
	
	
	addi $v0, $0, 11		#11 = char
	addi $a0, $0, 32		#32 ascii for space
	syscall
	
	addi $t1, $t1, 4
	addi $s0, $s0, 1	#printed 1 more element
	j printNextElement
	
printDone:
	addi $v0, $0, 4
	la $a0, original_list
	jr $ra
	
	
#inSort takes in a list and it size as arguments. 
#It performs INSERTION sort in ascending order and returns a new sorted list
#You may use the pre-defined sorted_list to store the result
inSort:
	#Your implementation of inSort here
	
	la $t1, original_list 	#fetch unsorted list
	la $t2, sorted_list	#fetch return loc
	li $t3, 1
	li $t4, 0		#create 2 iterators
	
sortNextWord:
	bgt $t3, $a1, reloadSorted
	lw $t5, ($t1)
	sw $t5, ($t2)
	addi $t1, $t1, 4	#move 1 word right
	addi $t2, $t2, 4	#move sorted over too
	addi $t3, $t3 1
	j sortNextWord

reloadSorted:
	la $t2, sorted_list	#reloads sorted list from original address
	
moveSorted:
	bge $t4, $a1, sortDone
	move $t6, $t4
	
sortWhile:
	mul $t5, $t6, 4
	add $t7, $t2, $t5
	ble $t6, 0, endWhile
	
	lw $t8, 0($t7)
	lw $t9, -4($t7)
	
	bge $t8, $t9, endWhile
	
	lw $t0, 0($t7)
	sw $t9, 0($t7)
	sw $t0, -4($t7)
	
	subi $t6, $t6, 1
	j sortWhile
	
endWhile:
	addi $t4, $t4, 1
	j moveSorted
	
sortDone:
	la $v0, sorted_list
	jr $ra

	
	
#bSearch takes in a list, its size, and a search key as arguments.
#It performs binary search RECURSIVELY to look for the search key.
#It will return a 1 if the key is found, or a 0 otherwise.
#Note: you MUST NOT use iterative approach in this function.
bSearch:
	#Your implementation of bSearch here
	
	# $a0 is address index of sorted list
	# $a1 gives size of array
	# $a3 is key
	
	addi $sp, $sp, -4
	sw $ra, 0($sp)		#put return address in stack
	
	bne $s3, $0, bIter
	li $s0, 0
	addi $s3, $0, 1
	
bIter:
	addi $sp, $sp, 12
	sw $a0, 0($sp)
	sw $a1, 4($sp)
	sw $a3, 8($sp)
	
	
	bgt $s0, $a1, bNotFound
	addi $t3, $0, 4
	add $t1, $a1, $s0
	sra $t1, $t1, 1
	mul $t3, $t3, $t1
	add $t0, $t3, $a0
	lw $t2, 0($t0)
	beq $t2, $a3, bkeyFound
	bgt $t2, $a3, bSearchL
	
	#jal bSearch1
	
	lw $a0, 0($sp)
	lw $a1, 4($sp)
	lw $a3, 8($sp)
	addi $sp, $sp, -12
	
	addi $s0, $t1, 1	#right side binary search
	j bSearch
	
bSearchL:
	addi $a1, $t1, -1
	j bSearch		#recur back to bSearch

bkeyFound:
	addi $v0, $0, 1
	j bEnd
	
bNotFound:
	li $v0, 0		#reset return vals before ending
bEnd:
	sw $ra, 0($sp)
	addi $sp, $sp, 4
	jr $ra
	
bSearch1:
	
	# a0 is address index of sorted list
	# $a1 gives size of array
	# $a3 is key
	
	addi $sp, $sp, -4
	sw $ra, 0($sp)
	
	