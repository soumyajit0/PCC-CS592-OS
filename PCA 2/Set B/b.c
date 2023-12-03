#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>
#include<ctype.h>

void custominterrupt(int signum){
	printf("Interrupt received : %d\n",signum);
	exit(0);
}

void customalarm(int signum){

}

void customchild(int signum){

}

int main(){
	signal(SIGINT,custominterrupt);
	signal(SIGALRM,customalarm);
	signal(SIGCHLD,customchild);
	pid_t p=fork();
	if (p<0){
		printf("Error in creating the Child Process\n");
		exit(0);
	}
	else if (p==0){
		while(1){
			pause();
			char c[100];
			printf("Enter a String : ");
			scanf("%s",c);
			int i;
			for(i=0;i<strlen(c);i++){
				if (i%2==0){
					c[i]=tolower(c[i]);
				}
				else{
					c[i]=toupper(c[i]);
				}
			}
			printf("%s\n",c);
			printf("Sending completion Signal to Parent Process : %d\n",getppid());
			kill(getppid(),SIGALRM);
		}
	}
	else{
		while(1){
			printf("Sending Signal to Child Process : %d\n",p);
			kill(p,SIGCHLD);
			pause();
			sleep(10);
		}	
	}
}
