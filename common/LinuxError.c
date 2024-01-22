/*
 * 文件名: LinuxError.c
 * 作者: ljk
 * 创建时间: 2023-07-25
 * 文件描述: perror用法
 */
// 禁用 assert,必须放<assert.h>前
#define NDEBUG
#include <string.h> 
#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "LinuxError.h"


// 获取错误码, 全局变量errno
int getErrCode()
{
    printf("Error code: %d\n", errno);
    return errno;
}

// 打印错误信息, strerror
int printErrCode()
{
    int  errnum = errno;  
    char *error_msg = strerror(errnum);
    printf("Error code: %d, message: %s\n", errnum, error_msg);
    return 0;
}

// 打印错误信息, perror
int printErrInfo()
{
    perror("Error message");
    return 0;
}

// 断言测试assert
int fun_assert(int a) 
{
    printf("assert test\n");
    // 断言 b 不为 0
    assert(a != 0);

    printf("input:%d\n", a);
    return 0;
}

