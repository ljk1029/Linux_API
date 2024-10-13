/*
 * 文件名: LinuxFile.c
 * 作者: ljk
 * 创建时间: 2023-07-15
 * 文件描述: 文件读写操操作例程, C 标准库中
 */
// strlen包括结束符，sizeof类型的长度，初学者尤其注意字符串指针计算的是指针长度
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "LinuxFile.h"




// 打开测试文件
int fun_fopen(int action, char* path, char* mode, FILE** _fp)
{
    if(action)
    {
        printf("打开文件: %s, mode: %s\n", path, mode);
        FILE *fp = fopen(path, mode);
        *_fp = fp;
        if (fp == NULL) {
            perror("fopen");
            return 1;
        }
    }
    else{
        fclose(*_fp);
        *_fp = NULL;
    }
   
    return 0;
}

// flie文件读写
int fun_fwrite(const char* path, const char* data)
{
    const char* file_path = path;
    const char* file_data = data;
    char buffer[256]; // 缓冲区用于读取和写入文件
    
    printf("打开文件: %s\n", file_path);
    FILE *fp = fopen(file_path, "w+");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }
    
    // 使用 fwrite 将整数数组写入文件
    size_t flie_len = fwrite(file_data, sizeof(char), strlen(file_data), fp);
    if (flie_len <= 0) {
        perror("fwrite");
        fclose(fp);
        return 1;
    }
    printf("写入文件: %s, ret len: %ld, write len: %lu\n", file_data, flie_len, strlen(file_data));
    
    // 刷新文件缓冲区，确保数据被写入文件
    if (fflush(fp) != 0) {
        perror("fflush");
        fclose(fp);
        return 1;
    }
    
    // 将读取位置指针从文件开头移动到第0个字节处
    if (fseek(fp, 0, SEEK_SET) != 0) {
        perror("fseek");
        fclose(fp);
        return 1;
    }

    // 使用 fread 从文件中读取整数数组
    size_t read_len = fread(buffer, sizeof(char), sizeof(buffer), fp);
    if (read_len <= 0) {
        perror("fread");
        fclose(fp);
        return 1;
    }

    // 获取文件指针的当前偏移量
    long offset = ftell(fp);
    if (offset == -1L) {
        perror("ftell");
        fclose(fp);
        return 1;
    }

    fclose(fp);
    // 打印读取的整数数组
    printf("读出文件: %s, ret len: %lu, ftell len: %ld\n", buffer, read_len, offset);
    
    return 0;
}

// getc/fgetc标准输入,也可以读取文件,getchar只能标准输入
int fun_fgetc()
{
    int ch;
    // 使用fgetc() 逐字符读取文件内容
    printf("fgetc请输入字符:\n");
    while ((ch = fgetc(stdin)) != EOF) {
        printf("%c", ch);
        if(ch == '\n')
            break;
    }
    
    // 使用getc() 逐字符读取标准输入
    printf("getc请输入字符:\n");
    while ((ch = getc(stdin)) != EOF) {
        printf("%c", ch);
        if(ch == '\n')
            break;
    }

    // 使用getchar() 逐字符读取标准输入
    printf("getchar请输入字符:\n");
    while ((ch = getchar()) != EOF) {
        printf("%c", ch);
        if(ch == '\n')
            break;
    }
    
    return 0;
}

// fputc/putc标准输出,也可以写入到文件,putchar只能标准输出
int fun_fputc()
{
    char ch = 'A';

    // 使用fputc() 逐字符写入文件内容
    printf("fputc 输出字符:\n");
    if (fputc(ch, stdout) == EOF) {
        perror("fputc");
    }
    fputc('\n', stdout);

    // 使用putc() 逐字符输出标准输出
    printf("putc 输出字符:\n");
    if (putc(ch, stdout) == EOF) {
        perror("putc");
    }
    putc('\n', stdout);

    // 使用putchar() 逐字符输出标准输出
    printf("putchar 输出字符:\n");
    if (putchar(ch) == EOF) {
        perror("putchar");
    }
    putchar('\n');
    
    return 0;
}

// fgets/puts字符串测试,也可以对文件进行操作
int fun_fgets()
{
    char input[100]={0};

    printf("fgets请输入字符串:");
    fgets(input, sizeof(input), stdin);

    printf("fputs输入的字符串:");
    fputs(input, stdout);

    return 0;
}

// fscanf标准输入解析,也可以读取文件里字符进行解析
// %*[^0-9]跳过非数字
int fun_print()
{
    int   number = 10;
    char  buffer[100]; 

    // scanf解析
    sprintf(buffer, "sprintf: %d\n", number);
    fprintf(stdout, "fprintf解析: %s", buffer);

    number = 0;
    printf("请输入一个数字\n");
    scanf("%d", &number);
    printf("scanf解析: %d\n", number);

    number = 0;
    printf("请输入一个数字\n");
    fscanf(stdin, "%d", &number);
    printf("fscanf解析: %d\n", number);

    // 使用 sscanf 解析字符串中的数据
    const char *instr = "John Doe 25";
    printf("sscanf解析:%s\n", instr);
    number = 0;
    memset(buffer, 0, 100);
    int num = sscanf(instr, "%s%*[^0-9]%d", buffer, &number);

    if (num == 2) {
        printf("Name:   %s\n", buffer);
        printf("Number: %d\n", number);
    } 
    else {
        printf("Failed to parse data.\n");
    }

    return 0;
}

// open()、socket()、pipe()等描述符打开文件
int fun_fopenfd(const char* path)
{
    printf("打开文件: %s\n", path);

    int fd = open(path, O_RDONLY); 
    if (fd != -1)
    {
        FILE* fp = fdopen(fd, "r");
        if (fp != NULL) 
        {
            char buffer[256];
            size_t read_len = fread(buffer, sizeof(char), sizeof(buffer), fp);
            if (read_len <= 0) {
                perror("fread");
                fclose(fp);
                return 1;
            }
            printf("读出文件: %s\n", buffer);
            fclose(fp);
        } 
        else
        {
            perror("创建文件指针时出错");
        }
    }
    else
    {
        perror("打开文件时出错");
    }

    return 0;
}

// fgetpos fsetpos rewind freopen setvbuf remove
int fun_preserve()
{
    printf("Preserve extension functions\n");
    return 0;
}

// 函数调试信息打印
typedef int(*FunctionCallback)(void);
typedef int(*FunctionCallback1)(const char*);
typedef int(*FunctionCallback2)(const char*, const char*);

int function_print(char* name, void* callback, const char* arg1, const char* arg2)
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
        FunctionCallback2 func = (FunctionCallback2)callback;
        ret = func(arg1, arg2);
    }
    printf("------[%s()] test end-------}\n\n", name);
    return ret;
}


// 测试文件目录
#define API_DIR_PATH     ".."           
#define API_FILE_NAME    API_DIR_PATH "/build/" "file.txt" 

int main_test(int argc, char* argv[])
{
    printf("输入的命令行参数个数为: %d\n", argc);
    for (int i = 0; i < argc; ++i) {
        printf("参数 %d: %s\n", i, argv[i]);
    }
    const char* path = API_FILE_NAME;
    const char* data = "Hello, World!";
    function_print("fun_fwrite", fun_fwrite, path, data);
    function_print("fun_fgetc",  fun_fgetc, NULL, NULL);
    function_print("fun_fputc",  fun_fputc, NULL, NULL);
    function_print("fun_fgets",  fun_fgets, NULL, NULL);
    function_print("fun_print",  fun_print, NULL, NULL);
    function_print("fun_fopenfd",  fun_fopenfd, path, NULL);
    return 0;
}

int main(int argc, char* argv[])
{
    main_test(argc, argv);
    return 0;
}