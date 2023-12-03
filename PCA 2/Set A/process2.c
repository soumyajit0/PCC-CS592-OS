#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<ctype.h>

int main(){
	char c[100];
	int s,n;
	int fd=open("namedpipe",O_RDONLY);
	read(fd,c,100);
	read(fd,&s,sizeof(int));
	read(fd,&n,sizeof(int));
	close(fd);
	int i;
	for(i=s;i<=(s+n-1);i++){
		c[i]=toupper(c[i]);
	}
	fd=open("namedpipe",O_WRONLY);
	write(fd,c,strlen(c)+1);
	close(fd);
	return 0;
}
