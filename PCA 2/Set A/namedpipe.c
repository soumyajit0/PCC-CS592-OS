#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
	int temp=mkfifo("namedpipe",0666);
	printf("A named Pipe is created\n");
	return 0;
}

