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

int main()
{
	key_t key=ftok("memory",2832);
	int shmid=shmget(key,sizeof(struct sharedMemory),0666|IPC_CREAT);
	if (shmid==-1)
	{
		printf("Error in creating the Shared Memory!!!\n");
		exit(0);
	}
	shared=(struct sharedMemory *)shmat(shmid,NULL,0);
	sem_init(&shared->mutex,1,1);
	sem_init(&shared->wrt,1,1);
	int i=1,readerCount=0;
	shared->term=0;
	shared->data=0;
	while(shared->term!=1){
		sleep(1);
		sem_wait(&shared->mutex);
		readerCount++;
		if (readerCount==1)
		{
			sem_wait(&shared->wrt);
		}
		sem_post(&shared->mutex);
		printf("Reader %d reads the value %d\n",i,shared->data);
		sem_wait(&shared->mutex);
		readerCount--;
		if (readerCount==0)
		{
			sem_post(&shared->wrt);
		}
		sem_post(&shared->mutex);
		i++;
	}
	sem_destroy(&shared->mutex);
	sem_destroy(&shared->wrt);
	shmdt(shared);
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
