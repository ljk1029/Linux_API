/*
 * 文件名: LinuxPwd.c
 * 作者: ljk
 * 创建时间: 2023-07-31
 * 文件描述: 用户信息操作例程
 */
#include <unistd.h>
#include <pwd.h>
#include <sys/utsname.h>
#include <stdio.h>
#include "LinuxPasswd.h"



// getuid获取用户id
int fun_getuid()
{
    uid_t uid = getuid();
    gid_t gid = getgid();
    printf("当前进程的有效用户ID为:%d, %d\n", uid, gid);
    return 0;
}

// getlogin获取登录用户
int fun_getlogin()
{
    char *login_name = getlogin();
    if (login_name != NULL) 
    {
        printf("当前登录用户名为：%s\n", login_name);
    } 
    else {
        perror("获取登录用户名失败");
    }
    return 0;
}

// passwd获取密码
int fun_passwd(int uid, char* user)
{
    struct passwd* pw;

    printf("%d:%s", uid, user);

    pw = getpwuid(uid);
    printf("UID passwd entry:\n name=%s, uid=%d, gid=%d, home=%s, shell=%s\n",
        pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir, pw->pw_shell);
    
    pw = getpwnam(user);
    printf("%s passwd entry:\n name=%s, uid=%d, gid=%d, home=%s, shell=%s\n", user,
        pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir, pw->pw_shell);
    return 0;
}

// getpwent遍历用户
int fun_getpwent()
{
     struct passwd *pwd_entry;

    // 获取用户数据库的第一条记录
    setpwent();

    // 读取用户数据库中的每一条记录
    while ((pwd_entry = getpwent()) != NULL) {
        printf("用户名:%s\n", pwd_entry->pw_name);
        printf("用户ID:%d\n", pwd_entry->pw_uid);
        printf("用户家目录:%s\n", pwd_entry->pw_dir);
        printf("用户登录Shell:%s\n", pwd_entry->pw_shell);
        printf("--------------------------\n");
    }

    // 关闭用户数据库
    endpwent();

    return 0;
}

// 获取主机信息
int fun_gethostname()
{
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("本地主机名：%s\n", hostname);
    } else {
        perror("获取主机名失败");
        return 1;
    }
    return 0;
}

// 获取系统信息
int fun_uname()
{
    struct utsname system_info;
    if (uname(&system_info) == 0) {
        printf("操作系统名称：%s\n", system_info.sysname);
        printf("网络节点名称（主机名）：%s\n", system_info.nodename);
        printf("操作系统发布版本：%s\n", system_info.release);
        printf("硬件类型：%s\n", system_info.machine);
    } else {
        perror("获取系统信息失败");
        return 1;
    }
    return 0;
}

// 主机标识id
int fun_gethostid()
{
    long host_id = gethostid();
    printf("本地主机标识符：%ld\n", host_id);
    return 0;
}

// 函数调试信息打印
typedef int(*FunctionCallback1)();
typedef int(*FunctionCallback2)(int, char*);
int function_print(char* name, void* callback, int arg1, char* arg2)
{
    int ret = 0;
    printf("{=====[%s()] test start=====\n", name);
    if(arg2 == NULL){
        FunctionCallback1 func = (FunctionCallback1)callback;
        ret = func();
    }
    else{
        FunctionCallback2 func = (FunctionCallback2)callback;
        ret = func(arg1, arg2);
    }
    printf("------[%s()] test end-------}\n\n", name);
    return ret;
}


int main_test(int argc, char* argv[])
{
    printf("输入的命令行参数个数为: %d\n", argc);
    for (int i = 0; i < argc; ++i) {
        printf("参数 %d: %s\n", i, argv[i]);
    }
    function_print("fun_getuid",   fun_getuid, 0, NULL);
    function_print("fun_getlogin", fun_getlogin, 0, NULL);
    function_print("fun_passwd",   fun_passwd, 1000, "root");
    function_print("fun_getpwent", fun_getpwent, 0, NULL);
    function_print("fun_gethostname", fun_gethostname, 0, NULL);
    function_print("fun_uname",    fun_uname, 0, NULL);
    function_print("fun_gethostid", fun_gethostid, 0, NULL);
    return 0;
}

// 环境测试例程
int main(int argc, char* argv[])
{
    main_test(argc, argv);
    return 0;
}