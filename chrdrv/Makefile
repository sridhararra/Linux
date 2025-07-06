obj-m += misc.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) CC=gcc-12 modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) CC=gcc-12 clean

