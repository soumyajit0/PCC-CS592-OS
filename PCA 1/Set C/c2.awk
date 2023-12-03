#!/bin/bash
BEGIN{
	FS=";"
	highest1=-1
	highest2=-1
	highest3=-1
}
NR!=1{
	if ($3>highest1){
		highest1=$3
		name1=$1
	}
	if ($4>highest2){
		highest2=$4
		name2=$1
	}
	if ($5>highest3){
		highest3=$5
		name3=$1
	}
}
END{
	print name1,"got the Highest Marks in Subject 1 =",highest1
	print name2,"got the Highest Marks in Subject 2 =",highest2
	print name3,"got the Highest Marks in Subject 3 =",highest3
}
