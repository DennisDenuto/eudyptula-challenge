/*
 *  hello-1.c - The simplest kernel module.
 */
#include <linux/module.h>
#include <linux/kernel.h>

int init_module(void)
{
	printk(KERN_DEBUG "Hello World! 1.\n");

	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Goodbye world 1.\n");
}
