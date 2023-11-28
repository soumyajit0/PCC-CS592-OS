#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(){
	int fd=open("namedpipe",O_RDONLY);
	char c1[100],c2[100];
	read(fd,c1,100);
	read(fd,c2,100);
	printf("The two Strings received are : %s and %s\n",c1,c2);
	if (strcmp(c1,c2)==0)
		printf("SAME\n");
	else
		printf("NOT SAME\n");
	close(fd);
}
