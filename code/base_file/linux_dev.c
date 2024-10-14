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
#include <stdarg.h>
#include "../base_common.h"
#include "linux_dev.h"




// 建立测试文件
int fun_establish_dev_file(int* fd, int act) {
    const char *file_path = DEV_FILE_NAME; 
    if(act) { // 打开一个文件并创建文件描述符
        *fd = open(file_path, O_RDWR | O_CREAT, 0644); 
        if (*fd < 0) {
            perror("Error opening file");
            return 1;
        }
    }
    else { // 关闭文件描述符
        close(*fd); 
        *fd = 0;
    }
    return 0;  
}

// 驱动命令
int api_ioctl(const char* dev, unsigned long cmd) {
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

int fun_ioctl() {
    // 'M' 是幻数，1 是序号，int 是参数类型
    #define MY_IOCTL_CMD _IOW('M', 1, int) 
    return api_ioctl("/dev/mydevice", MY_IOCTL_CMD);
}

int api_fcntl(int fd, int cmd, ...) {
    va_list args;
    va_start(args, cmd);
    int result = fcntl(fd, cmd, va_arg(args, void*));
    va_end(args);
    return result;
}

// fcntl 文件锁
int fun_fcntl_lock() {
    int fd = 0;
    if(fun_establish_dev_file(&fd, 1) == 0) {
        // 获取文件锁
        struct flock lock;
        lock.l_type   = F_WRLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;     // 开始行号
        lock.l_len   = 100;   // 行数长度
        api_fcntl(fd, F_GETLK, &lock);
        // 设置文件锁
        lock.l_type  = F_WRLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = 0;
        lock.l_len   = 100;
        api_fcntl(fd, F_SETLK, &lock);
        fun_establish_dev_file(&fd, 0);
    }
    return 0;
}

// fcntl 添加文件属性
int fun_fcntl_attribute() {
    int fd = 0;
    if(fun_establish_dev_file(&fd, 1) == 0) {
        // 获取文件描述符的标志属性
        int flags = api_fcntl(fd, F_GETFL, 0); 
        if (flags < 0) {
            perror("Error getting file flags");
            close(fd);
            return 1;
        }
        // 设置文件描述符的标志属性
        flags |= O_APPEND;
        if (api_fcntl(fd, F_SETFL, flags) < 0) {
            perror("Error setting file flags");
            close(fd);
            return 1;
        }
        close(fd);
    }
    return 0;
}

// 测试例程
int main(int argc, char* argv[]) 
{
    //FUNCTION_PRINT_API(fun_ioctl);
    FUNCTION_PRINT_API(fun_fcntl_lock);
    FUNCTION_PRINT_API(fun_fcntl_attribute);
    return 0;
}

