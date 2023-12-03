#ifndef  _LINUX_FCNTL_H__
#define  _LINUX_FCNTL_H__
#ifdef __cplusplus
extern "C" {
#endif

// 驱动命令
int fun_ioctl(const char* dev, unsigned long cmd);
// fcntl 添加文件属性
int fun_fcntl(int fd);

#ifdef __cplusplus
}
#endif
#endif