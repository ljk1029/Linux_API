#ifndef  _LINUX_MMAP_H__
#define  _LINUX_MMAP_H__
#ifdef __cplusplus
extern "C" {
#endif

// 将文件映射到内存
int fun_mmap(int fd, long size);

#ifdef __cplusplus
}
#endif
#endif