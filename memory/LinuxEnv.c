/*
 * 文件名: LinuxEnv.c
 * 作者: ljk
 * 创建时间: 2023-07-25
 * 文件描述: 环境变量操作例程
 */
#include "../common.h"





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




// 测试例程
int main(int argc, char* argv[])
{
    printf("__[fun_getenv()  test]__\n");
    fun_getenv("HOME"); 
    printf("__[fun_putenv()  test]__\n");
    fun_putenv("MY_VARIABLE", "hello"); 
    printf("__[fun_setenv()  test]__\n"); 
    fun_setenv("MY_VARIABLE", "ni hao!", 1); 
    printf("__[fun_showenv() test]__\n"); 
    fun_showenv(); 
    return 0;
}