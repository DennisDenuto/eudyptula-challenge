#include <linux/module.h>
#include <linux/init.h>

#include <linux/slab.h>			/* kmalloc() */
#include <linux/usb.h>			/* USB stuff */
#include <linux/mutex.h>		/* mutexes */
#include <linux/ioctl.h>

#include <asm/uaccess.h>		



struct usb_connected_devicel {
    /* One structure for each connected device */
};

// idVendor           0x05ac Apple, Inc.
//  idProduct          0x12a8 iPhone5/5C/5S/6
static struct usb_device_id ml_table [] = {
    { USB_DEVICE(0x05ac, 0x12a8) },
    { }
};

static int ml_open(struct inode *inode, struct file *file)
{
  	struct usb_interface *interface;

    /* open syscall */
    printk( KERN_DEBUG "[info]  m1_open called");
    int subminor;
    subminor = iminor(inode);
    // interface = usb_find_interface(&ml_driver, subminor);

    return 0;
}
static int ml_release(struct inode *inode, struct file *file)
{
    /* close syscall */
  	printk( KERN_DEBUG "[info]  m1_release called");
    return 0;
}

static ssize_t ml_write(struct file *file, const char __user *user_buf, size_t count, loff_t *ppos)
{
    /* write syscall */
  	printk( KERN_DEBUG "[info]  m1_write called");
    return 0;
}

static struct file_operations ml_fops = {
    .owner =    THIS_MODULE,
    .write =    ml_write,
    .open =     ml_open,
    .release =  ml_release,
};

static int ml_probe(struct usb_interface *interface, const struct usb_device_id
        *id)
{
    /* called when a USB device is connected to the computer. */
  	printk( KERN_DEBUG "[info]  m1_probe called");
    return 0;
}

static void ml_disconnect(struct usb_interface *interface)
{
    /* called when unplugging a USB device. */
  	printk( KERN_DEBUG "[info]  m1_disconnect called");
}

static struct usb_driver ml_driver = {
    .name = "some_usb_device",
    .id_table = ml_table,
    .probe = ml_probe,
    .disconnect = ml_disconnect,
};

static int __init usb_ml_init(void)
{
    /* called on module loading */
  	printk( KERN_DEBUG "[info]  init called");
	int result;

	result = usb_register(&ml_driver);
	if (result) {
		printk( KERN_ERR "[err]  reg driver failed");
	} else {
		printk( KERN_INFO "[info]  reg driver all good");
	}

	return result;
    return 0;
}

static void __exit usb_ml_exit(void)
{
    /* called on module unloading */
  	printk( KERN_DEBUG "[info]  unload called");
	usb_deregister(&ml_driver);
    return 0;
}

module_init(usb_ml_init);
module_exit(usb_ml_exit);

MODULE_AUTHOR("Den");
MODULE_LICENSE("GPL");

// EXPORT_SYMBOL_GPL(usb_register_driver);
// EXPORT_SYMBOL_GPL(usb_deregister);
