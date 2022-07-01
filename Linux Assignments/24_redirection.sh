#!/bin/bash
<<Documentation
name: Nishad S. Taksande
Date: 7-Dec-21
Assignment Title: 24_redirection.sh
Description:
1. The final output becomes the input again to the command line.
2. Be alert, remember to stop (ctrl + c) this command before it fills your
hard disk.
3. Look at the documentation for the tail command

Sample I/p :
1. ./24_redirection.sh
Before loop file contents
Hai hello
Sample O/p :
After loop file contents
Hai hello
Hai hello
Hai hello
Hai hello
Hai hello
Hai hello
Hai hello

Documentation
													#Infinite recursive output display
echo "Hai hello">output.txt 						#hrere we're using >> (appending operator)
													#so simply the text is getting copied 
													#into the outputfile that is also
													#that is also getting created at this instant
tail -f output.txt>>output.txt|tail -f output.txt	#the -f option keeps the output in a continuous proactive state
													#it is just waitig to display any new modifications that are available
													#>> will again keep transferring the same output content
													#and -f will just keep updating this output to re-store it in the file




