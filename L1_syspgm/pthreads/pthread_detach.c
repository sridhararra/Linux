#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void start_func(void *arg)
{

	printf("Inside thread 1");
}

int main()
{

	pthread_t t1;
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	pthread_create(&t1, &attr, start_func, NULL);

	pthread_attr_destroy(&attr);

	sleep(10);

	return 0;
}
