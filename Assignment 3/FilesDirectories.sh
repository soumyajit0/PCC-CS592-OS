#!/bin/bash
while [ 1 ]
do
	echo "Press 1 to check Permissions of a specific File or Directory"
	echo "Press 2 to check the no. of Files and Directories under current Directory"
	echo "Press 3 to show Last Modification Time of a File in current Directory"
	echo "Press 4 to Exit"
	read -p "Enter your choice : " n
	case $n in
		1)
			read -p "Enter the name of the File or Directory to check its permissions : " checkPerms
			perms=$(ls -l "${checkPerms}" | cut -d " " -f1 | cut -c2-)
			# perms=$(ls -l | grep "$name" | cut -d " " -f1 | cut -c2-)
			echo "The Permissions for ${checkPerms} are : $perms"
			;;
		2)
			files=$(ls -l | tail -n +2 | cut -d " " -f1 | grep -c "-")
			directories=$(ls -l | tail -n +2 | cut -d  " " -f1 | grep -c "d")
			echo "The no. of File(s) in the current Directory is/are : ${files}"
			echo "The no. of Directory/Directories in the current Directory is/are : ${directories}"
			
			# echo -n "The no. of Directories are : "
			# ls -l | cut -d " " -f1 | cut -c1 | grep "d" | wc -l
			# echo -n "The no. of Files are : "
			# ls -l | cut -d " " -f1 | cut -c1 | grep -c  "-"
			;;
		3)
			read -p "Enter the name of the File to check its Last Modification Time : " checkTime
			date=$(ls -l "${checkTime}" | cut -d " " -f6,7)
			time=$(ls -l "${checkTime}" | cut -d " " -f8)
			echo "${checkTime} was last modified on : ${date} at : ${time}"
			;;
		4)
			exit
			;;
		*)
			echo "Invalid choice"
	esac
done
