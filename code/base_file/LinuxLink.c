/*
 * 文件名: LinuxFileIO.c
 * 作者: ljk
 * 创建时间: 2023-07-15
 * 文件描述: 文件链接操作例程
 */
#include <unistd.h> 
#include <stdlib.h>    // For NULL
#include <stddef.h>    // For size_t and NULL
#include <sys/stat.h>  // For struct stat and file-related functions
#include <sys/types.h> // For uid_t, gid_t, and other types
#include <fcntl.h>
#include <stdio.h>
#include <limits.h>
#include "LinuxLink.h"


// 建立测试文件
int funEstablishFile(const char* path)
{
    const char* file_path = path;
    // 打开文件，以追加模式打开，如果文件不存在则创建
    FILE* file = fopen(file_path, "a");
    if (file == NULL) {
        printf("无法创建文件！\n");
        return 1;
    }

    // 关闭文件
    fclose(file);
    printf("文件创建成功！\n");

    return 0;
}

// 更改权限
int fun_chmod(const char* path, mode_t mode)
{
    const char* file_path = path;
    mode_t file_mode = mode;

    if (chmod(path, mode) == 0) {
        printf("权限修改成功！\n");
    } else {
        perror("chmod 失败");
    }
    return 0;
}

// 更改用户和组
int fun_chown(const char* path, uid_t owner, gid_t group)
{
    const char *file_path = path;
    uid_t file_owner = owner;  // 新的所有者用户 ID
    gid_t file_group = group;  // 新的所属群组群组 ID

    if (chown(file_path, file_owner, file_group) == 0) {
        printf("所有者和群组修改成功！\n");
    } else {
        perror("chown 失败");
    }
    return 0;
}

// 软连接、硬链接
// 硬链接 link <原文件路径> <目标文件路径>
// 软连接 ln -s <原文件路径> <符号链接路径>
int fun_link(const char *path, const char *spath, const char *hpath)
{
    const char *filepath = path;
    const char *softpath = spath;
    const char *hardpath = hpath;

    if (link(filepath, softpath) == 0) {
        printf("硬链接创建成功！\n");
    } else {
        perror("link 失败");
    }

    if (symlink(filepath, hardpath) == 0) {
        printf("符号链接创建成功！\n");
    } else {
        perror("symlink 失败");
    }

#if 1
    if (unlink(filepath) == 0) {
        printf("文件链接删除成功！\n");
    } else {
        perror("unlink 失败");
    }
#endif

#if 1
    if (unlink(softpath) == 0) {
        printf("软连接链接删除成功！\n");
    } else {
        perror("unlink 失败");
    }
    
    if (unlink(hardpath) == 0) {
        printf("硬链接删除成功！\n");
    } else {
        perror("unlink 失败");
    }
#endif

    return 0;
}

// 目录建立、删除、
int fun_dir(const char *path)
{
    const char *dir_path = path;
    int status;
    
    status = mkdir(dir_path, 0777);  // 创建目录，设置权限为 0777
    if (status == 0) {
        printf("目录创建成功！\n");
    } else {
        perror("mkdir 失败");
    }

    char buf[PATH_MAX];
    if (getcwd(buf, sizeof(buf)) != NULL) {
        printf("当前工作目录：%s\n", buf);
    } else {
        perror("getcwd 失败");
    }

    if (chdir(dir_path) == 0) {
        printf("当前工作目录修改成功！\n");
    } else {
        perror("chdir 失败");
    }

#if 1
    status = rmdir(dir_path);  // 删除目录
    if (status == 0) {
        printf("目录删除成功！\n");
    } else {
        perror("rmdir 失败");
    }
#endif
}

// 函数调试信息打印
typedef int(*FunctionCallback1)(const char*);
typedef int(*FunctionCallback2)(const char*, unsigned int);
typedef int(*FunctionCallback3)(const char*, unsigned int, unsigned int);
typedef int(*FunctionCallback4)(const char*, const char*, const char*);
typedef struct _arg_t{
    unsigned int type;
    const char* path;
    const char* arg1;
    const char* arg2;
    unsigned int arg3;
    unsigned int arg4;
}arg_t;

int function_print(char* name, void* callback, arg_t arg)
{
    int ret = 0;
    printf("{=====[%s()] test start=====\n", name);
    if(arg.type == 1){
        FunctionCallback1 func = (FunctionCallback1)callback;
        ret = func(arg.path);
    }
    else if(arg.type == 2){
        FunctionCallback2 func = (FunctionCallback2)callback;
        ret = func(arg.path, arg.arg3);
    }
    else if(arg.type == 3){
        FunctionCallback3 func = (FunctionCallback3)callback;
        ret = func(arg.path, arg.arg3, arg.arg4);
    }
    else if(arg.type == 4){
        FunctionCallback4 func = (FunctionCallback4)callback;
        ret = func(arg.path, arg.arg1, arg.arg2);
    }
    printf("------[%s()] test end-------}\n\n", name);
    return ret;
}


// 创建目录测试 软连接测试
#define LINK_DIR_NAME    "../build/link_dir"  
#define LINK_FILE_NAME   "link.txt"

// 测试例程
int main_test(int argc, char* argv[])
{
    printf("输入的命令行参数个数为: %d\n", argc);
    for (int i = 0; i < argc; ++i) {
        printf("参数 %d: %s\n", i, argv[i]);
    }
    const char *path = LINK_FILE_NAME; 
    const char *dir  = LINK_DIR_NAME; 
    arg_t arg = {
        .path = path
    };

    arg.type = 1;
    function_print("funEstablishFile", funEstablishFile, arg);

    arg.type = 2;
    arg.arg3 = 0644;
    function_print("fun_chmod", fun_chmod, arg);

    arg.type = 3;
    arg.arg3 = 1001;
    arg.arg3 = 1002;
    function_print("fun_chown", fun_chown, arg);

    // 使用预处理指令 # 进行字符串拼接
    #define STRINGIFY(x,y) x#y
    arg.type = 4;
    arg.arg1 = STRINGIFY(LINK_FILE_NAME, .softlink);;
    arg.arg2 = STRINGIFY(LINK_FILE_NAME, .hardlink);;
    function_print("fun_link", fun_link, arg);

    arg.type  = 1;
    arg.path = dir;
    function_print("fun_dir", fun_dir, arg);
    return 0;
}

// 测试例程
int main(int argc, char* argv[])
{
    main_test(argc, argv);
    return 0;
}