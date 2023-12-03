#!/bin/awk -f
BEGIN{
	FS="|"
}
NR!=1{
	if ($5>15000){
		print $1
	}
}
END{

}
