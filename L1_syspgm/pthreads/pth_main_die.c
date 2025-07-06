#include<stdio.h>
#include<pthread.h>

void th_func(void *a){
    /* th_func will also die when main thread exits */
    while(1);
}

int main(){
    pthread_t tid;


    pthread_create(&tid, NULL, th_func, NULL);
    sleep(10);

    return 0;
}
