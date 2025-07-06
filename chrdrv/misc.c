#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/kmod.h>


static __init int myinit(void){

    pr_info("This is myinit, %d\n", PATH_MAX);

return 0;
}

static __exit void myexit(void){

pr_info("This is my exit\n");
}

module_init(myinit);
module_exit(myexit);

MODULE_LICENSE("GPL");
