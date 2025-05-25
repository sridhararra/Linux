#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
clock_t t1,t2;

t1=clock();
sleep(10);
t2=clock();
printf("%d\n",((double)(t2-t1))/CLOCKS_PER_SEC);

}
