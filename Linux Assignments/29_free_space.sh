#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title: 29_free_space.sh
Description:
1. When you run the script show all file-system present in system.
2. Then print file-systems that have only 10% memory remaining.

Sample I/p :
./29_free_space.sh
Sample O/p :

Filesystem /dev/sda5 have less than 10% free space

Documentation


filsystm=(`df|tr -s [:space:]|cut -d " " -f 1`)
usedmem=(`df|tr -s [:space:]|cut -d " " -f 5|tr -d "%"`)		#collecitvle extraction of the required fields
#avalable=(`df|tr -s [:space:]|cut -d " " -f 4`)

for i in `seq ${#filsystm[@]}`
do
	if [[ ${usedmem[$i]} -gt 90 ]]					#comparings the used field and looping with index number
	then
		echo "Filesystem ${filsystm[$i]} have less than 10% free space"
	fi
done		