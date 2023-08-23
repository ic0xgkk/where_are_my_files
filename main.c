#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/fs.h>

static int __init mod_init(void)
{
	unsigned long long begin, end, offset, size;

	struct task_struct task;
	begin = (unsigned long long)&task;
	end = (unsigned long long)&task.files;
	offset = end - begin;
	size = (unsigned long long)sizeof(task);
	pr_info("wamf: task_struct->files_struct(files) offset: %llu, task_struct size: %llu \n", offset, size);

	struct file file;
	begin = (unsigned long long)&file;
	end = (unsigned long long)&file.f_op;
	offset = end - begin;
	size = (unsigned long long)sizeof(file);
	pr_info("wamf: file->file_operations(f_op) offset: %llu, file size: %llu \n", offset, size);

	end = (unsigned long long)&file.private_data;
	offset = end - begin;
	pr_info("wamf: file->void *(private_data) offset: %llu, file size: %llu \n", offset, size);

	return 0;
}

static void __exit mod_exit(void) {}

module_init(mod_init);
module_exit(mod_exit);
MODULE_LICENSE("Dual MIT/GPL");
MODULE_DESCRIPTION("Get files_struct offset in task_struct.");
MODULE_AUTHOR("Harris Ice <ic0xgkk@gmail.com>");
MODULE_VERSION("0.1");
