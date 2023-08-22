#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

static int __init mod_init(void)
{
	struct task_struct task;

	unsigned long long begin = (unsigned long long)&task;
	unsigned long long end = (unsigned long long)&task.files;
	unsigned long long offset = end - begin;
	unsigned long long size = (unsigned long long)sizeof(task);

	pr_info("files_struct offset: %llu, task_struct size: %llu \n", offset, size);

	return 0;
}

static void __exit mod_exit(void) {}

module_init(mod_init);
module_exit(mod_exit);
MODULE_LICENSE("Dual MIT/GPL");
MODULE_DESCRIPTION("Get files_struct offset in task_struct.");
MODULE_AUTHOR("Harris Ice <ic0xgkk@gmail.com>");
MODULE_VERSION("0.1");
