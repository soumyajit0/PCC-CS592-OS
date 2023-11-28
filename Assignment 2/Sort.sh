#!/bin/bash
read -p "Enter the no. of Array elements : " n
i=0
while [ $i -lt $n ]
do
	read arr[$i]
	i=$(( i + 1 ))
done
for (( i=0;i<$(( n - 1 ));i++ ))
do
	for (( j=$(( i + 1 ));j<$n;j++))
	do
		if [ ${arr[$i]} -gt ${arr[$j]} ]; then
			temp=${arr[$i]}
			arr[$i]=${arr[$j]}
			arr[$j]=$temp
		fi
	done
done
echo "The Sorted Array is : ${arr[@]}"
