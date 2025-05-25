#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv)
{
	void *ptr = NULL;
	void *dest, *src = "abcdefghij";
void *adbit = (void *)0xffffffffff60100;
	int n = strlen(src);

	ptr = malloc(100);

	if (!ptr) {
		perror("allocation failed");

	}

	if (argc == 1)
		dest = ptr;
	else
		dest = adbit;

	memcpy(dest, src, n);
printf("%s", (char *)dest);
	free(ptr);
	return 0;
}
