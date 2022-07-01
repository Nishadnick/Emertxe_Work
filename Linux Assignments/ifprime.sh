#!/bin/bash


read -p "enter a no. to chk if Prime : " num
flag=0

if [ $num -eq 1 ] || [ $num -eq 0 ]
then
	echo "$num prime no not prime"
else
	for i in `seq 2 $((num-1))`
	do
		echo "$num number ad i is $i answer $(($num%$i))"
		if [ $(($num%$i)) -eq 0 ]
		then
			flag=1
			break
		fi
	done
fi
if [ $flag -eq 1 ]
then
	echo "$num is not prime"
else
	echo "$num is prime number"
fi
	

	

