#!/bin/bash
read -p "Enter a no. to find Factorial : " n
factorial=1
for (( i=1;i<=$n;i++ ))
do
	# factorial=$(( factorial * i ))
	# factorial=$( expr $factorial \* $i )
	factorial=`expr $factorial \* $i`
done
echo "The Factorial of $n is $factorial"
