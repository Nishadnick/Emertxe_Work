#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title: 32_user_present.sh
Description:
1. Fetch user-names from the first field in /etc/passwd file.
2. Search given name in the list.

Sample I/p :
2. ./32_user_present.sh root

Sample O/p :
root is present

Documentation


usrname=(`cat /etc/passwd|cut -d ":" -f 1`)		#extracting usernames for /etc/passwd
flag=0
#echo "${usrname[@]}"
if [ $# -ne 1 ]
then
	echo "Error : Please pass the argument through command line."
else
	
	for i in ${usrname[@]}						#cycling through usernames
	do
		
		if [ $i = $1 ]
		then
			flag=1								#using flag method to confirm the search
			
			
		fi
	done	
	if [ "$flag" -eq 1 ]
	then
		echo "$1 is present"
	else										#flag decisions
		echo "$1 not present"
	fi
fi


