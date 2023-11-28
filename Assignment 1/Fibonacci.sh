#!/bin/bash
echo -n "Enter the value of n : "
read n
a=-1
b=1
for (( i=1;i<=$n;i++ ))
do
	c=`expr $a + $b`
	echo -n "$c "
	a=$b
	b=$c
done
echo
