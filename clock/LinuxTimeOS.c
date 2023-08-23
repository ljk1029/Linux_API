/*
 * 文件名: LinuxTimeOS.c
 * 作者: ljk
 * 创建时间: 2023-07-27
 * 文件描述: 
 */
#include "common.h"



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

// 测试例程
int main(int argc, char* argv[]) 
{
    printf("__[fun_gettimeofday() test]__\n");
    fun_gettimeofday();
    printf("__[fun_uptime()       test]__\n");
    fun_uptime();
    return 0;
}