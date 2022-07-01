#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 02_pattern.sh
Description:
			1. Read a number from user
			2. Check 2 < number < 2^5
			3. Create a pattern as mentioned above
Sample I/p : Enter a Number : 4
Sample O/p : 
1 
2 3 
4 5 6 
7 8 9 10 
Documentation
read -p "Enter a Number : " rows
#echo "The Entered Number is $rows"
let val=0
let limit=$((2**5))								# val is indipendent of the iteration 
if [ "$rows" -lt $limit ] && [ "$rows" -ge 2 ]	#hence it prints its values continuously
then
	for i in `seq $rows`
	do
		for cols in `seq $i`
		do	
			val=$(($val+1))
			echo -n "$val "
		done
		echo ""
	done
else
	echo "Error : Invalid input"			#Error incase of invaild Input
fi