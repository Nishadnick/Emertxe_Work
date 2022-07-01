oldnum=$1
echo "${#oldnum}"
echo "{$#}"


pwd
cd /home/nishu/dir5

pwd
aray=(`ls /home/nishu/dir5`)

echo "the array ${aray[@]}"

echo "now use for loop  "
for i in "${aray[@]}"
do
	echo "${i}"
done

#echo "`${aray[@]}|wc -l`"