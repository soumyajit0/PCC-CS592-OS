#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
	int fd1=mkfifo("namedpipe1",0666|O_CREAT);
	int fd2=mkfifo("namedpipe2",0666|O_CREAT);
	printf("Named Pipes created\n");
}
