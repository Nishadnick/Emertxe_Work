#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title: 06_reverse.sh
Description:
Read a multi-digit number from user and check only if numbers are entered.
Reverse the number.
Its not just printing in reverse order
Extract each digit and reverse the number.
Sample I/p : ./06_reverse.sh 69427
Sample O/p : Reversed number is 72496
Documentation

num=$1
new_num=0
#arr=()
if [[ ${num} =~ ^[a-z][A-Z]+$ ]]			#checking for alphabets
then
	echo "Error: Enter only numbers"
elif [ $# -eq 0 ]
then
	echo "Error : No arguments passed"
elif [ "${num}" -le 0 ]
then
	echo "Error : Please pass positive number"
elif [ "${num}" -le 10 ]
then
	echo "Error: pass a multi-digit number"
elif [[ "${num}" =~ ^[0-9]+$ ]]				#unsing the logic to eleminate unwanted inputs
then
	#echo "digits in ${#num}"
	for i in `seq 0 $((${#num}-1))`
	do
		digit=$(($num%10))					#takng out the last digit
		newnum=$((newnum*10+$digit))		#immediately mul it by 10 and adding another new digit
		num=$(($num/10))					#new number if lesser by a power of 10
		#echo "$newnum"
	done
#	echo "the seres ${arr[@]}"
#	for i in `seq 0 $((${#arr[@]}-1))`
#	do
#		new_num=($((${arr[$i]}*10))+${arr[$(($i+1))]})
#	done
	echo "Reversed number is $newnum"
else
	echo "Error : Please enter integers."			#error incase of invalid inputs
fi
