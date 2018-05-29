
kmod = roboFinger
ifneq ($(KERNELRELEASE),)
obj-m := $(kmod).o
else

KDIR ?= /lib/modules/$$(uname -r)/build

all:
	$(MAKE) -C $(KDIR) M=$$PWD modules
	sudo cp 99-robofinger.rules /etc/udev/rules.d/
	sudo udevadm control --reload-rules && udevadm trigger

load:
	sudo insmod $(kmod).ko

unload:
	sudo rmmod $(kmod).ko

clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean

read:
	tail -f /var/log/kern.log 

.PHONY  : clean
endif