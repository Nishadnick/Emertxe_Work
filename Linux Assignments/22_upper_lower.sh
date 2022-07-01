#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title:22_upper_lower.sh
Description:
1. Provide a filename through command-line.
2. Check the file is present and it has some contents.
3. Ask user for conversion Lower to Upper / Upper to Lower

Sample I/p :
/22_upper_lower.sh file.txt
1 – Lower to upper
2 – Upper to lower
Please select option : 1
Sample O/p : 
WHAT IS OS?
WHAT ARE THE DIFFERENT OS?
WHEN IS OS USED?
WHAT IS PARTITION AND ITS USE?
HOW MANY PARTITIONS CAN BE DONE?
Documentation


#	start=$(($1+$2-1))								
#	lines=$(wc -l $3 | cut -d " " -f 1)				
#	echo "$(head -$start "$3" | tail -$2)"		


if [ $# -eq 1 ]
then
	read -p "	1 – Lower to upper
	2 – Upper to lower
	Please select option : " choise
	if [ -e "$1" ]			#chk if file exists
	then
		if [ -s "$1" ]		#check if its not empty
		then
			if [ $choise -eq 1 ]
			then
				#cat $1 | tr '[:print:]' '[:upper:]'	
				
				tr '[[:lower:]]' '[[:upper:]]' <$1		#converting lowercase to UPPERCASE
			else
				#cat $1 | tr '[:print:]' '[:lower:]'
				
				tr '[[:upper:]]' '[[:lower:]]' < $1		#converting UPPERCASE to lowercase
			fi
		else
			echo "Error : No contents inside the file."
		fi
	else
		echo "Error : file is not exist."
	fi
else
	echo "Error : Please pass the file name through command line."
fi




