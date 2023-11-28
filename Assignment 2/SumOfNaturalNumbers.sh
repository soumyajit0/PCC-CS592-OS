#!/bin/bash

n=$1
sum=$( expr `expr $n \* $(( n + 1 ))` / 2 )
echo "The Sum of ${n} Natural No.s is : ${sum}"

#sum=0
#for (( i=1;i<=$n;i++ ))
#do
#	sum=$(( sum + i ))
#done
#echo "Sum of $n natural no.s is $sum"
