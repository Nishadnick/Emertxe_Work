#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title: 18_largest_username.sh
Description:
1. Fetch user-names from the first field in /etc/passwd file.
2. Print longest and shortest name.

Sample I/p :
./18_largest_username.sh
Sample O/p :
1. ./18_largest_username.sh
The Longest Name is: speech-dispatcher
The Shortest Name is: lp

Documentation


if [ "$1" = "/etc/passwd" ]
then
	#users=(`cat /etc/passwd | cut -d ":" -f 1`)				#absolute path /etc/passwd
	users=(`cat $1 | cut -d ":" -f 1`)
	longest=${users[0]}
	shortest=${users[0]}									#initially assigning the first value
	for i in 0 `seq $((${#users[@]}-1))`					#to check length, looping with the index number
	do
		if [ "${#users[$i]}" -gt "${#longest}" ]			#replace if new name length is greater
		then
			longest=${users[$i]}
		fi
		if [ "${#users[$i]}" -lt "${#shortest}" ]			#replace if new name length is smaller
		then
			shortest=${users[$i]}
		fi
	done
	echo "Longest user name is $longest"
	echo "Shortest user name is $shortest"
else
	echo "Error : Invalid number of arguments, Please pass only user information file through CL"
fi

