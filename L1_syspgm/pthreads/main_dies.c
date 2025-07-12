/*
 * main dies before the threads it created. see the behavior
 *
 * sridhar@sridhar:~/mywork/Linux/L1_syspgm/pthreads$
sridhar@sridhar:~/mywork/Linux/L1_syspgm/pthreads$ ps -lL
F S   UID     PID    PPID     LWP  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1000    2780    2762    2780  0  80   0 -  3012 do_wai pts/0    00:00:00 bash
0 S  1000   57450    2780   57450  0  80   0 - 21176 hrtime pts/0    00:00:00 main_dies
1 S  1000   57450    2780   57451  0  80   0 - 21176 do_sys pts/0    00:00:00 main_dies
1 S  1000   57450    2780   57452  0  80   0 - 21176 do_sys pts/0    00:00:00 main_dies
4 R  1000   57469    2780   57469  0  80   0 -  3168 -      pts/0    00:00:00 ps
sridhar@sridhar:~/mywork/Linux/L1_syspgm/pthreads$ ps -lL
F S   UID     PID    PPID     LWP  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1000    2780    2762    2780  0  80   0 -  3012 do_wai pts/0    00:00:00 bash
0 Z  1000   57450    2780   57450  0  80   0 -     0 -      pts/0    00:00:00 main_dies <defunct>
1 S  1000   57450    2780   57451  0  80   0 - 21208 do_sys pts/0    00:00:00 main_dies
1 S  1000   57450    2780   57452  0  80   0 - 21208 do_sys pts/0    00:00:00 main_dies
4 R  1000   57473    2780   57473  0  80   0 -  3168 -      pts/0    00:00:00 ps
sridhar@sridhar:~/mywork/Linux/L1_syspgm/pthreads$

 */

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void start_func(void *arg)
{

	printf("The thread is %d\n", arg);
	pause();
}

int main(int argc, char **argv)
{
	pthread_t *thd;

	int num_thread;

	if (argc != 2)
		return -1;

	num_thread = argc;

	thd = (pthread_t *) malloc(sizeof(pthread_t) * num_thread);

	for (int i = 0; i < num_thread; i++) {

		pthread_create(&thd[i], NULL, start_func, (void *)i);

	}

	sleep(10);
	pthread_exit(NULL);

	return 0;
}
