#pragma once

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include "device.h"

static ssize_t device_read(struct file *filp, char *buffer, size_t length, loff_t *offset)
{
  int bytes_read = 0;
  
  if (*msg_Ptr == 0)
  {
    return 0;
  }
  
  while (length && *msg_Ptr)
  {
    put_user(*(msg_Ptr++), buffer++);
    length--;
    bytes_read++;
  }

  return bytes_read;
}
