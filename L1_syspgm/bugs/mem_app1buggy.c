#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){

void *src="abcdefgh";
void *dest;

void *bad_addr="0xfffffffffffffabc";


if (argc==1)
    dest=malloc(256*1024);
else
    dest=bad_addr;

memcpy(dest, src, strlen(src));


printf("dest is %s\n",dest);

return 0;
}
