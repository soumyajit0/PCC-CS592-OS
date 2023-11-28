#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

sem_t mutex;

void *ba(void *arg);
void *ab(void *arg);

int main()
{
	pthread_t t1,t2;
	sem_init(&mutex,0,1);
	int i=1;
	for(i=1;i<=3;i++)
	{
		pthread_create(&t1,NULL,ba,NULL);
		pthread_join(t1,NULL);
		pthread_create(&t2,NULL,ab,NULL);
		pthread_join(t2,NULL);
	}
	sem_destroy(&mutex);
	printf("\n");
}

void *ba(void *arg)
{
	sem_post(&mutex);
	printf("ba");
	sem_wait(&mutex);
	pthread_exit(NULL);
}

void *ab(void *arg)
{
	sem_post(&mutex);
	printf("ab");
	sem_wait(&mutex);
	pthread_exit(NULL);
}

