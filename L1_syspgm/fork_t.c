#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

static int idata = 111;
int main(int argc, char *argv[])
{
	int istack = 222;
	pid_t childPid;
	/* Allocated in data segment */
	/* Allocated in stack segment */
	switch (childPid = fork()) {
		case -1:
			perror("fork");
		case 0:
			idata *= 3;
			istack *= 3;
			break;
		default:
			sleep(3);
			break;
	}
	/* Give child a chance to execute */
	/* Both parent and child come here */
	printf("PID=%ld %s idata=%d istack=%d\n", (long) getpid(),
			(childPid == 0) ? "(child) " : "(parent)", idata, istack);
	exit(EXIT_SUCCESS);
}
