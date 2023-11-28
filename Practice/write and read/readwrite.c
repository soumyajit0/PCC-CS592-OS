#include<unistd.h>
#include<stdio.h>

int main()
{
	char c[100];
	int n=read(0,c,100);
	write(1,c,n);
}
