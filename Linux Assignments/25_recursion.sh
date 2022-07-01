#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title: 25_recursion.sh
Description:
1. We pass command-line arguments to script.
2. Script call function with same arguments.
3. Regardless of how many arguments are passed. You are allowed to echo
only the first positional argument (echo $1).

Sample I/p :
1. ./25_recursion.sh How are you? I am fine
Sample O/p :
How
are
you?
I
am
fine

Documentation

strs=($@)					#CLA's are collected in an aray of strings

#strs=(${strs[@]:1})

if [ $# -eq 0 ]		#counting the updated number of elements present
then
	echo "Error : Pass the arguments through command line."
else
	function print1()					#declaring fucntion named print1()
	{
		while [ ${#strs[@]} -ne 0 ]		#array size decreasing
		do
			echo "$1"					#You are allowed to echo only the first positional argument (echo $1).
		
			strs=(${strs[@]:1})		#using offset method without the 3rd field to print remaining chars
		
			print1 ${strs[@]}			#Script call function with same arguments.
		done
	}
	print1 ${strs[@]}
fi
