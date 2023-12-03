#ifndef  _LINUX_RESOURCE_H__
#define  _LINUX_RESOURCE_H__
#ifdef __cplusplus
extern "C" {
#endif

// 获取进程或进程组的调度优先级
int fun_getpriority();
// 获取进程的资源限制
int fun_getrlimit();
// 获取进程资源使用情况
int fun_getrusage();

#ifdef __cplusplus
}
#endif
#endif