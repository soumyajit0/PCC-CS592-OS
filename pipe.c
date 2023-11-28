#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<string.h>

int main()
{
	int fd[2],n1,n2;
	char c1[100],c2[100];
	pipe(fd);
	pid_t p;
	p=fork();
	if (p<0)
	{
		printf("Error in creating the Child Process\n");
	}
	else if (p==0)
	{
		printf("Enter the message to be passed from the Child Process to the Parent Process : ");
		scanf("%s",c1);
		write(fd[1],c1,strlen(c1)+1);
	}
	else if (p>0)
	{
		wait(NULL);
		printf("The message received by the Parent Process is : ");
		n2=read(fd[0],c2,100);
		write(1,c2,n2);
	}
}
