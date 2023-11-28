#!/bin/bash
function storeDetails()
{
	read -p "Enter your Name : " name
	read -p "Enter your Department : " dept
	read -p "Enter your Roll No. : " roll
	echo -n  "Enter your Password : "
	read -s passwd
	echo
	echo "$name:$dept:$roll:$passwd" > personal.dat
	echo "Personal Details have been stored"
}
function displayDetails()
{
	if [ -f "personal.dat" ]; then
		passwd=$(cut -d ":" -f4 personal.dat)
		echo -n "Enter the Password : "
		read -s checkPasswd
		echo
		if [ "$checkPasswd" = "$passwd" ]; then
			name=$(cut -d ":" -f1 personal.dat)
			dept=$(cut -d ":" -f2 personal.dat)
			roll=$(cut -d ":" -f3 personal.dat)
			echo "Name : ${name}"
			echo "Department : ${dept}"
			echo "Roll No. ${roll}"
		else
			echo "Wrong Password"
		fi
	else
		echo "No file exists"
	fi
}
while [ 1 ]
do
	echo "Press 1 to Store Personal Details"
	echo "Press 2 to Display Personal Details"
	echo "Press 3 to Exit"
	read -p "Enter your choice : " n
	case $n in
		1)
			storeDetails
			;;
		2)
			displayDetails
			;;
		3)
			exit
			;;
		*)
			echo "Invalid Choice"
	esac
done
