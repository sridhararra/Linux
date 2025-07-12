#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define MAX_THREAD 1000

void start_func(void *i){

    int val=*(int *)i;

    printf("this is thread %d\n", val);
}

int main(int  argc, char **argv){
    pthread_t *thd;

    if(argc!=2) {
        printf("Invalid no of arguments");
        return -1;
    }

    int numThd=atoi(argv[1]);

    if(numThd<=0 || numThd>MAX_THREAD){
printf("please check the thread count range");
        return -1;
    }
    thd=(pthread_t *)malloc(sizeof(pthread_t)*numThd);


    for(int i = 0;i<numThd;i++){

        pthread_create(&thd[i], NULL, start_func, &i);

    }

// Free shoud be called before pthread_exit().. otherwise lsan will catch it
    free(thd);
    pthread_exit(NULL);


    return 0;
}
