#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
	char c1[100],c2[100];
	printf("Enter the two strings to be passed onto another process : \n");
	scanf("%s",c1);
	scanf("%s",c2);
	int fd=open("namedpipe",O_WRONLY);
	write(fd,c1,strlen(c1));
	write(fd,c2,strlen(c2));
	close(fd);
	return 0;
}
