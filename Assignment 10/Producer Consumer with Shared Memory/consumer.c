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

int main()
{
	key_t key=ftok("memory",2832);
	int shmid=shmget(key,sizeof(struct sharedMemory),0666|IPC_CREAT);
	shared=(struct sharedMemory *)shmat(shmid,NULL,0);
	int size=shared->buffersize;
	shared->out=0;
	while(shared->term!=1)
	{
		sleep(rand()%5);
		sem_wait(&shared->full);
		sem_wait(&shared->mutex);
		if(shared->in!=shared->out)
		{
			int n=shared->buffer[shared->out];
			shared->out=(shared->out+1)%size;
			printf("%d is consumed\n",n);
		}
		sem_post(&shared->mutex);
		sem_post(&shared->empty);
	}
	sem_destroy(&shared->mutex);
	sem_destroy(&shared->full);
	sem_destroy(&shared->empty);
	shmdt(shared);
	return 0;
}
