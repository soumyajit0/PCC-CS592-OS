#!/bin/bash
read -p "Enter a value : " n
regex="^-?[0-9]+$"
if [[ $n =~ $regex ]]; then
	echo "It is a Number"
else
	echo "It is not a Number"
fi
