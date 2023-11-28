#!/bin/bash
while [ 1 ]
do
	echo "Press 1 to Sort the Students in Reverse Order according to their Roll No.s"
	echo "Press 2 to Replace Lowercase with Uppercase letters in the file Sorted.dat"
	echo "Press 3 to Append Unique names from Sorted.dat to Students.dat"
	echo "Press 4 to Display 2nd and 3rd Lines of Student.dat"
	echo "Press 5 to Exit"
	read -p "Enter your choice : " ch
	case $ch in
		1)
			sort -r -g -t "|" -k2 Students.dat > Sorted.dat
			echo "Students have been Sorted in Reverse Order of their Roll No.s and stored in Sorted.dat"
			;;
		2)
			#tr "[:lower:]" "[:upper:]" < Sorted.dat > tmpSorted.dat		Method 1
			tr "[a-z]" "[A-Z]" < Sorted.dat > tmpSorted.dat		       #Method 2
			mv tmpSorted.dat Sorted.dat
			;;
		3)
  			cat Sorted.dat | sort -t "|" -u -k1,1 >> Students.dat
			;;
		4)
			head -n +3 Students.dat | tail -n +2
			;;
		5)
			exit
			;;
		*)
			echo "Invalid Choice"
	esac
done
