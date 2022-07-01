#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title:  21_say_hello.sh
Description:
1. The script should run as soon as you log-on to system
2. Print greetings based on time as follows.
3. "Good morning" (5 AM – 12 PM)
4. "Good noon" (12 PM – 1 PM)
5. "Good afternoon" (2 PM – 5 PM)
6. "Good evening" (5PM – 9 PM)
7. “Good night” (9 PM – 5 AM)


Sample I/p :
1. ./21_say_hello.sh

Sample O/p :
Good Morning user, Have nice day!
This is Thursday 08 in June of 2017 (10:44:10 AM)

Documentation

#info=$(date|cut -d " " -f 5)
#mins=`echo "$time"|cut -d ":" -f 2`
#hrs=$(echo "$time"|cut -d ":" -f 1)
#This file name with absolute path was added in the .bashrc file

day=$(date +%A)
daynum=$(date +%d)
month=$(date +%B)			#collectively using %specifiers according to the data required
year=$(date +%Y)
format=$(date +%H:%M:%S)
hrs=$(date +%H)
period=$(date|cut -d " " -f 6)

if [ $period = 'AM' ] || [ $period = 'am' ]
then
	if [ $hrs -eq 12 ]
	then										#bifercating between AM and PM
		hrs=0									#as with AM the Hour clock is unchanged
	else										
		hrs=$(date +%H)
	fi
elif [ $period = 'PM' ] || [ $period = 'pm' ]
then
	if [ $hrs -eq 12 ]
	then
		hrs=12
	else
		hrs=$(($(date +%H)+12))					#but with PM the the Hour clock doubles-up and 12hrs is added
	fi
fi

time=$(date +%H%M%S)							#printing the time intentionally 'as a big integer'
echo "$time"
#echo "time is $time and mins is $mins and hours  $hrs"		#the comparing number is also the time slot

if [ "$time" -ge 050000 ] && [ "$time" -le 115959 ]		#the big integer value aids us with numerical comparisons
then
	echo "Good morning user, Have nice day!"
elif [ "$time" -ge 120000 ] && [ "$time" -le 135959 ]	#with numerical comparison operators
then
	echo "Good noon user, Have nice day!"
elif [ "$time" -ge 140000 ] && [ "$time" -le 165959 ] 	#the options become easy to use
then
	echo "Good afternoon user, Have nice day!"
elif [ "$time" -ge 170000 ] && [ "$time" -le 205959 ] 	#could've also used the switch case
then
	echo "Good evening user, Have nice day!"
elif [ "$time" -ge 210000 ] || [ "$time" -le 045959 ] 	# OR condition is used cz anything works
then
	echo "Good night user, Good night!"
fi

echo "This is $day $daynum in $month of $year ($format $period)"		#tailored for the requirement




	

