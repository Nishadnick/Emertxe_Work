#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title:16_rename_album.sh
Description:
1. Aim of this project is to rename all files in one directory with a common
name and indexing.
2. Usually when we takes pics in camera or mobile default names are like
DSN001.jpg, DSN002.jpg
3. These files need to be renamed by user given prefix name
4. Prefix name pass through command-line argument.

Sample I/p : $ ls
DSN001.jpg DSN002.jpg DSN003.jpg DSN004.jpg DSN005.jpg
./16_rename_album.sh day_out

Sample O/p : All .jpg files in current directory is renamed as
day_out001.jpg day_out002.jpg day_out003.jpg day_out004.jpg
day_out005.jpg 


Documentation

oldfiles=$(ls jpegs)
#echo -e "${oldfiles[@]} \n new suffix $1 and $PWD"
if [ $# -eq 1 ]
then
	cd jpegs/
	echo "$PWD"
	for i in ${oldfiles[@]}
	do
		if [ "$1" != "$i" ]
		then
			oldsufix=$(echo "$i"| cut -d "." -f 1 | tr -cd [:alpha:])
			echo "$oldsufix"
			newname=`echo "$i" | sed s/$oldsufix/$1/`
			#newname=$(echo "$i"| sed -n 's/$oldsufix/$1/p')
			echo "$newname and $1"
			mv $i $newname
		else
			echo "string are same"
		fi
	done
else
	echo "Error : Please pass the prefix name through command line."
fi

