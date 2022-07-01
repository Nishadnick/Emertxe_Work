#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 04_calculator.sh
Description:
			User must provide two numbers and operator through command-line
			Based on input do the operation and display the output.
			Use case to handle multiple operations
			Use expr or bc commands
			
Sample I/p : 
Sample O/p : 

Documentation

if [ $# -eq 0 ]
then						#chk if command line args are ven passed or not
	echo "Error : Please pass the arguments through command line."
	echo "Usage:./04_arithmatic_calc 2.3 + 6.7"
elif [ $# -eq 3 ] && [[ "$1" =~ ^-?[0-9]+([.][0-9]+)?$ ]] && [[ "$3" =~ ^-?[0-9]+([.][0-9]+)?$ ]]
	then
			# ^-?[0-9]+([.][0-9]+)?$ ->this whole range of charchter checks for real nos and integers, be it +ve/-ve 
	case "$2" in 
			+)
				ans=`echo "scale=2; $1+$3" | bc`
				echo "$1 $2 $3 = $ans"
			;;
			-)
				ans=`echo "scale=2; $1-$3" | bc`
				echo "$1 $2 $3 = $ans"
			;;										#converting and allowinfg real numbers to be apart of the calcs
			/)
				ans=`echo "scale=2; $1/$3" | bc`
				echo "$1 $2 $3 = $ans"
			;;
			x|*)
				ans=`echo "scale=2; $1*$3" | bc`
				echo "$1 $2 $3 = $ans"
			;;
	esac
	
else				# error if 3 args are not passed
	#echo "Error:Please pass 3 arguments."
	echo "Error:Invalid number of arguments"
	echo "Usage:./04_arithmatic_calc 2.3 + 6.7"
fi
