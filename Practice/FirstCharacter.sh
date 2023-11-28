#!/bin/bash
while read line
do
	echo ${line^}
 	## echo ${line^^} -> Capitalize all letters
done < file.txt
