#ifndef  _LINUX_LINK66538_H__
#define  _LINUX_LINK66538_H__
#ifdef __cplusplus
extern "C" {
#endif

// 更改权限
int fun_chmod(const char* path, mode_t mode);
// 更改用户和组
int fun_chown(const char* path, uid_t owner, gid_t group);
// 软连接、硬链接
int fun_link(const char *path, const char *spath, const char *hpath);
// 目录建立、删除、
int fun_dir(const char *path);

#ifdef __cplusplus
}
#endif
#endif