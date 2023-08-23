# where_are_my_files

一个小工具，可以用于寻找内核中一些结构体成员的偏移量。

该内核模块仅几行代码，并且没有任何危险操作（其实连操作都没有，不信你看代码），可以放心加载到任何内核中。

目前支持的偏移量显示：
1. `struct task_struct`中成员`files`的偏移量。
2. `struct file`中成员`f_op`的偏移量。
3. `struct file`中成员`private_data`的偏移量。

开发eBPF可观测系统并且内核没有BTF时，会用到此工具。

## 使用方法

```bash
# 拉代码
git clone https://github.com/ic0xgkk/where_are_my_files.git
cd where_are_my_files
# 编译
make build
# 安装模块
make install
# 加载模块
modprobe wamf
# 卸载模块
rmmod wamf
# 查看输出
dmesg | grep wamf
```

在`dmesg`中，就可以看到输出了。
```bash
# dmesg | grep wamf
[621994.500286] wamf: task_struct->files_struct(files) offset: 3048, task_struct size: 9792 
[621994.500552] wamf: file->file_operations(f_op) offset: 40, file size: 232 
[621994.500749] wamf: file->void *(private_data) offset: 200, file size: 232
```

完成上边的命令后（尤其记得执行`rmmod`卸载），就可以删除了。
