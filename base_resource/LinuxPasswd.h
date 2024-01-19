#ifndef  _LINUX_PWD_H__
#define  _LINUX_PWD_H__
#ifdef __cplusplus
extern "C" {
#endif

// getuid获取用户id
int fun_getuid();
// getlogin获取登录用户
int fun_getlogin();
// passwd获取密码
int fun_passwd(int uid, char* user);
// getpwent遍历用户
int fun_getpwent();
// 获取主机信息
int fun_gethostname();
// 获取系统信息
int fun_uname();
// 主机标识id
int fun_gethostid();


#ifdef __cplusplus
}
#endif
#endif