/*
 * 文件名: LinuxTime.c
 * 作者: ljk
 * 创建时间: 2023-07-15
 * 文件描述: 
 */
#include "common.h"



//  time， 1970年1月1日至今的秒数
int fun_time()
{
    time_t t_time;
    t_time = time((time_t*)0);
    printf("The time is %ld\n", t_time);
    return 0;
}

// difftime时间差
int fun_difftime(int cnt)
{
    time_t t1, t2;
    double diff;

    // 获取两个时间戳
    t1 = time(NULL);
    sleep(cnt);
    t2 = time(NULL);

    // 计算时间差
    diff = difftime(t2, t1);
    
    printf("The difftime is %f\n", diff);
    return 0;
}

//  gmtime现在时间
int fun_gmtime()
{
    struct tm* tm_ptr;
    time_t t_time;
    time(&t_time);
    tm_ptr = gmtime(&t_time);
    printf("date: %04d/%02d/%02d\n", 
        tm_ptr->tm_year+1900, tm_ptr->tm_mon+1, tm_ptr->tm_mday);
    printf("time: %02d:%02d:%02d\n", 
        tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);
    printf("week: %d, day:%03d, is:%d\n", 
        tm_ptr->tm_wday, tm_ptr->tm_yday, tm_ptr->tm_isdst);
    return 0;
}

//  localtime现在时间
int fun_localtime()
{
    struct tm* tm_ptr;
    time_t t_time;
    time(&t_time);
    tm_ptr = localtime(&t_time);
    printf("time: %02d:%02d:%02d\n", 
        tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);
    return 0;
}

//  1970-01-01 08:00:00 0
//  mktime时间戳
int fun_mktime()
{
    struct tm tm_info;
    time_t timestamp;

    // 设置时间结构体的信息
    tm_info.tm_year = 70;     // 年份，从1900年开始计算，所以2021年对应121
    tm_info.tm_mon  = 0;      // 月份，0表示1月，所以7表示8月
    tm_info.tm_mday = 1;      // 日
    tm_info.tm_hour = 8;      // 小时
    tm_info.tm_min  = 0;      // 分钟
    tm_info.tm_sec  = 0;      // 秒

    // 将时间结构体转换成时间戳
    timestamp = mktime(&tm_info);

    // 输出时间戳
    printf("Timestamp: %ld\n", timestamp);
    return 0;
}

//  astime现在时间
int fun_astime()
{
    struct tm* tm_ptr;
    time_t t_time;
    time(&t_time);
    tm_ptr = localtime(&t_time);
    char* c_time  = ctime(&t_time);
    char* as_time = asctime(tm_ptr);

    printf("当前时间: %s", c_time);
    printf("当前时间: %s", as_time);
    return 0;
}

//  strtime时间格式化
int fun_strtime()
{
    struct tm* tm_ptr, timestruct;
    time_t t_time;
    char buf[256], *result;
    time(&t_time);
    tm_ptr = localtime(&t_time);
    char* c_time  = ctime(&t_time);
    strftime(buf, 256, "%A %d %B, %I:%S %p", tm_ptr);
    printf("strftime gives: %s\n", buf);
#if 0  // 系统不支持
    strcpy(buf, "Thu 26 July 2007, 17:53 will do fine");
    printf("calling strptine with: %s\n", buf);
    tm_ptr = &timestruct;
    result = strptime(buf, "%a %d %b %Y, %R", tm_ptr);
    printf("strptime consumed up to:%s\n", result);
    printf("strptime gives: %02d/%02d/%02d %02d:%02d\n", 
        tm_ptr->tm_year%100, tm_ptr->tm_mon+1, tm_ptr->tm_mday,
        tm_ptr->tm_hour, tm_ptr->tm_min);
#endif
    return 0;
}




// 测试例程
int main(int argc, char* argv[]) 
{
    printf("__[fun_time()      test]__\n");
    fun_time();
    printf("__[fun_difftime()  test]__\n");
    fun_difftime(1);
    printf("__[fun_gmtime()    test]__\n");
    fun_gmtime();
    printf("__[fun_localtime() test]__\n");
    fun_localtime();
    printf("__[fun_mktime()    test]__\n");
    fun_mktime();
    printf("__[fun_astime()    test]__\n");
    fun_astime();
    printf("__[fun_strtime()   test]__\n");
    fun_strtime();
   
    return 0;
}