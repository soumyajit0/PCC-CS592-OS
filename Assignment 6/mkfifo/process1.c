#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
	char c1[100],c2[100];
	int fd=open("namedpipe",O_WRONLY);
	printf("Enter the strings to be passed onto another process : \n");
	scanf("%s",c1);
	scanf("%s",c2);
	write(fd,c1,strlen(c1)+1);
	write(fd,c2,strlen(c2)+1);
	close(fd);
	return 0;
}


