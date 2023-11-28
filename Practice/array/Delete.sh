#!/bin/bash
arr=('1' '2' '3' '4' '5')
echo "The Original Array is ${arr[@]}"
read -p "Enter the Cell No. to be Deleted(1-5) : " n
unset arr[$n-1]
echo "The New Array is ${arr[@]}"
