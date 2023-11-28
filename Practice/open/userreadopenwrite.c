#include<fcntl.h>
#include<unistd.h>

int main()
{
	char c[100];
	int n=read(0,c,100);
	int fd=open("file.txt",O_CREAT|O_WRONLY,0642);
	write(fd,c,n);
}
