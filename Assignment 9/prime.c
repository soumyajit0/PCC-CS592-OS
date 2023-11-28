#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<math.h>

void *isPrime(void *arg);

int main()
{
	pthread_t t;
	int n;
	printf("Enter the no. to check for Prime No. : ");
	scanf("%d",&n);
	pthread_create(&t,NULL,isPrime,(void *)&n);
	pthread_join(t,NULL);
}

void *isPrime(void *arg)
{
	int n=*((int *)arg);
	if (n==1)
	{
		printf("Not a Prime no.\n");
		pthread_exit(NULL);
	}
	int i,c=0;
	for(i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
		{
			printf("Not a Prime No.\n");
			pthread_exit(NULL);
		}
	}
	printf("Prime No.\n");
	pthread_exit(NULL);
}
