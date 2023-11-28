#include<signal.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void customHandler(int);

int main()
{
	signal(SIGINT,customHandler);
	while(1)
	{
		printf("Hello World!\n");
		sleep(1);
	}
}

void customHandler(int signum)
{
	printf("Interrupted!\n");
	printf("Signal ID : %d\n",signum);
	exit(0);
}
