#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<semaphore.h>
#include<math.h>
#include<unistd.h>

#include"buffer.h"

sem_t mutex,full,empty;

void *producer(void *);
void *consumer(void *);

int main()
{
	pthread_t producer_t,consumer_t;
	sem_init(&mutex,0,1);
	sem_init(&full,0,0);
	printf("Enter the size of the Buffer : ");
	int size;
	scanf("%d",&size);
	sem_init(&empty,0,size);
	
	pthread_create(&producer_t,NULL,producer,NULL);
	pthread_create(&consumer_t,NULL,consumer,NULL);

	pthread_join(producer_t,NULL);
	pthread_join(consumer_t,NULL);
	
	sem_destroy(&mutex);
	sem_destroy(&full);
	sem_destroy(&empty);
}

void *producer(void *arg)
{
	while(1)
	{
		sem_wait(&empty);
		sem_wait(&mutex);
		// srand(time(NULL));
		sleep(rand()%2);
		int item=rand()%100;
		insert(item);
		printf("%d is produced\n",item);
		sem_post(&mutex);
		sem_post(&full);
		sleep(1);
	}
	pthread_exit(NULL);
}

void *consumer(void *arg)
{
	while(1)
	{
		sem_wait(&full);
		sem_wait(&mutex);
		sleep(rand()%5);
		if (buffer!=NULL)
		{
			int item=buffer->data;
			delete();
			printf("%d is consumed\n",item);
		}
		sem_post(&mutex);
		sem_post(&empty);
		sleep(1);
	}
	pthread_exit(NULL);
}
