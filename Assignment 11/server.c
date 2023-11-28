#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<signal.h>

struct sharedmemory
{
	char c[100];
	int client;
	int server;
	int res;
};

void custom_handler(int signum)
{
	int n=signum;
}

int isPal(char word[])
{
	int i;
	for(i=0;i<strlen(word)-1;i++)
	{
		if (word[i]!=word[strlen(word)-1-i])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	signal(SIGCONT,custom_handler);
	int shmid=shmget(2832,sizeof(struct sharedmemory),0666|IPC_CREAT);
	struct sharedmemory *shared;
	shared=shmat(shmid,NULL,0);
	shared->server=getpid();
	pause();
	char word[100];
	strcpy(word,shared->c);
	if(isPal(word)==0)
	{
		shared->res=0;
	}
	else
	{
		shared->res=1;
	}
	kill(shared->client,SIGCONT);
	shmdt(shared);
	shmctl(shmid,IPC_RMID,NULL);
}
