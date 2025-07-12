#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void count(void *arg)
{

	for (int i = 0;; i++) {

		if (i == 100000)
			pthread_testcancel();
	}
}

int main()
{
	pthread_t t1;
	int res;

	pthread_create(&t1, NULL, count, NULL);

	sleep(5);
	pthread_cancel(t1);

	pthread_join(t1, &res);
	if (res == PTHREAD_CANCELED)
		printf("Thread canceled\n");
	else
		printf("thread has no cancel point, res:%d\n", res);
	return 0;
}
