#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title:  08_operator_dependent.sh
Description:
1. Pass a string through command line, must end with a operator symbol.
2. Number can be any length but must end with an operator character
3. Always do left to right operations.
4. If 8312- passed do 8-3-1-2 = 2
Sample I/p :  
Sample O/p :  
Documentation

argument=("$@")										#reading input number along with some arithmatic sign
offsign=${argument: -1}								#offsign is the arithmatic sign we offset
number=${argument::-1}								#extracting  valid number

for i in $(seq $((${#number}-1)) -1 0)
do
	digit=$((number%10))
	num_arr[$i]=$digit
	number=$((number/10))
done
#echo "new array  ${num_arr[@]}"
if [ $# -eq 1 ] && [[ "$number" =~ ^[[:digit:]]+$ ]]
then 
	
	case $offsign in
		+)
			
			answer=0
			for i in ${num_arr[@]}
			do
				answer=$(($answer$offsign$i))
			done
			echo "Sum of digits = $answer"
		;;
		-)
			
			answer=$((${num_arr[0]}*2))
			for i in ${num_arr[@]}
			do
				answer=$(($answer-$i))
			done
			echo "Subtraction of digits = $answer"
		;;
		x)
		
			answer=1
			for i in ${num_arr[@]}
			do
	#			answer=`echo "$(($answer*$i))"| bc -l`
				answer=$((answer*i))
			done
			echo "Multiplication of digits $answer"
		;;
		/)
			
			answer=1
			for i in ${num_arr[@]}
			do
				answer=`echo "scale=2; ($answer/$i)"| bc`
			done
			echo "Division of digits = $answer"
		;;
		*)
			echo "Error: Operator missing or invalid operator, please pass operator as last digit (+,-,x,/)"
	esac
else
	echo "Error : Please pass the arguments through CL."
	echo "Usage : ./09_operator_dependent.sh 2345+"
fi
#echo "final $answer"



		