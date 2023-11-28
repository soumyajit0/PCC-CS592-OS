#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>

int main()
{
	pid_t p;
	p=fork();
	if (p<0)
	{
		printf("Error in creating a Child Process\n");
	}
	else if (p==0)
	{
		sleep(10);
		printf("I am the Orphan Child Process\n");
		printf("My Process ID is : %d\n",getpid());
		printf("My Parent's Process ID is : %d\n",getppid());
	}
	else if (p>0)
	{
		sleep(5);
		printf("I am the Parent Process and I am going to die\n");
		printf("My Process ID is : %d\n",getpid());
		printf("My Child's Process ID is : %d\n",p);
	}
}
