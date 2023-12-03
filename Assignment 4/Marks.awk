#!/bin/awk -f
BEGIN{
	FS="~"
	print "Press 1 to find the name of the Student with Highest Marks"
	print "Press 2 to find the Average Marks for a given subject"
	print "Press 3 to find the top scorer for each subject"
	print "Enter your choice : "
	getline choice < "/dev/stdin"
}
NR!=1{
	if (choice==1){
		sum=$3+$4+$5
		if (sum>highest){
			name=$1
			highest=sum
		}
	}
	else if (choice==2){
		n+=1
		sub1+=$3
		sub2+=$4
		sub3+=$5
	}
	else if (choice==3){
		sub1=$3
		sub2=$4
		sub3=$5
		if (sub1>highest1){
			name1=$1
			highest1=sub1
		}
		if (sub2>highest2){
                        name2=$1
                        highest2=sub2
                }
		if (sub3>highest3){
                        name3=$1
                        highest3=sub3
                }
	}
	else{
		print "Invalid Choice"
	}	
}
END{
	if (choice==1){
        print name," got the Highest Marks of",highest
    }       
    else if (choice==2){
        print "Average for Sub 1 :",sub1/n
		print "Average for Sub 2 :",sub2/n
		print "Average for Sub 3 :",sub3/n
    }       
    else if (choice==3){
        print name1,"got the Highest Marks of",highest1,"in Subject 1"
		print name2,"got the Highest Marks of",highest2,"in Subject 2"
		print name3,"got the Highest Marks of",highest3,"in Subject 3"
    }
}
