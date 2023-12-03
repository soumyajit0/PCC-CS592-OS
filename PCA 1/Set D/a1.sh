#!/bin/bash
while [ 1 ]
do
	echo "Press 1 to sort reverse of Roll No. and store in Sorted.dat"
	echo "Press 2 to convert Lower Case to Upper Case in Sorted.dat"
	echo "Press 3 to find the Unique names"
	echo "Press 4 to exit"
	read -p "Enter your choice : " c
	case $c in
		1)
			echo "NAME|ROLL|PHONE|ADDRESS" > Sorted.dat
			cat Student.dat | tail -n +2 | sort -g -r -t "|" -k2 >> Sorted.dat
			echo "Data sorted in reverse order"
			;;
		2)
			tr "[a-z]" "[A-Z]" < Sorted.dat > tempSorted.dat
			mv tempSorted.dat Sorted.dat
			echo "Case changed"
			;;
		3)
			cat Student.dat | tail -n +2 | cut -d "|" -f1 | sort | uniq -u > Unique.dat
			cat Student.dat | tail -n +2 | cut -d "|" -f1 | sort | uniq -d >> Unique.dat
			echo "The Unique names are : "
			cat Unique.dat
			;;
		4)
			exit
			;;
		*)
			echo "Invalid Choice"
	esac
done
