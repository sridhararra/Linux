#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	pid_t pid;

	pid = fork();

	switch (pid) {
	case -1:
		perror("Failed");
		exit(1);
	case 0:
		printf("This is child\n");
		sleep(5);
		exit(0);
		break;
	default:
		printf("This is parent\n");
		sleep(10);
		exit(0);
		break;

	}

	return 0;
}
