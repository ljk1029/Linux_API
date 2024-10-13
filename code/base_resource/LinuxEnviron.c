/*
 * 文件名: LinuxEnv.c
 * 作者: ljk
 * 创建时间: 2023-07-25
 * 文件描述: 环境变量操作例程
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "LinuxEnviron.h"




// getenv获取环境变量
int fun_getenv(const char* path)
{
    const char* env_var = path;
    char* value = getenv(env_var);
    
    if (value != NULL) {
        printf("Value of %s: %s\n", env_var, value);
    } else {
        printf("Environment variable %s not found.\n", env_var);
    }
    
    return 0;
}

// putenv设置环境变量
int fun_putenv(const char* path, const char* value)
{
    const char* env_var   = path;
    const char* in_value = value;

    char* env_str = (char*)malloc(strlen(env_var) + strlen(in_value) + 2); // +2 for '=' and null terminator
    if (env_str == NULL) {
        perror("Memory allocation error");
        return 1;
    }
    
    sprintf(env_str, "%s=%s", env_var, in_value);
    
    if (putenv((char*)env_str) != 0) {
        perror("Error setting environment variable");
        return 1;
    }
    
    char* env_value = getenv(env_var);
    
    if (env_value != NULL) {
        printf("Value of %s: %s\n", env_var, env_value);
    } else {
        printf("Environment variable %s not found.\n", env_var);
    }
    
    return 0;
}

// setenv设置环境变量 overwrite 非0：覆盖已经存在的环境变量值 0：不覆盖已经存在环境变量值
int fun_setenv(const char* path, const char* value, int over)
{
    const char* env_var  = path;
    const char* in_value = value;
    int overwrite = over;

    // 设置环境变量
    int ret = setenv(env_var, value, overwrite);

    if (ret != 0) {
        perror("Error setting environment variable");
        return 1;
    }

    // 获取环境变量并打印
    char* env_value = getenv(env_var);

    if (env_value != NULL) {
        printf("Value of %s: %s\n", env_var, env_value);
    } else {
        printf("Environment variable %s not found.\n", env_var);
    }

    return 0;
}

extern char** environ;
// environ 展示环境变量
int fun_showenv()
{
    char **env = environ;

    while(*env)
    {
        printf("%s\n",*env);
        env++;
    }
    return 0;
}

// 函数调试信息打印
typedef int(*FunctionCallback)();
typedef int(*FunctionCallback1)(const char*);
typedef int(*FunctionCallback2)(const char*, const char*);
typedef int(*FunctionCallback3)(const char*, const char*, int);
int function_print(char* name, void* callback, const char* arg1, const char* arg2, int arg3)
{
    int ret = 0;
    printf("{=====[%s()] test start=====\n", name);
    if(arg1 == NULL){
        FunctionCallback func = (FunctionCallback)callback;
        ret = func();
    }
    else if(arg2 == NULL){
        FunctionCallback1 func = (FunctionCallback1)callback;
        ret = func(arg1);
    }
    else{
        if(arg3 == 0){
            FunctionCallback2 func = (FunctionCallback2)callback;
            ret = func(arg1, arg2);
        }else{
            FunctionCallback3 func = (FunctionCallback3)callback;
            ret = func(arg1, arg2, arg3);
        }
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
    function_print("fun_getenv", fun_getenv, "HOME", NULL,  0);
    function_print("fun_putenv", fun_putenv, "MY_VARIABLE", "hello",   0);
    function_print("fun_setenv", fun_setenv, "MY_VARIABLE", "ni hao!", 1);
    function_print("fun_showenv", fun_showenv, NULL, NULL, 0);
    return 0;
}

// 环境测试例程
int main(int argc, char* argv[])
{
    main_test(argc, argv);
    return 0;
}