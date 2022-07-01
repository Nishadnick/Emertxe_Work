#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title: 20_random_password.sh
Description:
1. Every time a new password must created.
2. Password must contains a alpha-numeric and special characters.

Sample I/p :
1. ./20_random_password.sh
nH@Rh0Pv
Sample O/p :

Documentation

#here we are generating and 8 character string that is totally random owing to the use of urandom file.

#result=`echo "$(cat "/dev/urandom"|tr -cd [[:graph:]]|head -c 8)"`
result=$(cat "/dev/urandom"|tr -cd [[:graph:]]|head -c 8)		#complement deletion of spaces of any kinds
echo "$result"													#printing head characters


	

