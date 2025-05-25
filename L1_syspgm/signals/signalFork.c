#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void handler(int num){
	printf("Inside handler from pid:%d\n", getpid());
return;
}

int main(){
	struct sigaction act;
	pid_t pid;
memset(&act, 0, sizeof(act));
	act.sa_handler=handler;

	sigaction(SIGINT, &act, NULL);

	pid=fork();
	if(pid==-1)
		perror("Failed to fork\n");
	else if(pid==0)
	{
		printf("Inside child\n");
		raise(SIGINT);
		sleep(20);
	}
	else {
		printf("In parent, while\n");
		sleep(40);
	}
	return 0;
}

