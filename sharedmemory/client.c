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

int main()
{
	signal(SIGCONT,custom_handler);
	int shmid=shmget(2832,sizeof(struct sharedmemory),0666|IPC_CREAT);
	struct sharedmemory *shared;
	shared=shmat(shmid,NULL,0);
	shared->client=getpid();
	printf("Enter a word to check for Palindrome : ");
	char word[100];
	scanf("%s",word);
	strcpy(shared->c,word);
	kill(shared->server,SIGCONT);
	pause();
	if (shared->res==0)
	{
		printf("Not Palindrome\n");
	}
	else if (shared->res==1)
	{
		printf("Palindrome\n");
	}
	shmdt(shared);
	shmctl(shmid,IPC_RMID,NULL);
}
