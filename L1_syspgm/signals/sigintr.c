#include<stdio.h>
#include<signal.h>
void handler(int signum){
printf("Inside sighandler\n");
sleep(15);
return;
}
int main(){
printf("Now hit ctrl c\n");
signal(SIGINT, handler);
sleep(20);
return 0;
}
