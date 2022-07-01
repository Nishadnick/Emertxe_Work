#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 03_real_add.sh
Description:
			Prompt the user to enter two numbers.
 			User can enter real numbers also.
 			Check if only numbers are entered.
 			Use bc command and piping to do.
Sample I/p : Enter the numbers to addition
10 20
Sample O/p : Answer is 30

Documentation
read -p "Enter the numbers to addition " num1 num2
		# ^-?[0-9]+([.][0-9]+)?$ ->this whole range of charchter checks for real nos and integers, be it +ve/-ve 
if [[ "$num1" =~ ^-?[0-9]+([.][0-9]+)?$ ]] && [[ "$num2" =~ ^-?[0-9]+([.][0-9]+)?$ ]] 
then										#to check if both numbers are valid entries
	#echo "real"
	answer=`echo "(($num1+$num2))" | bc -l`		#saving the calculation in a variable
	echo "Answer is $answer"					#cz i was not able to print the calculation directly in echo
else
	echo "Error : Please enter only integers or real numbers"
fi
