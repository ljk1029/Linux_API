/*
 * 文件名: LinuxFcntl.c
 * 作者: ljk
 * 创建时间: 2023-07-15
 * 文件描述: fcntl
 */
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include "LinuxFcntl.h"

// 驱动命令
int fun_ioctl(const char* dev, unsigned long cmd)
{
    int fd =  -1;  
    int ret = -1; 
    int status = 0;
    const char* device = dev;
    unsigned long commod = cmd;

    // 打开设备文件
    fd = open(device, O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // 发送一个控制命令
    ret = ioctl(fd, commod, &status);
    if (ret == -1) {
        perror("ioctl");
        close(fd);
        return 1;
    }

    // 关闭设备文件
    close(fd);
    return 0;
}

// fcntl 文件锁
int fun_fcntl_lock(int fd) 
{
    // 获取文件锁
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;   // 开始行号
    lock.l_len = 100;   // 行数长度
    fcntl(fd, F_GETLK, &lock);

    // 设置文件锁
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 100;
    fcntl(fd, F_SETLK, &lock);
    return 0;
}

// fcntl 添加文件属性
int fun_fcntl(int fd) 
{
    // 获取文件描述符的标志属性
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags < 0) 
    {
        perror("Error getting file flags");
        close(fd);
        return 1;
    }

    // 在标志属性中添加O_APPEND选项
    flags |= O_APPEND;
    // 设置文件描述符的标志属性
    if (fcntl(fd, F_SETFL, flags) < 0) 
    {
        perror("Error setting file flags");
        close(fd);
        return 1;
    }

    // 读取文件内容并输出
    char buffer[100];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead < 0) 
    {
        perror("Error reading file");
        close(fd);
        return 1;
    }
    printf("File content: %.*s\n", (int)bytesRead, buffer);
    return 0;
}


// 测试文件目录
#define API_DIR_PATH     ".."           
#define API_FILE_NAME     API_DIR_PATH "/build/" "file.txt" 

int test_fcntl()
{
    const char *file_path = API_FILE_NAME;
    // 打开一个文件并创建文件描述符
    int fd = open(file_path, O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }
    fun_fcntl(fd);
    // 关闭文件描述符
    close(fd);
}

// 测试例程
int main(int argc, char* argv[]) 
{
    printf("{=====[fun_fcntl()] test start=====\n");
    test_fcntl();
    printf("------[fun_fcntl()] test end-------}\n\n");

    printf("{=====[fun_ioctl()] test start=====\n");
    return 0;
}

