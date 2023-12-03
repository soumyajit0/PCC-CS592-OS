#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main()
{
	char c1[100],c2[100];
	printf("Enter the strings to be passed onto another process : \n");
	scanf("%s",c1);
	scanf("%s",c2);
	int fd1=open("namedpipe1",O_WRONLY);
	int fd2=open("namedpipe2",O_WRONLY);
	write(fd1,c1,strlen(c1));
	write(fd2,c2,strlen(c2));
	close(fd1);
	close(fd2);
	return 0;
}

