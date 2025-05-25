#include<stdio.h>
#include<pthread.h>

void start_func(void *arg){

return;
}

int main(){

int k  = 50000;
pthread_t t[50000];

for(int i=0;i<k;i++){

pthread_create(&t[i], NULL, start_func, NULL);
}

return 0;
}
