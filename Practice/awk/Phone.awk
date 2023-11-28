#!/bin/awk -f

#Name:Roll No.:Phone No.

BEGIN{
	FS=":"
	output="result.txt"
}
NR!="1"{
	if ($3 ~ /^79/){
		print $1 >> output
	}
}
END{
	while ((getline line < output) > 0){
		print line
	}
}
