#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
	char c[100];
	int s,n;
	int fd=open("namedpipe",O_WRONLY);
	printf("Enter a String : ");
	scanf("%s",c);
	printf("Enter the Starting Index : ");
	scanf("%d",&s);
	printf("Enter no. of Characters : ");
	scanf("%d",&n);
	write(fd,c,strlen(c)+1);
	write(fd,&s,sizeof(int));
	write(fd,&n,sizeof(int));
	close(fd);
	fd=open("namedpipe",O_RDONLY);
	read(fd,c,100);
	printf("The final String is : %s\n",c);
	close(fd);
	return 0;
}
