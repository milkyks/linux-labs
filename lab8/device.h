#pragma once

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

//int init_module(void);
//void cleanup_module(void);

static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);

int analysCommand(const char*);

#define SUCCESS 0
#define DEVICE_NAME "device"
#define BUF_LEN 80

static int major_num;
static int numberOfOpens = 0;

static char msg[BUF_LEN];
static char *msg_Ptr;

static struct file_operations fops = {
  .read = device_read,
  .write = device_write,
  .open = device_open,
  .release = device_release
};
