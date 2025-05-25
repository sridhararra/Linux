#include<stdio.h>
#include<stdlib.h>

int main(int argc, char **argv){
void *ptr = NULL;
void *desc, *src = "abcdefghij";

int n = strlen(src);

ptr=malloc(100);

if(!ptr){
perror("allocation failed");

}

if(argc==1)
dest=ptr;
else
dest=(void*)0xhfhkngf;

memcpy(dest, src, n);
free(ptr);
return 0;
}
