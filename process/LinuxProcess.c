/*
 * 文件名: LinuxProcess.c
 * 作者: ljk
 * 创建时间: 2023-07-23
 * 文件描述: 进程操作例程
 */
#include "../common.h"




// 创建子进程
int fun_fork()
{
    pid_t pid;    // 用于存储 fork 返回值，表示进程 ID
    pid = fork(); // 创建子进程

    if (pid < 0) 
    {
        // 创建子进程失败
        fprintf(stderr, "Fork failed.\n");
        return 1;
    } 
    else if (pid == 0) 
    {
        // 子进程
        printf("Hello from the child process! (Child PID: %d, Parent PID: %d)\n", getpid(), getppid());
    } 
    else 
    {
        // 父进程
        printf("Hello from the parent process! (Child PID: %d)\n", pid);
        wait(NULL); // 等待子进程结束
        printf("Child process has terminated.\n");
    }

    // 这里的代码将被父进程和子进程共同执行
    printf("fork hello...\n");

    return 0;
}

pid_t gettid(void)
{
    return syscall(SYS_gettid);
}

// 获取线程、进程ID
int fun_getID()
{
    pid_t pid  = getpid();  // 进程ID
    pid_t ppid = getppid(); // 父进程ID
    pid_t pgid = getpgrp(); // 进程组ID
    pid_t tid  = gettid();  // 线程ID
    
    printf("进程ID:   %d\n", pid);
    printf("父进程ID: %d\n", ppid);
    printf("进程组ID: %d\n", pgid);
    printf("T线程ID:  %d\n", tid);
    printf("主线程ID: %d\n", pid); // 主线程 ID 就是进程 ID
    return 0;
}




// 测试程序
int main(int argc, char* argv[])
{
    printf("__[fun_fork() test]__\n");
    fun_fork();
    printf("__[fun_getID() test]__\n");
    fun_getID();

    return 0;
}