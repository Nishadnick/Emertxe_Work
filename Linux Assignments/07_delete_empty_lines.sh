#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title:  07_delete_empty_lines.sh
Description:
• Pass a filename through command-line.
• Delete all the empty lines from that file and save it back.
• If the line is empty with spaces or tabs you need to delete that line also.
• Use sed command to delete the empty lines.
Sample I/p :  1. ./07_delete_empty_lines.sh file.txt
Sample O/p : Empty lines are deleted.
After this all empty lines must be deleted from given file.
 
Documentation


if [ "$#" -ne 0 ]
then
	if [ -s $1 ]
	then
		#cat "$1" 								# ^ -> start of line  $ -> new line 
		sed -i '/^[[:space:]]*$/d' $1				# ssooo we cannot use [:blank:] cz we're dealing with 
		echo "Empty lines are deleted"			# end of line/ nwe line characters hence we use [:space:]
		cat $1
	else
		echo "Error : $1 is empty, So cannot delete the empty lines."
	fi
else
	echo "Error: Please pass the file name through command line."
fi