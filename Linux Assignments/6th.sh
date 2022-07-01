# Given input is reading
digit=$1
num=0
rev=0
if [ $# -gt 0 ]
then

    # cheking the condition is true or not
    if [ $digit -lt -9 -o $digit -gt 9 ]
    then
        if [ $digit -gt 9 ]
        then    
            while [ $digit -gt 0 ]
            do
                num=$(($digit % 10))
                rev=$(( $rev * 10 + $num ))
                digit=$(( $digit / 10 ))
            done
            # The reversing of digits are printing
            echo "Reversed number is $rev"
        else
            echo Error : Please pass positive number
        fi
    else
        echo Error : pass a multi-digit number
    fi
    
else
    echo Error : No arguments passed
fi