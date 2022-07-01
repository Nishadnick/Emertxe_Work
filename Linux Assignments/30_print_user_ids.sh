#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title: 30_print_user_ids.sh
Description:
1. Fetch user-ids from the in /etc/passwd file.
2. Count the no.of user-ids present in given range.
3. User can change the range using command-line arguments.
4. Default is 500 - 10000


Sample I/p :
./30_user_ids.sh 
Sample O/p :
Total count of user ID between 500 to 10000 is: 2
Documentation

cd /etc
usrid=(`cat /etc/passwd|cut -d ":" -f 3`)		#extracting the userID field
#echo "user id's   ${usrid[@]}"

count=0											#required userID number is initially 0
if [ $# -eq 0 ]
then
	limit1=500
	limit2=10000								#these are the default limits
	for i in ${usrid[@]}
	do
		if [[ $i -ge $limit1 ]] && [[ $i -le $limit2 ]]
		then
			count=$((count+1))					#count for default limits
			
		fi
	done
	echo "Total count of user ID between 500 to 10000 is : $count"
elif [ $# -eq 2 ]
then
	if [ $1 -lt $2 ]							#if proper limits are provided
	then
	limit1=$1
	limit2=$2									#they are assigned
		for i in ${usrid[@]}
		do
			if [[ "$i" -ge "$limit1" ]] && [[ "$i" -le "$limit2" ]]
			then
				count=$((count+1))				#count for given limits
				
			fi
		done	
		echo "Total count of user ID between $1 to $2 is : $count"
	else 
		echo "Error : Invalid range. Please enter the valid range through CL." 	#incorrect range
	fi
else													#when incorrect args are provided
	echo "Error : Please pass 2 arguments through CL.		
Usage : ./30_user_ids.sh 100 200"
fi
