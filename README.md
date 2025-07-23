# linux_device_drivers
Linux device driver development

sudo insmod hello.ko

sudo mknod /dev/hello0 c major_num 0

sudo rmmod hello.ko

ls -lh

https://elixir.bootlin.com/linux/v6.15.7/source/include/linux/fs.h#L2129


for guidelines linux-x.x.x/scripts/checkpatch.pl

linux-x.x.x/scripts/checkpatch.pl -f file_path

sudo dmesg -l log_level

sudo dmesg -W