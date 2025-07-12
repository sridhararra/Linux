#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_attr_t attr;

void start_func(void *arg)
{

	size_t sz1;
	int a[134217728];
	int b[83886092] = { 0 };

	for (int i = 0; i < 8388609; i++) {

		a[i] = i * 1;
		b[i] = i * (i + 1);
	}
	pthread_attr_getstacksize(&attr, &sz1);

	printf("The thread stack size is %d\n", sz1);
	pause();
	pthread_exit(NULL);

}

int main()
{
	pthread_t tid;

	size_t sz;
	int status;

	pthread_attr_init(&attr);

	pthread_attr_getstacksize(&attr, &sz);

	printf("The sz is %d\n", sz);

	pthread_create(&tid, &attr, start_func, NULL);

	pthread_join(tid, &status);

	return 0;
}
