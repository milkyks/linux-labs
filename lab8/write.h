#pragma once

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

#include "device.h"
#include "command-analysis.h"

static ssize_t device_write(struct file *filp, const char *buffer, size_t length, loff_t * offset)
{
  #ifdef DEBUG
    printk(KERN_INFO "device_write(%p,%s,%d)", file, buffer, length);
  #endif

  size_t actualLength;
  int i;

  actualLength = (length < BUF_LEN) ? length : BUF_LEN;

  if (analysCommand(buffer) == 11)
  {
    printk(KERN_INFO "Delete file");
    buffer = "";
  }

  if (analysCommand(buffer) == 14)
  { 
    printk(KERN_INFO "Backward direction");

    for (i = 0; i < actualLength; i++)
    {
      get_user(msg[actualLength - i - 1], buffer + i);
    }
       
  }
  else
  {
    printk(KERN_INFO "Forward direction");

    for (i = 0; i < actualLength; i++)
    {
      get_user(msg[i], buffer + i);
    }
  }

  msg_Ptr = msg;
  return i;
}
