
/*
	The default value is -1, otherwise, 
	it means that the second capture kernel was started because kdump occurred.
*/
unsigned long long elfhead_address = NOT_KDUMP_SETUP;

static int __init capturekernel_startpoint(void)
{
	int err_val = 0;

	if (elfhead_address != NOT_KDUMP_SETUP) {
		pr_err("the 2 kernel is booting after not panic\n");
		pr_err("Bye, haha!!\n");
		BUG();
	}
}

core_initcall(capturekernel_startpoint); 
