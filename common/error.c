#include <stdio.h>
#include <string.h>
#include <errno.h>


// 获取错误码
int getErrCode()
{
    return errno;
}

// 打印错误码，打印错误码对应错误
int printErrCode(int err)
{
    int errnum = errno;  // 示例错误码
    char *error_msg = strerror(errnum);
    printf("Error code:%d,  message: %s\n", errno, error_msg);
    return 0;
}

// 打印错误信息
int printErrInfo()
{
    perror("Error");
    return 0;
}

int main(int argc, char* argv[]) 
{
    FILE *file = fopen("nonexistent.txt", "r");
    if (file == NULL) 
    {
        printErrCode(getErrCode());
        printErrInfo();
    }
    return 0;
}
