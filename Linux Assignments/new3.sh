array=(one two three four five)
echo "${#array[@]} -

${#array[*]} -

${array[2]} -

${#array} -"



echo "echo $#

echo $@

echo $1"

myname=Vivek

myno=5

myos=TroubleOS

echo "My name is $myname"

echo My OS is `myno`

echo "My no is myno, can you see this number"