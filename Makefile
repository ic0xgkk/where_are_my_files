obj-m := wamf.o
wamf-y := main.o

KERNEL_VERSION = $(shell uname -r)
KDIR = /lib/modules/${KERNEL_VERSION}/build

build:
	@echo "Building for kernel version $(KERNEL_VERSION)"
	@make -C ${KDIR} M=$(PWD) modules
install:
	@echo "Installing for kernel version $(KERNEL_VERSION)"
	@make -C ${KDIR} M=$(PWD) modules_install
	@depmod -A
uninstall:
	@echo "Uninstalling for kernel version $(KERNEL_VERSION)"
	@rm -f /lib/modules/${KERNEL_VERSION}/extra/wamf.ko
	@depmod -a ${KERNEL_VERSION}
clean:
	@make -C ${KDIR} M=$(PWD) clean
