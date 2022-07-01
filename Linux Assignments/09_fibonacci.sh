#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 09_fibonacci.sh
Description:
			1. Read a number from user and validate only numbers are entered
			2. Remember n is not number of elements to print
			3. Its the boundary of elements to print.
Sample I/p : Enter a Number limit : 77
Sample O/p : Fibonacci Series: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
Documentation

# Actual Fibonacci series 0 1 1 2 3 5 8 13 21 34 55
read -p "Enter the limit: " limit #25
pos1=0
pos2=1
series=1
if [[ "${limit}" =~ ^[0-9]+$ ]]				#unsing the logic to eleminate unwanted inputs
then
	
	echo -n "$pos1"
	if [ $limit -le 2 -a $limit -gt 0 ]
	then
		echo ", $pos2, $(($pos1+$pos2))"			
	fi
	if [ $limit -gt 2 ]
	then
		for i in `seq $limit`
		do
			if [ $series -le $limit ]
			then
			
				echo -n ", $series"			#using 3 position method 
				series=$(($pos1+$pos2))		#printing 1st 2 values
				pos1=$pos2					#then swaping and incrementing values to print further series
				pos2=$series
			fi
		done	
		echo ""
	fi
else
	echo "Error : Please enter only positive numbers."			#error incase of invalid inputs
fi
