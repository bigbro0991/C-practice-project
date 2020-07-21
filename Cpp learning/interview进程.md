#### 计算机环境

虚拟机：VMM 可以看作一个host OS 来管理其他的VM kernel

云计算：通过网络提供计算，存储，甚至应用的服务

云计算采用虚拟技术作为基础

SaaS software as a Service

PaaS platform i.e database server

IaaS infrastructure server or storage available over Internet i.e., 百度云存储服务？

网络处理用户的请求，给请求提供云服务接口,通过云管理命令传递给云服务管理模块，然后处理请求（防火墙防止攻击，load balancer 通过不同应用类型将网络traffic分离 ）

#### 操作系统组成：

用户态：API library Compiler and build tools UI(CLI GUI)

内核态：

程序执行模块：将程序load到main memory and run

I/O 操作：一个程序或许需要I/O 服务 文件或者I/O 设备 鼠标等

文件系统

进程之间的交流 shared memory ；socket等

错误探测，debug

资源分配：向多个任务分配资源

安全

#### 系统调用

via API 用c或者c++写的

system call interface 维护了一个index 表 去追踪每一个system call

用户不知道system call 则么用 detals 被hidden by api

参数传递：通过一个参数表 linux Solaris 不限定参数长度

a Daemon 守护进程： 和终端的启动和关闭没有联系 在后台等待请求的进程

系统调用里的交流模式：信息传递模式和内存共享模式 一个传递小信息一个大信息 因为能访问内存



进程控制

MS doS 单任务 FreeBSD 多进程 用 fork 创建新的进程

系统程序中 windows dll 和 linux so文件 可以 帮助程序link到shared memory

#### 进程

a program in execution

Program becomes process when its executable file is loaded into main memory

main memory 被分成几个section: code （text section）

stack lcoal变量 栈区 进程结束释放

堆区 由程序员动态分配  由程序员释放

   data section 包含全局变量啥的

PCB process control block
OS maintain a PCB for every process, in order to save the information of every statement of the process

OS uses PCB to discribe the basic statement and execution processes, PCB is the only one can confirm a process exist

进程的创建：为该进程生成一个PCB
结束：回收PCB

进程控制信息：调度和状态信息 进程间通信信息 存储管理信息 进程所用资源 有关数据结构连接信息
PCB organization ListNode/Array
用链表 因为进程是动态操作的，用链表能更好实现动态的插入和删除

PCB is placed at the beginning of the kernel stack of the process.

进程调度

kernel 尽可能最大化CPU的利用率

进程调度模块就是选择下一个进程进入cpu

进程管理模块维护了一些队列 进程队列 就绪队列 设备队列等

长调度 batch system 决定什么进程需要被admit 放入就绪队列 

控制多任务的等级

短调度决定下一个执行的进程进入cpu

#### 上下文切换

时间是一种额外花销

进程切换并保存当前state在PCB里面 但硬件牛逼的话 时间会缩短



进程创建 

init and kthreadd 没有父进程ppid=0 kernel boots时候就创建了

init是所有user 进程的父亲 kthewadd是所有kernel 进程 的父亲



进程结束后 通过exit() return 子进程状态 且os释放资源

abort() 子进程占用太多资源需要弃用

父进程已经结束 要abort子进程 

Some operating systems do not allow a child to exist if its parent has terminated. Hence, in such systems, if a process terminates, then the OS terminates all its children.

The init process periodically invokes wait in order to release orphan zombie processes.

僵尸进程， 子进程结束 到父进程执行wait的时候 他是僵尸进程 因为分配他的资源被释放 但进程入口还存在

孤儿进程 linux 允许 自己原来的父进程exit 所以 父进程变成了init

所以os需要周期性的调用wait 去释放这些程序