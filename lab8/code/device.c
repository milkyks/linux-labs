#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

#include "device.h"
#include "read.h"
#include "write.h"

int init_module(void)
{
  major_num = register_chrdev(0, DEVICE_NAME, &fops);

  if (major_num < 0)
  {
    printk(KERN_ALERT "Registering device failed with %d\n", major_num);
    return major_num;
  }

  printk(KERN_INFO "'Making a node /dev/%s c %d 0'.\n", DEVICE_NAME, major_num);
  return SUCCESS;
}

void cleanup_module(void)
{
  unregister_chrdev(major_num, DEVICE_NAME);
}

static int device_open(struct inode *inode, struct file *file)
{
  if (numberOfOpens)
  {
    return -EBUSY;
  }

  numberOfOpens++;
  msg_Ptr = msg;
  try_module_get(THIS_MODULE);
  
  return SUCCESS;
}

static int device_release(struct inode *inode, struct file *file)
{
  numberOfOpens--;
  module_put(THIS_MODULE);
  return 0;
}
