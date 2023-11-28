#!/bin/bash
read -p "Enter the size of the Array : " n
for (( i=0;i<$n;i++ ))
do
	read arr[$i]
done
length=${#arr[@]}-1
for (( i=0;i<$n;i++ ))
do
	reversed[$i]=${arr[$length]}
	length=$(( length - 1 ))
done
echo "The Original Array is ${arr[@]}"
echo "The Reversed Array is ${reversed[@]}"
