/*
 * 文件名: LinuxSyslog.c
 * 作者: ljk
 * 创建时间: 2023-07-31
 * 文件描述: syslog测试操作例程
 */
#include "../common.h"



// 写入到 /var/log/syslog日志中
int fun_syslog()
{
    // 打开系统日志，设置日志选项
    openlog("my_program", LOG_PID | LOG_CONS | LOG_NDELAY, LOG_USER);

    // 记录不同级别的日志信息
    syslog(LOG_INFO,    "这是一条INFO级别的日志信息");
    syslog(LOG_WARNING, "这是一条WARNING级别的日志信息");
    syslog(LOG_ERR,     "这是一条ERROR级别的日志信息");

    // 关闭系统日志
    closelog();

    return 0;
}

// 设置写入过滤
int fun_setlogmask()
{
    // 设置日志过滤掩码，只记录警告（LOG_WARNING）级别的日志
    int old_mask = setlogmask(LOG_MASK(LOG_WARNING));

    // 记录不同级别的日志信息
    syslog(LOG_INFO,    "set 这是一条INFO级别的日志信息");
    syslog(LOG_WARNING, "set 这是一条WARNING级别的日志信息");
    syslog(LOG_ERR,     "set 这是一条ERROR级别的日志信息");

    // 恢复之前的日志过滤掩码
    setlogmask(old_mask);

    return 0;
}

// 测试例程
int main()
{
    printf("__[fun_syslog()     test]__\n");
    fun_syslog();
    printf("__[fun_setlogmask() test]__\n");
    fun_setlogmask();
    return 0;
}