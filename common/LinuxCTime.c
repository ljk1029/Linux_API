/*
 * 文件名: LinuxAssert.c
 * 作者: ljk
 * 创建时间: 2023-08-01
 * 文件描述: 断言用法
 */
#include <time.h>
#include <unistd.h>
#include <stdio.h>

// 幂次方
int power10(int s, int cnt)
{
    int ret = s;
    while(cnt-- >= 0)
    {
        ret *=10;
    }
    return ret;
}

// 延时秒
int delay_s(int cnt)
{
    sleep(cnt);
    return 0;
}

// 延时毫秒
int delay_ms(int cnt)
{
    int count = cnt/1000;
    delay_s(count);
    count = cnt%1000*1000;
    usleep(count);
    return 0;
}

// 延时微秒
int delay_us(int cnt)
{
    int count = cnt/1000000;
    delay_s(count);
    count = cnt%1000000;
    usleep(count);
    return 0;
}

// 延时纳秒
int delay_ns(int cnt)
{
    struct timespec sleepTime;
    sleepTime.tv_sec = cnt / 1000000000;
    sleepTime.tv_nsec = cnt % 1000000000;

    struct timespec remainingTime;
    int result = nanosleep(&sleepTime, &remainingTime);
    while (result != 0) {
        // 如果 nanosleep 被中断，使用剩余的时间再次休眠
        sleepTime = remainingTime;
        result = nanosleep(&sleepTime, &remainingTime);
    }
    return 0;
}


