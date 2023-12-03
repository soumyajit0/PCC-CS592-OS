#!/bin/bash
if (( $#==0 ));then
	echo "No arguments passed"
	exit
fi

sum=0
n=0
for num in $@
do
	sum=$(( sum+num ))
	n=$(( n+1 ))	
done
echo -n "The Average is : "
echo "scale=3;$sum/$n" | bc -l
