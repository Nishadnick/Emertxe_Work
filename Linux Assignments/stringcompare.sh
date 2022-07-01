#!/bin/bash

#string compare

string1="Error : data2.txt is having only 2 lines. So can’t print 5th line"
string2="Error : data2.txt is having only 2 lines. So can't print 5th line"


if [ string1==string2 ]
then
	echo "samesies"
else
	echo "Diffo"
fi