SUBDIRS := hello_kernel
KDIR := /lib/modules/$(shell uname -r)/build

all:
	@for dir in $(SUBDIRS); do \
		make -C $(KDIR) M=$(PWD)/$$dir modules;  \
	done

clean:
	@for dir in $(SUBDIRS); do \
		make -C $(KDIR) M=$(PWD)/$$dir clean;  \
	done

copy:
	mkdir -p build
	@find . -type f -name "*.ko" -exec cp {} build/ \;

clean-build:
	rm -rf build/*.ko

clean-all: clean clean-build