#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<unistd.h>

struct sharedMemory
{
	int term;
	int data;
	sem_t mutex;
	sem_t wrt;
};

struct sharedMemory *shared; 

void customHandler(int signum)
{
	int signal=signum;
	shared->term=1;
	printf("Interrupt Signal %d received!!!\n",signal);
	exit(0);
}

int main()
{
	signal(SIGINT,customHandler);
	key_t key=ftok("memory",2832);
	int shmid=shmget(key,sizeof(struct sharedMemory),0666|IPC_CREAT);
	if (shmid==-1)
	{
		printf("Error in creating the Shared Memory!!!\n");
		exit(0);
	}
	shared=(struct sharedMemory *)shmat(shmid,NULL,0);
	int i=1;
	while(1){
		sleep(rand()%5);
		sem_wait(&shared->wrt);
		int n=rand()%100;
		printf("Writer %d is writing a new value\n",i);
		printf("Original Value %d\n",shared->data);
		printf("New Value %d\n\n",n);
		shared->data=n;
		i++;
		sem_post(&shared->wrt);
	}
	return 0;
}
