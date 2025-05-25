#include<stdio.h>

int getreg(void)
{
	__asm__("movq $5, %rcx");
	__asm__("movq %rcx, %rax");
}

int main()
{
	printf("the value of getreg is %d\n", getreg());

	return 0;
}
