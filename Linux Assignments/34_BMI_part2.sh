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
Sample I/p : Enter a Number : 4
Sample O/p : 
Documentation

read -p "Enter Height in Meters: " ht
read -p "weight in Kgs: " wt
bmi=0
#let total=$ht*$ht
#let bmi=$(echo "scale=2 ; $wt/$((ht*ht))" | bc)
#bmi=$(echo "scale=2 ; $wt/$((ht*ht))" | bc -l)
#read -p "Enter Height in Meters and Weight in Kgs: " ht wt
#let total=$ht*$ht
#let bmi=$(echo "scale=2 ; $wt/$((ht*ht))" | bc)
#bmi=$(echo "scale=2 ; $wt/$((ht*ht))" | bc -l)
BMI=`echo "scale=5; $wt/(($ht*$ht))" | bc`

echo "the BMI is $BMI"

case "$BMI" in
			"{0...18.5}")
			echo "your BIM is $BMI and you're Underweight"
			;;
			"{18.5...24.9}")
			echo "your BIM is $BMI and you're Normal"
			;;
			"{25...29.9}")
			echo "your BIM is $BMI and you're Overweight"
			;;
			"{30...100}")
			echo "your BIM is $BMI and you're Obese"
			;;
			*)
			echo "There is an error with your BMI. Please consult a Doctor immediately"
			;;
esac




#if [ `echo "$BMI -gt 0" | bc -l` -a `echo "$BMI -lt 18.5" | bc -l` ]
#	then 
#	echo "Underweight"
#elif [ `echo "$BMI -gt 18.5" | bc -l` -a `echo "$BMI -lt 24.9" | bc -l` ]
#	then 
#	echo "Normal"
#elif [ `echo "$BMI -gt 25" | bc -l` -a `echo "$BMI -lt 29.9" | bc -l` ]
#	then 
#	echo "Overweight"
#elif [ `echo "$BMI -gt 30" | bc -l` -a `echo "$BMI -lt 100" | bc -l` ]
#	then 
#	echo "Obease"
#else 	
#	echo "this is Error "
#fi



#if [ $((echo "$BMI -gt 0" | bc -l)) ] && [ $((echo "$BMI -lt 18.5" | bc -l)) ]
#	then 
#	echo "Underweight"
#elif [ $((echo "$BMI -gt 18.5" | bc -l)) ] && [ $((echo "$BMI -lt 24.9" | bc -l)) ]
#	then 
#	echo "Normal"
#elif [ $((echo "$BMI -gt 25" | bc -l)) ] && [ $((echo "$BMI -lt 29.9" | bc -l)) ]
#	then 
#	echo "Overweight"
#elif [ $((echo "$BMI -gt 30" | bc -l)) ] && [ $((echo "$BMI -lt 100" | bc -l)) ]
#	then 
#	echo "Obease"
#else 	
#	echo "Error"
#fi
