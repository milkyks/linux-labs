#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/workqueue.h>
#include <linux/interrupt.h>
#include <asm/io.h>

static unsigned char scancode;
static struct work_struct *hardwork;

static void got_char(struct work_struct *hadrwork);
static DECLARE_WORK(create_work, got_char);

static irqreturn_t irq_handler(int iqr, void *dev_id)
{
	scancode = inb(0x60);
	schedule_work(&create_work);
	return IRQ_HANDLED;
}


static void got_char(struct work_struct *hardwork)
{
	printk(KERN_INFO "Scancode %x %s\n", 
			scancode & 0x7F, 
			scancode & 0x80 ? "Released" : "Pressed");
}

int init_module(void)
{
	return request_irq(1, 
			   irq_handler,
			   IRQF_SHARED, 
			   "test_keyboard_irq_handler", 
			   &scancode);
}

void cleanup_module(void)
{
	free_irq(1, &scancode);
}


