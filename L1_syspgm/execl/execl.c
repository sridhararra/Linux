#include<stdio.h>
#include<unistd.h>

int main()
{

	printf("The pid of process is :%d\n", getpid());

	execl("/usr/bin/ps", "ps", "-elf", (char *)0);

	printf("The pid of process is %d\n", getpid());

	return 0;
}
