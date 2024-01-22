/**
 * 文件名: LinuxXxx.c
 * 作者: ljk
 * 创建时间: 2023-08-03
 * 文件描述: XXX操作例程
 * 版本: V 1.0.0
 */
#include "common.h"

#define LINUX_VERSION_MAJOR   "1"
#define LINUX_VERSION_MINOR   "0"
#define LINUX_VERSION_PATCH   "3"
#define LINUX_API_VERSION   "API V" LINUX_VERSION_MAJOR "." LINUX_VERSION_MINOR "." LINUX_VERSION_PATCH


// Xxx功能
int fun_Xxx()
{
    return 0;
}

char* getVersion()
{
    return LINUX_API_VERSION;
}

// 测试用例
int main(int argc, char* argv[])
{
    printf("version:%s\n", getVersion());
    return  0;
}