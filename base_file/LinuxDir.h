#ifndef  _LINUX_DIR66535_H__
#define  _LINUX_DIR66535_H__
#ifdef __cplusplus
extern "C" {
#endif

// 遍历文件
int fun_finddir(char* dir, int depth);
// 记录文件
int fun_seekdir(char* target, char* path_dir);

#ifdef __cplusplus
}
#endif
#endif