#!/bin/bash
read -p "Enter a Year to check if it is Leap Year or not : " y

if [ `expr $y % 100` -eq 0 ]; then
	if [ `expr $y % 400` -eq 0 ]
	then
		echo "$y is a Leap Year"
	else
		echo "$y is not a Leap Year"
	fi
elif [[ $( expr $y % 4 ) == 0 ]]
then
	echo "$y is a Leap Year"
else
	echo "$y is not a Leap Year"
fi
