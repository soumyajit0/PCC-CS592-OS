#!/bin/awk -f
BEGIN{
	FS="~"
	highest=-1
}
NR!=1{
	sub1=$3
	sub2=$4
	sub3=$5
	if (highest<(sub1+sub2+sub3)){
		name=$1
		highest=sub1+sub2+sub3
	}
}
END{
	print name,"got the Highest Marks =",highest
}
