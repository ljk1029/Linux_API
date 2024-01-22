/*
 * 文件名: LinuxTimeOS.c
 * 作者: ljk
 * 创建时间: 2023-07-27
 * 文件描述: 
 */
#include <sys/time.h>
#include <stdlib.h>
//#include <time.h>
#include <stdio.h>
#include "LinuxTimeOS.h"



// gettimeofday获取当前时间
int fun_gettimeofday()
{
    struct timeval tv;
    if (gettimeofday(&tv, NULL) == 0) 
    {
        printf("Seconds: %ld\n", tv.tv_sec);
        printf("Microseconds: %ld\n", tv.tv_usec);
    } 
    return 0;
}

// 获取当前系统允许时间
int fun_uptime()
{
    long long _ltime = 0;
    char szline[1024] = {0};
    FILE* fp = fopen("/proc/uptime", "r");//打开系统文件查看
	if(!fp)
	{
		perror("fopen /proc/uptime");
		return -1;
	}
	// 获取运行时间和空闲时间
	fgets(szline, sizeof(szline), fp);
    fclose(fp);
    _ltime = atoi(szline);
    printf("/proc/uptime:%s %lld\n", szline, _ltime);
    return 0;
}

// 函数调试信息打印
typedef int(*FunctionCallback)();
int function_print(char* name, void* callback)
{
    int ret = 0;
    printf("{=====[%s()] test start=====\n", name);
    FunctionCallback func = (FunctionCallback)callback;
    ret = func();
    printf("------[%s()] test end-------}\n\n", name);
    return ret;
}


int main_test(int argc, char* argv[])
{
    printf("输入的命令行参数个数为: %d\n", argc);
    for (int i = 0; i < argc; ++i) {
        printf("参数 %d: %s\n", i, argv[i]);
    }
    function_print("fun_gettimeofday",  fun_gettimeofday);
    function_print("fun_uptime", fun_uptime);
    return 0;
}

// 测试例程
int main(int argc, char* argv[])
{
    main_test(argc, argv);
    return 0;
}