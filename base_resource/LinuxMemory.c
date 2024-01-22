/*
 * 文件名: LinuxMmap.c
 * 作者: ljk
 * 创建时间: 2023-07-15
 * 文件描述: 内存RAM测试
 */
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "LinuxMemory.h"



// 将文件映射到内存ARM
int fun_mmap(int fd, long size, const char* data)
{
    // 将文件扩展到指定大小
    off_t file_size = size;
    if (lseek(fd, file_size - 1, SEEK_SET) == -1) {
        perror("Error calling lseek");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (write(fd, "", 1) == -1) {
        perror("Error writing to file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // 映射文件到内存
    char *mapped_addr = (char *)mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mapped_addr == MAP_FAILED) {
        perror("Error mapping file to memory");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // 写入数据到映射区域
    const char *message = data;
    for (int i = 0; message[i] != '\0'; ++i) {
        mapped_addr[i] = message[i];
    }

    // 刷新映射区域到文件
    if (msync(mapped_addr, file_size, MS_SYNC) == -1) {
        perror("Error syncing memory to file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // 从映射区域读取数据
    printf("Read from memory-mapped file: %s\n", mapped_addr);

    // 解除映射并关闭文件
    if (munmap(mapped_addr, file_size) == -1) {
        perror("Error unmapping memory");
        close(fd);
        exit(EXIT_FAILURE);
    }
    return 0;
}

// mmap测试
int test_mmap(char* file)
{
    const char *message = "Hello, mmap!";
    const char *file_path = file;

    int fd = open(file_path, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) 
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fun_mmap(fd, 100, message);

    close(fd);
}

// 内存开辟测试
int  test_memory()
{
    // 使用malloc动态分配内存
    int* arr1 = (int*)malloc(5 * sizeof(int));
    if (arr1 == NULL) {
        perror("malloc 内存分配失败:");
        return 1;
    }

    // 使用calloc动态分配内存，并初始化为0
    int* arr2 = (int*)calloc(5, sizeof(int));
    if (arr2 == NULL) {
        perror("calloc 内存分配失败:");
        return 1;
    }

    // 对动态分配的内存进行写操作
    for (int i = 0; i < 5; i++) {
        arr1[i] = i + 1;
        arr2[i] = i + 1;
    }

    // 输出数组内容
    printf("arr1: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    printf("arr2: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // 使用realloc重新调整分配内存的大小
    int* arr3 = (int*)realloc(arr1, 10 * sizeof(int));
    if (arr3 == NULL) {
        perror("realloc:内存分配失败:");
        return 1;
    }

    // 对重新分配的内存进行写操作
    for (int i = 5; i < 10; i++) {
        arr3[i] = i + 1;
    }

    // 输出重新分配后的数组内容
    printf("arr3: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    // 释放动态分配的内存
    free(arr2);
    free(arr3);
    return 0;
}

// 函数调试信息打印
typedef int(*FunctionCallback1)(const char*);
int function_print(char* name, void* callback, const char* arg1)
{
    int ret = 0;
    printf("{=====[%s()] test start=====\n", name);
    FunctionCallback1 func = (FunctionCallback1)callback;
    ret = func(arg1);
    printf("------[%s()] test end-------}\n\n", name);
    return ret;
}


#define API_DIR_PATH        ".."           // 测试文件目录
#define API_FILE_NAME       API_DIR_PATH "/build/" "file.txt" 
int main_test(int argc, char* argv[])
{
    printf("输入的命令行参数个数为: %d\n", argc);
    for (int i = 0; i < argc; ++i) {
        printf("参数 %d: %s\n", i, argv[i]);
    }
    function_print("test_mmap", test_mmap, API_FILE_NAME);
    return 0;
}

// 环境测试例程
int main(int argc, char* argv[])
{
    main_test(argc, argv);
    return 0;
}
