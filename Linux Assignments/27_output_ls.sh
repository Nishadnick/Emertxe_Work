#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title: 27_output_ls.sh
Description:
1. This script will work like a ls command.
2. Don’t use ls command.
3. Pass any number of directories through command-line.
4. If no arguments passed, list current directory contents.

Sample I/p :
./27_ouput_ls.sh ~ ~/ECEP
Sample O/p :

/home/user:
Downloads Documents Desktop Music Pictures Public Videos
ECEP

Documentation

direcs=($@)						#colllecting all the directories in array


if [ $# -eq 0 ]
then
	echo "$PWD:"				#if CLA directories are not passed then just display current directory
	echo *						#using * to print all the contents
else
	
	for i in ${direcs[@]}
	do
							
		if [ -d $i ]			#checking if the supposed directory is an actual directory
		then
			cd $i				#changing to required directory, could'nt do it earlier cz it might not have been a directory
			echo "$PWD:"		#prints the current path
			echo *
		else
			echo "Cannot access ‘$i’ : No such a file or directory."
		fi
	done
fi