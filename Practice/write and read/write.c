#include<unistd.h>
#include <stdio.h>

int main()
{
	//write(1,"Hello World",11);
	
	/*
	 * fd = > file descriptor
	 * 0 - stdin
	 * 1 - stdout
	 * 2 - stderr
	 *
	 * On successfull execution returns the no. of bytes written
	 *
	 */
	int n=write(1,"Hello World",11);
	printf("\n");
	printf("The value of n is %d",n);
}
