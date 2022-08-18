##########################################################################
# Created by: Chembu, Ashwin
# 1890044
# 14 November 2021
#
# Assignment: Lab 3:  ASCII-risks (Asterisks)
# CSE 012, Computer Systems and Assembly Language
# UC Santa Cruz, Fall 2021
#
# Description: In this lab, the user enters a number when the prompt asks for it. The program then generates a pyramid of asteriks with tabs between them in respect to the number that is entered. 
#
# Notes: This program is intended to be run from the MARS IDE.
##########################################################################
.text
#$t0: pyramid length
#$t1: row number
#$t2: star variable to count the number of stars printed
#t3: holds 1
#t4: printed row number
addi $t3, $t3, 1 	#sets $t3 to 1
j ask 			#jumps to prompt to ask for integer
toolow: 		#jumps here if value is too low
#prints out that input is invalid
li $v0, 4
la $a0, invalid
syscall
#prompt to get value
ask:
li $v0, 4
la $a0, prompt
syscall 
#get the pyramid length
li $v0, 5 
syscall
#store pyramid length in $t0
move $t0, $v0
sub $t0, $t0, $t3
#check if input is too low
ble $t0, $zero, toolow
#set $t4 to one 
addi $t4, $t4, 1
#print $t4(printed row number)
addi $v0, $zero, 1
add $a0, $t4, $zero
syscall
#prints a new line
li $v0, 4      
la $a0, newline       
syscall
#set row number(row)
addi $t1, $t1, 0
#create while loop
while1:
#initialize star variable 
	addi $t2, $t1, 1
#increments $t4(printed row number) by 1
	addi $t4, $t4, 1
	addi $v0, $zero, 1
	add $a0, $t4, $zero
	syscall
#while loop inside while loop
	while2: 
		#print tab
		addi $v0, $zero, 4
		la $a0, tab
		syscall
		#print stars
		addi $v0, $zero, 4
		la $a0, star
		syscall
		#check if last star
		beq $t2, $t3,skiptab
		skiptab:
		#subtracting 1 from star
		sub $t2, $t2, $t3 
		#check if inner while loop should be run
		bgt $t2, $zero, while2
	# adding 1 to row
	addi $t1, $t1, 1
	#print line break
	li $v0, 4      
	la $a0, newline       
	syscall
	#check if while loop needs to run again
	blt  $t1, $t0, while1 

.data
#holds strings to be printed
prompt: .asciiz "Enter the height of the pattern (must be greater than 0):\n"
invalid: .asciiz "Invalid Entry!\n"
tab: .asciiz "	"
star: .asciiz "*"
newline: .asciiz "\n"
