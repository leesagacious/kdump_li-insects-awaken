#include <linux/errno.h>

/*
	Each item on the linked list is a memory range that crashes the kernel memory
*/
static struct list_head targets = LIST_HEAD_INIT(crash_memory_range);

/*
	The default value is -1, otherwise, 
	it means that the second capture kernel was started because kdump occurred.
*/
unsigned long long elfhead_address = NOT_KDUMP_SETUP;

static ssize_t type_show(struct kobject *kobj,
                         struct kobj_attribute *attr, char *buf)
{
        return 0;
}

static struct kobj_attribute type_attr = __ATTR_RO(type);

static int __init capturekernel_startpoint(void)
{
	int ret;

	if (elfhead_address != NOT_KDUMP_SETUP) {
		pr_err("the 2 kernel is booting after not panic ! Bye Bye haha. \n");
		return -EINVAL;
		BUG();
	}

	ret = sysfs_create_file(NULL, &type_attr);
	WARN_ON(ret);

	return ret;
}

core_initcall(capturekernel_startpoint); 
