#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 09_fibonacci.sh
Description:
1. Read a number from user and validate only numbers are entered
2. Remember n is not number of elements to print
3. Its the boundary of elements to print.
Sample I/p : Enter a Number : 4
Sample O/p : 
Documentation

# 0 1 1 2 3 5 8 13 21 34 55
read -p "enter a number limit: " limit #25
declare -a arr=(0 1 1)

if [ $limit -lt 2 ]
then
	echo "Fibonachi Series: ${a[0]}, ${a[1]}, ${a[2]}"
fi
if [ $limit -gt 2 ]
then
	for i in `seq $limit`
	do
		while [ "${arr[$i]}" -lt "$limit" ]
		do
			echo -n ", ${arr[$i]}"
			arr[$((i+2))] = ${arr[$((i+1))]} + ${arr[$i]}
			i=`expr $i + 1`
		done
	done	
else
	echo "please enter valid number"
fi