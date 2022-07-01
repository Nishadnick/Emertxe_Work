#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title:15_rename_cur_dir.sh
Description:
 Pass new name through command-line.
• After executing this script your current directory will be renamed to given
name

Sample I/p :

Sample O/p : 

Documentation

echo "current directory name $(basename $PWD)"
old_name=$(basename $PWD)
cd ..
if [ $# -eq 1 ]
then
	if [ "$1" != "$old_name" ]
	then
		mv "$old_name" "$1"
	else
		echo "Error : Current directory name and $1 both are same, Please pass new name"
	fi
else
	echo "Error : Please pass the new directory name"
fi

