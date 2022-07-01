#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title: 26_mounted_fs.sh
Description:
1. Check that given file-system is mounted or not
2. If its mounted, print free-space available in it.
3. Other-wise print error message.

Sample I/p :

1. ./26_mounted_fs.sh /dev/sda2
File-system /dev/sda2 is mounted on / and it is having 98%
used space with 3298220 KB free.

Documentation


filsystms=(`df|tr -s " "|cut -d " " -f 1`)
usepercent=(`df|tr -s " "|cut -d " " -f 5`)		#selectively extracting the full data from a particular row
freespace=(`df|tr -s " "|cut -d " " -f 4`)		#stoing the data in array
mounts=(`df|tr -s " "|cut -d " " -f 6`)
#echo " 
#${mounts[@]} 
#"
#for i in ${mounts[@]}
#do
#	echo "$i"
#done
flag=0
if [ $# -eq 0 ]
then
	echo "Error : Please pass the name of the file-system through command line."
else
	for i in `seq ${#mounts[@]}`	
	do
		if [ "${filsystms[$i]}" = "$1" ]		#simply checking if the given argument is present in the data list
		then
			flag=1								#using flag method to confirm if we found a match
			break								#immidiately break the loop after we found what we were looking for
		fi
	done
	if [ "$flag" -eq 1 ]						#use the chosen values index number to print the data needed
	then
		echo "File-system $1 is mounted on ${mounts[$i]} and it is having ${usepercent[$i]} used space with ${freespace[$i]}KB free."
	else
		echo "$1 is not mounted."				#this is the flag when the required flie system was not found
	fi
fi
