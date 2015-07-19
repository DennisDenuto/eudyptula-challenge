#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("b40a84f");

int init_module(void)
{
	pr_debug("Hello World!");

	return 0;
}

void cleanup_module(void)
{
	pr_debug("Goodbye world.\n");
}
