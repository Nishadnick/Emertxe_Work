#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title: 23_print_fifth_line.sh
Description:
1.Pass the filename through command line.
2.Check if file is already exist or not and check the contents are available or not.
3.If the no. of lines is less than 5 then print the error.

Sample I/p :
./23_print_fifth_line.sh data.txt
Sample O/p : 
Fifth line of data.txt is 5th line
Documentation


#	start=$(($1+$2-1))								
#	lines=$(wc -l $3 | cut -d " " -f 1)				
#	echo "$(head -$start "$3" | tail -$2)"		

if [ $# -eq 1 ]
then
	if [ -e "$1" ]
	then
		if [ $(wc -l "$1" | cut -d " " -f 1) -ge 5 ]
		then
			echo "Fifth line of $1 is $(head -5 "$1" | tail -1)"
		else
			echo "Error : $1 is having only $(wc -l "$1" | cut -d " " -f 1) lines. So can’t print 5th line"
		fi
	else
		echo "Error : No such a file"
	fi
else
	echo "Error : Please pass the file name in command line"
fi




