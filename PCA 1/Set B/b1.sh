#!/bin/bash
declare -a arr
read -p "Enter the size of the Array : " n
for (( i=0;i<$n;i++ ))
do
	read arr[$i]
done
for (( i=0;i<$n-1;i++ ))
do
	for (( j=$i+1;j<$n;j++ ))
	do
		if (( ${arr[$j]}<${arr[$i]} ));then
			temp=${arr[$i]}
			arr[$i]=${arr[$j]}
			arr[$j]=$temp
		fi
	done
done
echo "Sorted Array : ${arr[@]}"
