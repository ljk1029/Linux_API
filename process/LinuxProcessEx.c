/*
 * 文件名: LinuxProcess.c
 * 作者: ljk
 * 创建时间: 2023-07-23
 * 文件描述: 进程开启子进程例程
 */
#include "../common.h"



// 在一个shell新进程执行命令，返回值退出状态码，返回-1则失败
int fun_system(char* cmd)
{
    return system(cmd);
}

// 在一个新的shell进程执行命令，它可以像打开文件一样打开一个管道，实现输入和输出的交互
int fun_popen(char* cmd, char* mode)
{
    FILE* stream;
    char buffer[1024];

    // Using popen to execute a shell command and read its output
    stream = popen(cmd, mode);
    if (stream) {
        while (!feof(stream) && fgets(buffer, sizeof(buffer), stream) != NULL) {
            printf("%s", buffer);
        }
        pclose(stream);
    }

    return 0;
}

// 代替原先的进程，exec后代码不会执行
// 显式地指定新进程的每个参数,第一次参数执行文件路径
int fun_execl()
{
    execl("/bin/ls", "ls", "-l", NULL);
    perror("exec failed"); 
    return 1;
}

// 同execl，允许提供文件名称，不提供路径
int fun_execlp()
{
    execlp("ls", "ls", "-l", NULL);
    perror("exec failed"); 
    return 1;
}

// 允许提供环境变量
int fun_execle()
{
    char *envp[] = {"USER=abc", "HOME=/home/abc", NULL}; //环境变量
    execle("/bin/echo", "echo", "$USER", "$HOME", NULL, envp);
    perror("exec failed"); 
    return 1;
}

// 允许命令行参数作为字符串指针传递
int fun_execv()
{
    char* args[] = {"ls", "-l", NULL}; 
    execv("/bin/ls", args);
    perror("exec failed"); 
    return 1;
}

// 同execv，允许提供文件名称，不提供路径
int fun_execvp()
{
    char* args[] = {"ls", "-l", NULL}; 
    execvp("ls", args);
    perror("exec failed"); 
    return 1;
}



// 测试程序
int main(int argc, char* argv[])
{
    printf("argc:%d, path:%s", argc, argv[0]);
    if(argc > 1)
    {
        printf(" commond:%s\n", argv[1]);
        if(strcmp("system", argv[1]) == 0)
        {
            fun_system("ls -l");
        }
        else if(strcmp("popen", argv[1]) == 0)
        {
            fun_popen("ls -l", "r");
        }
        else if(strcmp("execl", argv[1]) == 0)
        {
            fun_execl();
        }
        else if(strcmp("execlp", argv[1]) == 0)
        {
            fun_execlp();
        }
        else if(strcmp("execle", argv[1]) == 0)
        {
            fun_execle();
        }
        else if(strcmp("execv", argv[1]) == 0)
        {
            fun_execv();
        }
        else if(strcmp("execvp", argv[1]) == 0)
        {
            fun_execvp();
        }
    }
}