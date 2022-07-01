#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 12_sorting.sh
Description:
			1. Pass numbers through command-line arguments.
			2. Provide a menu for user to choose ascending or descending.
			3. Show sorted array according to user choice.
Sample I/p : Enter numbers in command line : ./12_sorting.sh 5 7 9 -2 -4 1 -6 3 -8 0
Sample O/p : The sort
Documentation



total_arr=("$@")				#taking total values into array along with choice
#echo "total    ${total_arr[@]}"
#echo "total    ${total_arr[1]}"
for i in `seq 1 $((${#}-1))`
do
	num_list[$(($i-1))]="${total_arr[i]}"			#reducing the former array by making a new one
	
done

#echo "number list ${num_list[@]}"
#echo "The numbers are ${num_list[@]}"
#echo "the 4th number ${num_list[3]}"
#echo "Total is ${#num_list[@]}"
#echo "command line $#"
if [ $# -gt "0" ]
then
	if [ $1 = "-a" ]				#Ascending Order
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
				fi
			done
		done
		echo "Ascending order of array is ${num_list[@]}"
	elif [ $1 = "-d" ]			#Descending Order
	then
		for i in `seq $((${#num_list[@]} - 1))` 1				#running 2nd loop to sort remaining values turn by turn
		do
			for i in `seq $((${#num_list[@]} - 1))` 1			#running 1st loop to sort 1 value
			do
				if [ ${num_list[$i]} -gt ${num_list[$((i-1))]} ]
				then 
					temp=${num_list[$i]}
					num_list[$i]=${num_list[$((i-1))]}				#number swaping logic
					num_list[$((i-1))]=$temp
				fi
			done
		done
		echo "descending order of array is ${num_list[@]}"
	else
		echo "Error : Please pass the choice."
		echo "Usage : ./12_sorting -a/-d 4 23 5 6 3"
	fi													#errors for invalid inputs
else
	echo "Error : Please pass the argument through command line."
	echo "Usage : ./12_sorting -a/-d 4 23 5 6 3"
fi

