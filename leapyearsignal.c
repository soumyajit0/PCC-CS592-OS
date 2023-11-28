#include<unistd.h>
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int received=0;

void signalHandler(int signum)
{
	received=1;
}

void parentSignalHandler(int signum)
{
}

int main()
{
	signal(SIGCHLD,signalHandler);
	signal(SIGALRM,parentSignalHandler);
	pid_t p;
	p=fork();
	if (p<0)
	{
		printf("Error in creating the Child Process\n");
		exit(1);
	}
	else if (p==0)
	{
		while(1)
		{
			pause();
			if (received==1)
			{
				printf("Enter a year to check for Leap Year : ");
				int year;
				scanf("%d",&year);
				if (year%100==0)
				{
					if (year%400==0)
					{
						printf("%d is a Leap Year\n",year);
					}
					else
					{
						printf("%d is not a Leap Year\n",year);
					}
				}
				else if (year%4==0)
				{
					printf("%d is a Leap Year\n",year);
				}
				else
				{
					printf("%d is not a Leap Year\n",year);
				}
				received=0;
				kill(getppid(),SIGALRM);
			}
		}
	}
	else if (p>0)
	{
		while(1)
		{
			printf("Press 1 if you want to continue and 0 to exit\n");
			int n;
			scanf("%d",&n);
			if (n!=1)
				break;
			sleep(5);
			printf("Sending signal to the Child Process\n");
			kill(p,SIGCHLD);
			pause();
		}
	}
}
