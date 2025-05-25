#include<stdio.h>
#include<unistd.h>

/*
 *
 * sysconf - get configuration information at run time
 * man 3 sysconf
 */
int main() {

printf("page size is %ld\n", sysconf(_SC_PAGESIZE));

return 0;
}
