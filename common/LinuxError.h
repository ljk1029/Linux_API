#ifndef  _LINUX_ERROR_67891_H__
#define  _LINUX_ERROR_67891_H__
#ifdef __cplusplus
extern "C" {
#endif

// 获取错误码, 全局变量errno
int getErrCode();
// 打印错误信息, strerror
int printErrCode();
// 打印错误信息, perror
int printErrInfo();
// 断言测试assert
int fun_assert(int a);

#ifdef __cplusplus
}
#endif
#endif