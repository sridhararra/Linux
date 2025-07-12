#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void count(void *arg){

int j = 0;

for(j=0;;j++){
//printf("%d\n", j);
}
}

int main(){
pthread_t tid;
int res;

pthread_create(&tid, NULL, count, NULL);

sleep(10);


pthread_cancel(tid);

pthread_join(tid, &res);

if(res == PTHREAD_CANCELED){

printf("Thread is cancelled\n");
}
else{
printf("Thread exited normall;y\n");
}
return 0;
}

