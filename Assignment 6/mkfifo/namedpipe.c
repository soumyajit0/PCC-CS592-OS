#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	int fd=mkfifo("namedpipe",0666|O_CREAT);
	printf("Named Pipe created\n");
}

