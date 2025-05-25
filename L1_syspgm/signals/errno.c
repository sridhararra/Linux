#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>

int main(){
int fd= open("file1.txt", O_RDWR);
if(fd==-1){

perror("Open failed");
return -1;
}
else{

printf("Succes\n");
}
return 0;
}
