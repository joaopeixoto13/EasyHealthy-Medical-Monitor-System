obj-m := buzzer.o
buzzer-objs:= buzzermodule.o CGPIO.o
KDIR := "/home/diogo/buildroot/buildroot-2022.02.7/output/build/linux-custom"
ARCH ?= arm

CROSS_COMPILE ?= /home/diogo/buildroot/buildroot-2022.02.7/output/host/bin/arm-buildroot-linux-gnueabihf-

export ARCH CROSS_COMPILE

KBUILD_TARGETS	:= clean help modules modules_install

.PHONY: all $(KBUILD_TARGETS)

all: modules
$(KBUILD_TARGETS):
	$(MAKE) -C ${KDIR} M="$(shell pwd)" $@
	cp buzzer.ko /home/diogo/Projects/EasyHealthy/EasyHealthy/EasyHealthy/DeviceDrivers/
	mkdir -p /home/diogo/Projects/EasyHealthy/bin
	cp buzzer.ko /home/diogo/Projects/EasyHealthy/bin
