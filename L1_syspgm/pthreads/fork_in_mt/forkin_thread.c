#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

void thread1(void *arg)
{
	printf("Nothing to do in %s\n", __func__);
	pthread_exit(NULL);
}

void thread2(void *arg)
{
	pid_t pid;

	char *file = (char *)arg;

	if (file == NULL) {
		pthread_exit();
	}
	printf("Enter %s\n", __func__);
	pid = fork();

	if (pid < 0) {
		perror("fork failed");
		pthread_exit();
	} else if (pid == 0) {
/* child */
		execl("/usr/bin/evince", "evince PDF reader", file, (char *)0);
		perror("execl failed");

	}
	pthread_exit(NULL);
}

int main(int argc, char **argv)
{
	pthread_t t1, t2;
	
    if (argc != 2) {
		printf("Invalid argument");
		return -1;
	}

	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, (void *)argv[1]);

	pause();
	pthread_exit(NULL);

	return 0;
}
