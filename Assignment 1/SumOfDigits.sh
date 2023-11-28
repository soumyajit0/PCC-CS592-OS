#!/bin/bash
read -p "Enter a No. to find the Sum of its Digits : " n
sum=0
temp=$n
while [[ $temp > 0 ]]
do
	#lastDigit=$(( temp % 10 ))			Method 1
	#sum=`expr $sum + $lastDigit`
	sum=$(( sum + $(( temp % 10 )) ))	       #Method 2
	temp=$( expr $temp / 10 )
done
echo "The Sum of the Digits of $n is : $sum"
