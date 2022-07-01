#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 10_string_length.sh
Description:
1. Pass some names or strings from command-line.
2. Print all the string lengths one-by-one.
3. Number of argument may vary.
Sample I/p : Enter numbers in command line : ./10_string_length.sh cat jerry ronaldo govinda jiggnesh
Sample O/p : 
Length of string (cat) - 3
Length of string (jerry) - 5
Length of string (ronaldo) - 7
Length of string (govinda) - 7
Length of string (jiggnesh) - 8

Documentation

str_list=("$@")				#taking all values into array

if [ $# -gt "0" ]
then
	for i in 0 `seq $((${#str_list[@]} - 1))`
	#$(seq $((${#str_list[@]} - 1)) -1 0)
	do
		#echo "what is : ${str_list[i]}"
		echo "Length of string (${str_list[i]}) - ${#str_list[i]}"
	done
else
	echo "Error : Please pass the arguments through command-line."				#error incase of invalid inputs
fi