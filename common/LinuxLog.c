/*
 * 文件名: LinuxLog.c
 * 作者: ljk
 * 创建时间: 2023-07-25
 * 文件描述: va_list用法
 */
#include <stdarg.h>
#include <stdio.h>
#include "LinuxLog.h"



static int print_level = SWITCH_DEBUG_PRINT;

// 初始化打印
int init_print(int level)
{
    print_level = level;
    return print_level;
}

// 打印
void log_print(int level, const char *msg, ...)
{
    #define LOG_BUF_SIZE           (1024)
    if( print_level > level)
        return ;
    
    va_list ap;    
    char message[LOG_BUF_SIZE] = {0}; 
    va_start(ap, msg);  
    vsnprintf(message, LOG_BUF_SIZE, msg, ap);  
    va_end(ap);

    if(PRINT_ERROR == level){
        fprintf(stderr, "%s", message);
    }
    else{
        fprintf(stdout, "%s", message);
    }
}



// 打印文件，函数，行号
int log_debug(char* info)
{
    printf("%s: %s %s line %d\n", info, __FILE__, __FUNCTION__, __LINE__);
    return 0;
}

