/*
 * 文件名: LinuxDir.c
 * 作者: ljk
 * 创建时间: 2023-07-15
 * 文件描述: 目录寻找操作例程
 */
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include "LinuxDir.h"


// 遍历文件
int fun_finddir(char* dir, int depth)
{
    DIR *dirp = NULL;
    struct stat statbuf;
    struct dirent *entry = NULL;

    if((dirp = opendir(dir)) == NULL) {
        fprintf(stderr, "cannot open directory:%s\n", dir);
    }
    chdir(dir);// 切换目录
    while((entry =readdir(dirp)) != NULL) {
        lstat(entry->d_name,&statbuf);
        if(S_ISDIR(statbuf.st_mode)) {
            if(strcmp(".",entry->d_name) == 0 || 
                strcmp("..",entry->d_name) == 0)
                continue;
            printf("%*s%s/\n",depth,"",entry->d_name);
            fun_finddir(entry->d_name,depth+4);
        }
        else printf("%*s%s\n",depth,"",entry->d_name);
    }
    chdir("..");
    closedir(dirp);

    return 0;
}

// 记录文件
int fun_seekdir(char* target, char* path_dir) 
{
    DIR *dir;
    struct dirent *entry;
    long position;
    // 要查找的目标文件名
    char* targetFile = target; 

    // 打开目录
    dir = opendir(path_dir);
    if (dir == NULL) {
        perror("opendir failed");
        return 1;
    }

    // 遍历目录并记录当前位置
    while ((entry = readdir(dir)) != NULL) {
        printf("File: %s\n", entry->d_name);

        // 检查是否找到目标文件
        if (strcmp(entry->d_name, targetFile) == 0) {
            printf("Found target file: %s\n", targetFile);

            // 记录当前位置
            position = telldir(dir);
        }
    }

    // 恢复到之前记录的位置
    printf("--重新定位--\n");
    seekdir(dir, position);

    // 继续遍历剩余的目录项
    while ((entry = readdir(dir)) != NULL) {
        printf("File: %s\n", entry->d_name);
    }

    // 关闭目录
    closedir(dir);

    return 0;
}

// 函数调试信息打印
typedef int(*FunctionCallback1)(const char*, int);
typedef int(*FunctionCallback2)(const char*, const char*);

int function_print(char* name, void* callback, const char* arg1, const char* arg2, int arg3)
{
    int ret = 0;
    printf("{=====[%s()] test start=====\n", name);
    if(arg2 == NULL){
        FunctionCallback1 func = (FunctionCallback1)callback;
        ret = func(arg1, arg3);
    }
    else{
        FunctionCallback2 func = (FunctionCallback2)callback;
        ret = func(arg1, arg2);
    }
    printf("------[%s()] test end-------}\n\n", name);
    return ret;
}


// 测试文件目录
#define API_DIR_PATH   ".." 

int main_test(int argc, char* argv[])
{
    printf("输入的命令行参数个数为: %d\n", argc);
    for (int i = 0; i < argc; ++i) {
        printf("参数 %d: %s\n", i, argv[i]);
    }
    char* dir = API_DIR_PATH;
    int depth = 0;
    char targetFile[] = "build.sh";
    function_print("fun_finddir", fun_finddir, dir, NULL, depth);
    function_print("fun_seekdir", fun_seekdir, dir, targetFile, 0);
    return 0;
}

int main(int argc, char* argv[])
{
    main_test(argc, argv);
    return 0;
}