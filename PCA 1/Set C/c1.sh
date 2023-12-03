#!/bin/bash
while [ 1 ]
do
	echo "Press 1 to show no. of Files and Directories"
	echo "Press 2 the permission of a File/Directory"
	echo "Press 3 to show the size of File/Directory in Bytes"
	echo "Press 4 to exit"
	read -p "Enter your choice : " c
	case $c in
		1)
			files=$(ls -l | cut -d " " -f1 | cut -c1 | grep -c "-")
			directories=$(ls -l | cut -d " " -f1 | cut -c1 | grep -c "d")
			echo "No. of Files : ${files}"
			echo "No. of Directories : ${directories}"
			;;
		2)
			read -p "Enter a File/Directory name : " name
			ls -l $name | cut -d " " -f1 | cut -c2-
			;;
		3)
			read -p "Enter a File/Directory name : " name
			echo -n "The size of ${name} is : "
			ls -l $name | tr -s " " | cut -d " " -f5
			echo
			;;
		4)
			exit
			;;
		*)
			echo "Invalid Choice"
	esac
done
