/*
 * 文件名: LinuxXxx.c
 * 作者: ljk
 * 创建时间: 2023-08-03
 * 文件描述: XXX操作例程
 */
#include <stdio.h>
#include "LinuxLog.h"
#include "LinuxError.h"
#include "LinuxCTime.h"


// 测试用例
int main(int argc, char* argv[])
{
    FILE *file = fopen("nonexistent.txt", "r");
    if (file == NULL) {
        int err = getErrCode();
        printErrCode(err);
        printErrInfo();
    }

    log_debug("log_debug test");
    log_print(PRINT_DEBUG, "%s test\n", "log_print");

    fun_assert(1);
    fun_assert(0);

    printf("delay 1s\n");
    delay_s(1);
    printf("delay 1000ms\n");
    delay_ms(1000);
    printf("delay 1000000us\n");
    delay_us(1000000);
    printf("delay 1000000000ns\n");
    delay_ns(1000000000);
    return 0;
}