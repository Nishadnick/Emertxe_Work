


read -p "no. of rows: " rows
echo the $rows limit

for i in `seq $rows`
do
#	echo "$i $rows"
	for j in `seq $i`
	do
		echo -e -n ' ' 
	done
	for k in `seq $rows -1 $i`
	do
		echo -n "*"
	done
	echo ""
done


