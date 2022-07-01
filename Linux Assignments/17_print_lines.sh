#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title:17_print_lines.sh
Description:
1. Pass three command-line arguments
2. 1- starting line number
3. 2-number of lines and filename
4. Script will print n lines from given starting line (including starting line)

Sample I/p :
nishu@Nishu:~/extra folder$ ./17_print_lines.sh 3 5 new1.txt
Sample O/p :
3. Home directory
4. OS name & version
5. Current working directory
6. Number of users logged in
7. Show all available shells in your system

Documentation


#echo "lines				$lines"
#echo "start				$start"
#echo "number of aargs $#  1st $1   2nd $2"
if [ $# -eq 3 ]
then
	start=$(($1+$2-1))								#according to formula finding the max lines required
	lines=$(wc -l "$3" | cut -d " " -f 1)				#according to file, checking how many lines are available
	
	if [[ "$start" -gt "$lines" ]]					#if available lines are less then required then its error
	then
		echo "Error: $3 is having only $lines lines. file should have atleast $(($1+$2-1)) lines"		
	else
		echo "$(head -$start "$3" | tail -$2)"		#printing the lines according to formula for desired lines
	fi
else
	echo "Error: arguments missing!
Usage: ./file_filter.sh start_line uptoline filename
For eg. ./20_file_filter.sh 5 5 <file>"
fi