
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
	int ret = 0;

	if (elfhead_address != NOT_KDUMP_SETUP) {
		pr_err("the 2 kernel is booting after not panic\n");
		pr_err("Bye, haha!!\n");
		BUG();
	}

	ret = sysfs_create_file(NULL, &type_attr);
	WARN_ON(ret);

	return ret;
}

core_initcall(capturekernel_startpoint); 
