#ifndef  _LINUX_FILEIO66537_H__
#define  _LINUX_FILEIO66537_H__
#ifdef __cplusplus
extern "C" {
#endif

// 文件权限确认
int fun_access(const char* path);
// 文件IO写
int fun_write(const char* path, const char* data);
// 文件IO读
int fun_read(const char* path);
// 文件lseek
int fun_lseek(const char* path);
// 文件stat
int fun_stat(const char* path);
// 文件dup
int fun_dup(const char* path);

#ifdef __cplusplus
}
#endif
#endif