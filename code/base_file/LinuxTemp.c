/*
 * 文件名: LinuxTemp.c
 * 作者: ljk
 * 创建时间: 2023-07-31
 * 文件描述: 临时文件操作例程
 */
#include <unistd.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinuxTemp.h"

// 读写测试
int fun_rwfile(FILE *fp)
{
    char *data = "Hello, this is a temporary file!";
    // 向临时文件写入数据
    fprintf(stdout, "向临时文件写入数据:%s\n", data);
    fprintf(fp, "%s\n", data);

    // 定位文件指针到文件开头
    rewind(fp);

    fprintf(stdout, "向临时文件读出数据:");
    // 从临时文件读取数据并输出到控制台
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp)) {
        printf("%s", buffer);
    }
    return 0;
}

// 读写测试
int fun_rwio(int fd)
{
    char *data = "Hello, this is a temporary file!";
    // 向临时文件写入数据
    fprintf(stdout, "向临时文件写入数据:%s, fd:%d\n", data, fd);
    // 写入数据到文件
    if (write(fd, data, strlen(data)) == -1) {
        perror("write");
        exit(1);
    }

    // 将文件指针移动到文件的开头
    off_t newOffset = lseek(fd, 0, SEEK_SET);
    if (newOffset == -1) {
        perror("lseek");
        exit(1);
    }

    // 从文件中读取数据到缓冲区
    char buffer[100];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead == -1) {
        perror("read");
        exit(1);
    }
    fprintf(stdout, "向临时文件读出数据:%s\n", buffer);
    
    return 0;
}

// tmpnam 返回一个唯一的临时文件名, 并不会创建实际的文件。
// 这个函数被认为是不安全的
int fun_tmpnam()
{
    // 定义一个字符数组用于存储临时文件名
    char temp_file_name[L_tmpnam]; 

    // 生成临时文件名并存储在 temp_file_name 中
    if (tmpnam(temp_file_name) == NULL) {
        perror("Error generating temporary file name");
        return 1;
    }
    printf("临时文件名称:%s\n", temp_file_name);
#if 0
    // 打开临时文件进行读写，使用 "w+" 模式表示可读可写
    FILE* fp = fopen(temp_file_name, "w+");
    if (fp == NULL) {
        perror("Error opening temporary file");
        return 1;
    }

    fun_rwfile(fp);

    // 关闭临时文件
    fclose(fp);

    // 删除临时文件（可选步骤）
    if (remove(temp_file_name) != 0) {
        perror("Error deleting temporary file");
        return 1;
    }
#endif
    return 0;
}

// tmpfile 创建一个唯一的临时文件，并返回一个指向该文件的文件指针。创建的临时文件在程序结束后会自动删除。
int fun_tmpfile()
{
    FILE *fp = tmpfile();
    if (fp != NULL) 
    {
        fun_rwfile(fp);
    }
    return 0;
}

// mktemp返回一个唯一的临时文件名, 并不会创建实际的文件。
// 这个函数被认为是不安全的
// 模板字符串必须以 "XXXXXX" 结尾，这些 "X" 会被替换为随机字符
int fun_mktemp()
{
    char temp_file_name[] = "/tmp/fileXXXXXX";
    if (mktemp(temp_file_name) == NULL) {
        perror("Error creating temporary file");
        return 1;
    }
    printf("临时文件名称:%s\n", temp_file_name);
#if 0
    // 打开临时文件进行读写，使用 "w+" 模式表示可读可写
    FILE* fp = fopen(temp_file_name, "w+");
    if (fp == NULL) {
        perror("Error opening temporary file");
        return 1;
    }

    fun_rwfile(fp);

    // 关闭临时文件
    fclose(fp);

    // 删除临时文件（可选步骤）
    if (remove(temp_file_name) != 0) {
        perror("Error deleting temporary file");
        return 1;
    }
#endif
    return 0;
}

// mkdtemp 返回一个唯一的临时文件名, 创建实际的文件目录。
int fun_mkdtemp()
{
    char temp_dir_path[] = "/tmp/fileXXXXXX";
    if (mkdtemp(temp_dir_path) == NULL) {
        perror("Error creating temporary file");
        return 1;
    }
    printf("临时文件目录名称:%s\n", temp_dir_path);
    // 删除临时目录
    if (rmdir(temp_dir_path) != 0) {
        perror("删除临时文件目录");
        return 1;
    }
    return 0;
}

// mkstemp 返回一个描述符和文件名字, 创建实际的文件。
int fun_mkstemp()
{
    char temp_file_name[] = "/tmp/fileXXXXXX";
    int fd = mkstemp(temp_file_name);
    printf("临时文件名称:%s\n", temp_file_name);
    if (fd != -1) 
    {
#if 1
        // 使用 fd 创建文件指针
        FILE* fp = fdopen(fd, "w+");
        if (fp == NULL) {
            perror("Error opening temporary file");
            return 1;
        }

        fun_rwfile(fp);

        // 关闭临时文件
        fclose(fp);

        // 删除临时文件（可选步骤）
        if (remove(temp_file_name) != 0) {
            perror("Error deleting temporary file");
            return 1;
        }
#elif 2
        fun_rwio(fd);
#else
        // 关闭临时文件
        printf("关闭临时文件:%s\n", temp_file_name);
        close(fd);
#endif
    } 
    else 
    {
        perror("Error creating temporary file");
        return 1;
    }
    return 0;
}

// 函数调试信息打印
typedef int(*FunctionCallback)();

int function_print(char* name, void* callback)
{
    int ret = 0;
    printf("{=====[%s()] test start=====\n", name);
    FunctionCallback func = (FunctionCallback)callback;
    ret = func();
    printf("------[%s()] test end-------}\n\n", name);
    return ret;
}


int main_test(int argc, char* argv[])
{
    printf("输入的命令行参数个数为: %d\n", argc);
    for (int i = 0; i < argc; ++i) {
        printf("参数 %d: %s\n", i, argv[i]);
    }
    function_print("fun_tmpnam",  fun_tmpnam);
    function_print("fun_tmpfile", fun_tmpfile);
    function_print("fun_mktemp",  fun_mktemp);
    function_print("fun_mkdtemp", fun_mkdtemp);
    function_print("fun_mkstemp", fun_mkstemp);
    return 0;
}

// 测试例程
int main(int argc, char* argv[])
{
    main_test(argc, argv);
    return 0;
}