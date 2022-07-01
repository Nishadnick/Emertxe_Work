#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title: 28_lock_permissions.sh
Description:
1. Provide directory name through command-line.
2. Remove all permissions for groups and others.
3. But remember don’t add any permission to user, only change
permissions to others and groups.

Sample I/p :
1. ./28_lock_permissions.sh Dir/
Before locking
total 0
-rw-rw-r-- 1 biju biju 0 Jun 8 12:37 D2file1
-rw-rw-r-- 1 biju biju 0 Jun 8 12:37 D2file2
-rw-rw-r-- 1 biju biju 0 Jun 8 12:37 D2file3
Sample O/p :
After locking
total 0
-rw------- 1 biju biju 0 Jun 8 12:37 D2file1
-rw------- 1 biju biju 0 Jun 8 12:37 D2file2
-rw------- 1 biju biju 0 Jun 8 12:37 D2file3

Documentation



if [ $# -eq 0 ]
then
	echo "Error : Please pass the directory in command line"		#if CLA directories are not passed then error
else
	if [ -d $1 ]			#checking if the supposed directory is an actual directory
	then
		cd $1					#changing to the directory before changing their permissions
		chmod -R go-rwx $1		#chmod is used to modify permissions and R is used to do it recurrsively
	else						#go (group&others)	-rwx{minus read, write and execute}
		echo "Cannot access ‘$1’ : No such a file or directory."
	fi
fi