#!/bin/bash
read -p "Enter the Username to be Searched : " user
count=$(grep -c -i "$user" /etc/passwd)
# count=$(cat /etc/passwd | cut -d ":" -f1 | grep ${user} | wc -l)
if [ $count -eq 0 ]; then
	echo "${user} is not a Valid User"
else
	echo "${user} is a Valid User"
fi
