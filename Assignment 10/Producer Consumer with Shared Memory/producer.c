#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<math.h>
#include<signal.h>
#include<unistd.h>

#define MAX 100

struct sharedMemory
{
	int term;
	int buffer[MAX];
	sem_t mutex,full,empty;
	int in,out;
	int buffersize;
};

struct sharedMemory *shared;

void customHandler(int signum)
{
	int signal=signum;
	shared->term=1;
	printf("Producer Terminated!!!\n");
	exit(0);
}

int main()
{
	signal(SIGINT,customHandler);
	key_t key=ftok("memory",2832);
	int shmid=shmget(key,sizeof(struct sharedMemory),0666|IPC_CREAT);
	shared=(struct sharedMemory *)shmat(shmid,NULL,0);
	int size;
	printf("Enter the size of the Buffer : ");
	scanf("%d",&size);
	shared->buffersize=size;
	sem_init(&shared->mutex,1,1);
	sem_init(&shared->full,1,0);
	sem_init(&shared->empty,1,size);
	shared->in=0;
	while (1)
	{
		sleep(rand()%2);
		sem_wait(&shared->empty);
		sem_wait(&shared->mutex);
		int n=rand()%100;
		shared->buffer[shared->in]=n;
		shared->in=(shared->in+1)%size;
		printf("%d is produced\n",n);
		sem_post(&shared->mutex);
		sem_post(&shared->full);
	}
	return 0;
}
