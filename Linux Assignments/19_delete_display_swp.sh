#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title: 19_delete_display_swp.sh
Description:
1. Find and delete all .swp files (Temporary vi files).
2. If command-line directories are passed delete only from that directories
3. If no arguments passed display from entire ~/ directory
4. If no file present show a message.

Sample I/p :
./19_delete_display_swp.sh ~/dir5
Sample O/p :
1)./19_delete_display_swp.sh ~/dir5
the no. of .swp files found is  2
swp file found :
/home/nishu/dir5/file9.swp
/home/nishu/dir5/file8.swp

2)./19_delete_display_swp.sh ~/dir5
the no. of .swp files found is  0
No swp files found in /home/nishu/dir5


Documentation

location=~/					#setting the default location

if [ $# -eq 0 ]										#chking if no directory is passed then default "~/"
then
	result=$(find $location -name "*.swp"|wc -l)	#counting how many files are found from ~/
	#echo "the no. of .swp files found is  $result"					#if files found then "swp file found :"
	if [ $result -ne 0 ]
	then
		echo "swp file found :"
		echo "$(find $location -name "*.swp")"
	else
		echo "No swp files found in $location"		#else no files found
	fi
elif [ ${#@} -eq 1 ]								#checking if any argument i passed
then

	if [ -d $1 ]									#chk if its a directory
	then
		location=$1
		result=$(find $location -name "*.swp"|wc -l)		#counting how many files are found
	#	echo "the no. of .swp files found is  $result"
		if [ $result -ne 0 ]
		then
			echo "swp file found :"
			echo "$(find $location -name "*.swp")"			#find and display
	#		cd ~/
			find $location -name "*.swp" -type f -delete	#find and delete after checking if its a file of .swp
		else
			echo "No swp files found in $location"
		fi
	else
		echo "Error : $1 no such a file or directorie"		#error if the argument is invalid
	fi
fi


	

