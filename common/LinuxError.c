/*
 * 文件名: LinuxError.c
 * 作者: ljk
 * 创建时间: 2023-07-25
 * 文件描述: perror用法
 */
#include "../common.h"


// 获取错误码 errno
int getErrCode()
{
    return errno;
}

// 打印错误码
int printErrCode(int err)
{
    int errnum = errno;  // 示例错误码
    char *error_msg = strerror(errnum);
    printf("Error code:%d,  message: %s\n", errno, error_msg);
    return 0;
}

// 打印错误信息 perror
int printErrInfo()
{
    perror("Error");
    return 0;
}


#include "LinuxLog.c"
// 测试程序
int main(int argc, char* argv[]) 
{
    FILE *file = fopen("nonexistent.txt", "r");
    if (file == NULL) 
    {
        int err = getErrCode();
        printErrCode(err);
        printErrInfo();
    }

    char* str = "log_print";
    log_print(PRINT_DEBUG, "%s test", str);

    return 0;
}
