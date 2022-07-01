#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 3-Dec-21
Assignment Title: 13_system_info.sh
Description:
1. Provide a menu for user about what information he wants to check
2. Using switch case display output for selected option.
Sample I/p :

Sample O/p : 


1. Currently logged users
2. Your shell directory
3. Home directory
4. OS name & version
5. Current working directory
6. Number of users logged in
7. Show all available shells in your system
8. Hard disk information
9. CPU information.
10. Memory Informations
11. File system information.
12. Currently running process.
Documentation


echo "
1. Currently logged users
2. Your shell directory
3. Home directory
4. OS name & version
5. Current working directory
6. Number of users logged in
7. Show all available shells in your system
8. Hard disk information
9. CPU information.
10. Memory Informations
11. File system information.
12. Currently running process."

opt="y"
#read -p "press a value :" choice

	while [ "$opt" == "y" ]					
	do 
		read -p "Enter the choice :" choice					#prompt for choice until the user presses yes 'y'
		if [ $choice -gt 0 ] || [ $choice -le 12 ]
		then
			case $choice in 
			1) 
				echo -n "Currently logged users"
				echo " are $who"
				read -p "Do you want to continue(y/n) ? " opt		#when user presses no 'n' 
																	#then the control comes out of whle loop
			;;
			2) 
				echo -n "Your shell directory"
				echo " is $SHELL"
				read -p "Do you want to continue(y/n) ? " opt
			;;			
			3) 
				echo -n "Home directory"
				echo " is $HOME"
				read -p "Do you want to continue(y/n) ? " opt
			;;			
			4) 
				echo -n "OS name & version"
				echo " is $(uname -a)"
				read -p "Do you want to continue(y/n) ? " opt
				
			;;			
			5) 
				echo -n "Current working directory"
				echo " is $PATH"
				read -p "Do you want to continue(y/n) ? " opt
			;;			
			6) 
				echo -n "Number of users logged in"
				echo " is $(who -q)" 
				read -p "Do you want to continue(y/n) ? " opt
			;;			
			7) 
				echo -n "Show all available shells in your system"
				echo " $(cat /etc/shells)"
				read -p "Do you want to continue(y/n) ? " opt
			;;			
			8) 
				echo -n "Hard disk information"
				echo " is $df"
				read -p "Do you want to continue(y/n) ? " opt
			;;			
			9) 
				echo -n "CPU information."
				echo " is $(cat /proc/cpuinfo)"
				read -p "Do you want to continue(y/n) ? " opt
			;;			
			10) 
				echo -n "Memory Informations"
				echo " is $(cat /proc/meminfo)"
				read -p "Do you want to continue(y/n) ? " opt
			;;			
			11) 
				echo -n "File system information."
				echo " is $(cat /proc/mounts)"
				read -p "Do you want to continue(y/n) ? " opt
			;;			
			12) 
				echo -n "Currently running process."
				echo " is $ps"
				read -p "Do you want to continue(y/n) ? " opt
			;;
			*)
				echo "Error : Invalid option, please enter valid option"
				read -p "Do you want to continue(y/n) ? " opt
			esac
		else
		echo "Error : Invalid option, please enter valid option"
		read -p "Do you want to continue(y/n) ? " opt
		fi
	done
	
