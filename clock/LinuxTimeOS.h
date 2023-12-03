#ifndef  _LINUX_TIME_OS_H__
#define  _LINUX_TIME_OS_H__
#ifdef __cplusplus
extern "C" {
#endif

// gettimeofday获取当前时间
int fun_gettimeofday();
// 获取当前系统允许时间
int fun_uptime();

#ifdef __cplusplus
}
#endif
#endif