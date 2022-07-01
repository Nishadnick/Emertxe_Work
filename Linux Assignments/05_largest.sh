#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 05_largest.sh
Description:
			1.Using command-line, pass n arguments.
			2.Compare all these arguments and print the largest value.
			3.Print error in-case no arguments.%%%%%
			4.Number of arguments can vary every time.
Sample I/p : Enter numbers in command line : ./05_largest.sh 5 7 9 -2 -4 1
Sample O/p : The Largest value = 9
Documentation

num_list=("$@")				#taking all values into array

#echo "The numbers are ${num_list[@]}"
#echo "the 4th number ${num_list[3]}"
#echo "Total is ${#num_list[@]}"
#echo "command line $#"
if [ $# -gt "0" ]
then
	for i in `seq $((${#num_list[@]}-1))`				#running 2nd loop to sort remaining values turn by turn
	do
		for i in `seq $((${#num_list[@]}-1))`			#running 1st loop to sort 1 value
		do

			if [ ${num_list[$((i-1))]} -gt "${num_list[$i]}" ]
			then
				temp=${num_list[$((i-1))]}
				num_list[$((i-1))]=${num_list[i]}			#number swaping logic
				num_list[$i]=$temp
			#else
			#	i=`expr $i + 1`
			fi
		done
	done
	#echo "the sorted array num_list is: ${num_list[@]}"
	echo "Largest number is ${num_list[${#num_list[@]}-1]}"
else
	echo "Error: No arguments passed"				#error incase of invalid inputs
fi