#!/bin/awk -f
BEGIN{
	FS="|"
	output="temp.txt"
}
NR!=1{
	if ($3 ~ /^98/){
		print $1 >> output
	}
}
END{
	close(output)
	while ((getline line < output)>0){
		print line
	}
}
