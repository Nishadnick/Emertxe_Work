#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 34_BMI.sh
Description:
			1. Ask user to enter two numbers
			2. Validate the numbers, whether only the numbers entered.
			3. User can enter real numbers also
			4. Use bc command and piping to do
Sample I/p :
Enter Height in Meters: 1.7
weight in Kgs: 70
Sample O/p : 
the BMI is 24.22
Normal

Documentation
#read -p "Enter the weight in Kg :" wt 
#read -p "Enter the height in meters :" ht
read -p "Enter the weight in Kg and height in meters :" wt ht

BMI=`echo "scale=2; $wt/(($ht*$ht))" | bc`				#formula to calculate BMI

if [ $(echo "$wt > 0" | bc -l) -eq "1" ] && [ $(echo "$ht > 0" | bc -l) -eq "1" ]  # we check if the height and weight is valid
then
	#echo "the BMI is $BMI"					
	if [ $(echo "$BMI > 0" | bc -l) -eq "1" ] && [ $(echo "$BMI < 18.5" | bc -l) -eq "1" ]
		then 
		echo "You are UNDERWEIGHT"
	elif [ $(echo "$BMI > 18.5" | bc -l) -eq "1" ] && [ $(echo "$BMI < 24.9" | bc -l) -eq "1" ]
		then 
		echo "You are NORMAL"								#different condition to bifercate the said BMI
	elif [ $(echo "$BMI > 25" | bc -l) -eq "1" ] && [ $(echo "$BMI < 29.9" | bc -l) -eq "1" ]
		then 
		echo "You are OVERWEIGHT"
	elif [ $(echo "$BMI > 30" | bc -l) -eq "1" ] && [ $(echo "$BMI < 100" | bc -l) -eq "1" ]
		then 
		echo "You are OBESE"
	else 	
		echo "Invalid Input"
	fi							#error incase of invalid inputs
else
	echo "Invalid input"
fi
