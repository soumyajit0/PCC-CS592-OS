#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(){
	int fd1=open("namedpipe1",O_RDONLY);
	int fd2=open("namedpipe2",O_RDONLY);
	char c1[100],c2[100];
	read(fd1,c1,100);
	read(fd2,c2,100);
	printf("The two Strings received are : %s and %s\n",c1,c2);
	if (strcmp(c1,c2)==0)
		printf("SAME\n");
	else
		printf("NOT SAME\n");
	close(fd1);
	close(fd2);
}

