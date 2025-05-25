#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>   // for memset
#include<sys/types.h>

void handler(int num) {
    printf("Inside handler from pid: %d\n", getpid());
sleep(2);
}

int main() {
    struct sigaction act;
    pid_t pid;

    memset(&act, 0, sizeof(act));
    act.sa_handler = handler;
    act.sa_flags = SA_NODEFER;

sigfillset(&act.sa_mask);

    sigaction(SIGINT, &act, NULL);
while(1);
    return 0;
}

