#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>

int alrm=0,signl=0;

void signalHandler(int signum)
{
	alrm=1;
	signl=signum;
}


int main()
{
	signal(SIGALRM,signalHandler);
	pid_t p;
	p=fork();
	if (p<0)
	{
		printf("Error creating the Child Process\n");
		exit(0);
	}
	else if (p==0)
	{
		printf("I am the Child Process with ID : %d and my Parent's Process ID : %d\n",getpid(),getppid());
		sleep(5);
		kill(getppid(),SIGALRM);
		printf("Child Process sent an Alarm to the Parent Process\n");
	}
	else if (p>0)
	{
		printf("I am the Parent Process with my Process ID : %d\n",getpid());
		while(alrm==0)
		{
			printf("Hello World! I am waiting for the signal from my Child Process\n");
			sleep(1);
		}
		printf("I received Signal : %d from my Child Process\n",signl);	
	}
}
