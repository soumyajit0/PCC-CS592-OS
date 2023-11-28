#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fdopen=open("file.txt",O_RDONLY);
	char c[100];
	int n=read(fdopen,c,100);
	int fdnew=open("newfile.txt",O_CREAT|O_WRONLY,0642);
	write(fdnew,c,n);
}
