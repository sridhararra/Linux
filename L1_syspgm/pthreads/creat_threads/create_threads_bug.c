#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

/* if the global var a is uncommented and ran with tsan
 * you can detect the data race
 */

//int a=0;
void start_func(void *val){
//a++;
//    printf("The ths id %d, a:%d\n", val, a);
    printf("The ths id %d\n", val);
    pause();

}

int main(int argc, char **argv){
    pthread_t thd[5];

    if(argc!=2){

        printf("Invalid no of args\n");
        return -1;
    }

    int numThd = atoi(argv[1]);
    if(numThd<0 || numThd > 1000){

        printf("check the thread count properly\n");
        return -1;
    }
    for(int i = 0;i<numThd;i++){

        pthread_create(&thd[i],NULL, start_func, (void *)i);


    }

    pause();
    pthread_exit(NULL);


    return 0;
}
