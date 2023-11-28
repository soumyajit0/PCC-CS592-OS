#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int sum;

void *threadfunction(void *arg)
{
	int n=*((int *)arg);
	sum=(n*(n+1))/2;
	pthread_exit(&sum);
}

int main()
{
	int n;
	printf("Enter the value of n : ");
	scanf("%d",&n);
	pthread_t t;
	void *res;
	pthread_create(&t,NULL,threadfunction,(void *)&n);
	pthread_join(t,&res);
	printf("The Summation of %d Natural No.s is %d\n",n,*((int *)res));
}
