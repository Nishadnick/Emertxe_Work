#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 11_chess_board.sh
Description:
1. To print a black box echo -e -n "\e[40m" " "
2. To print a white box echo -e -n "\e[47m" " "
3. Call the commands in a loop.
4. After 8 columns make to normal color.
5. To make it normal echo -e -n "\e[0m" " "
Sample I/p : ./11_chess_board.sh
Sample O/p : 
0 1 0 1 0 1 0 1
1 0 1 0 1 0 1 0
0 1 0 1 0 1 0 1
1 0 1 0 1 0 1 0
0 1 0 1 0 1 0 1
1 0 1 0 1 0 1 0
0 1 0 1 0 1 0 1
1 0 1 0 1 0 1 0
Documentation

for i in `seq 4`
do
	for i in `seq 4`
	do
		echo -e -n "\e[47m" " "					#print white first then Black
		echo -e -n "\e[40m" " "
	done
	echo -e "\e[0m" " "							#normal colour
	for i in `seq 4`
	do
		echo -e -n "\e[40m" " "					#print black first then white
		echo -e -n "\e[47m" " "
	done
	echo -e "\e[0m" " "							#normal colour

done
#echo -e -n "\e[0m" " "