#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 01_pattern.sh
Description:
			1.Read a number from user
			2.Check number is greater than 0
			3.Create the pattern given
Sample I/p : Enter a Number : 4
Sample O/p : 
1 
1 2 
1 2 3 
1 2 3 4
Documentation

read -p "Enter a Number : " rows		#reading the no. of columns to print
#echo "The Entered Number is $rows"		# and checking if values are valid
if [ $rows -gt 0 ]						
then
	for i in `seq $rows`
	do
		for cols in `seq $i`
		do
			echo -n "$cols "			#column will have same value till its max s
		done							#to the present value of row
		echo ""
	done
else
	echo "Error : Invalid Input"	#Error incase of invalid entry
fi
