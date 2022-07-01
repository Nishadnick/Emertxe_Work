#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title: 31_executable_path.sh
Description:
1. Fetch each directories from PATH variable.
2. Use -x option in if condition to check executable permission.
3. Print directory and number of executable files one-by-one.
4. Print the total number of executable files at last.
5. Count only files have executable permission.
6. Verify path is present every-time.

Sample I/p :
./31_executable_path.sh
Sample O/p :

Current dir: /usr/local/sbin
current count: 0
Current dir: /usr/local/bin
current count: 0
Current dir: /usr/sbin
current count: 205
Current dir: /usr/bin
current count: 1889
Current dir: /sbin
current count: 187
Current dir: /bin
current count: 159
Current dir: /usr/games
current count: 5
Current dir: /usr/local/games
current count: 0
Total – 2445
Documentation

#echo "$PATH"

arrpath=`(echo "$PATH"|tr ":" " ")`			#tr and sed command can be used to do literal replacement

echo "${arrpath[@]}"
totcount=0							
for dir in ${arrpath[@]}					#cycle through #PATH directories
do
	if [ -e $dir ]							#chk if file is Xist
	then
		if [ -d $dir ]
		then
			cd $dir							#enter the current directory
			count=0							#
			#echo "$dir"
			for i in $(ls)					# * also works
			do	
				
				if [ -x $i ]				#chk if file is xecutable
				then 
					
					count=$((count+1))		#count of executable file for the current directory
				fi
			done
			echo "Current dir: $dir"
			echo "current count: $count"			#stats of current directory
		else
			echo "$dir is not a directory"
		fi
	else
		echo "$dir does not exist"
	fi
	totcount=$(($totcount+$count))			#total count after counts of indivdual directories is accumilated
done
echo "Total count = $totcount"
			
