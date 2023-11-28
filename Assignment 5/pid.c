#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>

int main()
{
	pid_t p;
	p=fork();
	if (p<0)
	{
		printf("Error in creating the Child Process\n");
	}
	else if (p==0) // Child Process
	{
		sleep(5);
		printf("I am the Child Process\n");
		printf("My Process ID is : %d\n",getpid());
		printf("My Parent's Process ID is : %d\n",getppid());
		printf("\n");
	}
	else if (p>0) // Parent Process
	{
		wait(NULL);
		printf("I am the Parent Process\n");
		printf("My Process ID is : %d\n",getpid());
		printf("My Child's Process ID is : %d\n",p);
	}
}
