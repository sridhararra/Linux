#include<stdio.h>
#include<unistd.h>

void foo3()
{
	pause();
}

void foo2()
{
	foo3();
}

void foo1()
{

	foo2();
}

void foo()
{
	foo1();
}

int main()
{
	foo();
	return 0;
}
