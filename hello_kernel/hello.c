#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

static int major_number;

static ssize_t my_read(struct file *f, char __user *c, size_t l, loff_t *o){
    pr_info("hello_cdev - Read called\n");
    return 0;
}

static struct file_operations _file_ops = {
    .read = my_read
    };

static int __init my_init(void){

    major_number = register_chrdev(0, "hello_cdev", &_file_ops);
    if(major_number < 0){
        pr_err("hello_cdev - Error registering chracter device\n");
        return major_number;
    }

    pr_info("hello_cdev - Major number is %d\n", major_number);
    return 0;
}

static void __exit my_exit(void){
    unregister_chrdev(major_number, "hello_cdev");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Emine Durmuşkaya <eminedurmuskaya123@gmail.com>");
MODULE_DESCRIPTION("A simple hello world linux kernel module");