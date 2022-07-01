#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title:14_file_upper_lower.sh
Description:
1. Rename all files from current working directory to lowercase letters.
2. Rename all directories from current directories to uppercase.
3. Digits and other symbols should remain same.

Sample I/p :
nishu@Nishu:~/copper$ ls test
FILE1.txt  neW1  nEW.txt      testCOPY.txt  TEST.txt
FILe2.txt  new2  TesT3RD.txt  TesTing       workING

Sample O/p : 
nishu@Nishu:~/copper$ ls test
file1.txt  NEW1  new.txt      testcopy.txt  test.txt
file2.txt  NEW2  test3rd.txt  TESTING       WORKING

Documentation

list=`(ls test)` 			#old names
echo "eco ${list[@]}"

echo "$(pwd)"

cd test/

echo "$(pwd)"

for i in ${list[@]}											#cycle through contents
do
	echo "this is $i"
	
	if [ -f ${i} ]											# Check if its a file
	then
	 	echo "$i    is a file"
		#new_name="$(dirname "${i}")/$(basename "${i}" | tr '[A-Z]' '[a-z]')"
		new_name=`echo "$i" | tr '[A-Z]' '[a-z]'`				#creating a new name making lower case
		echo "$new_name"
		if [ "${name}" != "${new_name}" ]					#chking if it already exists
		then
			mv "$i" "${new_name}"							#rename operation
		fi
	elif [ -d ${i} ]											# Check if its a directory
	then
		echo "$i   this is directory"
		new_name=`echo "$i"|tr '[a-z]' '[A-Z]'`				#creating a new name making upper case
		echo "$new_name"
		if [ "${name}" != "${new_name}" ]					#chking if it already exists
		then
			mv "$i" "${new_name}"							#rename operation
		fi
	fi
done
#echo "$(ls test)"											#test result
