# where_are_my_files

一个小工具，可以用于寻找内核中`struct task_struct`中成员`files`的偏移量。

该内核模块仅几行代码，并且没有任何危险操作（其实连操作都没有，不信你看代码），可以放心加载到任何内核中。加载该内核模块后，即可在`dmesg`中输出该内核中`struct task_struct`中成员`files`的偏移量，开发eBPF可观测系统并且内核没有BTF时，会用到此工具。

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
dmesg | grep files_struct
```

在`dmesg`中，就可以看到输出了。
```bash
[529733.371443] files_struct offset: 3048, task_struct size: 9792
```

完成上边的命令后（尤其记得执行`rmmod`卸载），就可以删除了。
