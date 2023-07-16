/*
 * 文件名: LinuxFile.c
 * 作者: ljk
 * 创建时间: 2023-07-15
 * 文件描述: 文件读写操操作例程
 */
// strlen包括结束符，sizeof类型的长度，初学者尤其注意字符串指针计算的是指针长度
#include "common.h"

// 文件读写
int fun_fwrite(const char* path, const char* data)
{
    const char* file_path = path;
    const char* file_data = data;
    char buffer[256]; // 缓冲区用于读取和写入文件
    
    FILE *file = fopen(file_path, "w+");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }
    
    // 使用 fwrite 将整数数组写入文件
    size_t elementsWritten = fwrite(data, sizeof(char), strlen(file_data), file);
    if (elementsWritten <= 0) {
        perror("fwrite");
        fclose(file);
        return 1;
    }
     printf("fwrite: %s, write len: %lu, ret len: %ld\n", data, strlen(file_data), elementsWritten);
    
    // 刷新文件缓冲区，确保数据被写入文件
    if (fflush(file) != 0) {
        perror("fflush");
        fclose(file);
        return 1;
    }
    
    // 将读取位置指针从文件开头移动到第10个字节处
    if (fseek(file, 0, SEEK_SET) != 0) {
        perror("fseek");
        fclose(file);
        return 1;
    }

    // 使用 fread 从文件中读取整数数组
    size_t elementsRead = fread(buffer, sizeof(char), sizeof(buffer), file);
    if (elementsRead <= 0) {
        perror("fread");
        fclose(file);
        return 1;
    }

    // 获取文件指针的当前偏移量
    long offset = ftell(file);
    if (offset == -1L) {
        perror("ftell");
        fclose(file);
        return 1;
    }

    fclose(file);
    // 打印读取的整数数组
    printf("fread: %s, ret len: %lu, ftell len: %ld\n", buffer, elementsRead, offset);
    
    return 0;
}

// get字符
// getc/fgetc可以读取文件
int fun_fgetc()
{
    int ch;
    printf("fgetc input character:\n");
    // 使用 fgetc 逐字符读取文件内容
    while ((ch = fgetc(stdin)) != EOF) {
        printf("%c", ch);
        if(ch == '\n')
            break;
    }
    
    printf("getc input character:\n");
    // 使用 getc 逐字符读取标准输入
    while ((ch = getc(stdin)) != EOF) {
        printf("%c", ch);
        if(ch == '\n')
            break;
    }

    printf("getchar input character:\n");
    // 使用 getchar 逐字符读取标准输入
    while ((ch = getchar()) != EOF) {
        printf("%c", ch);
        if(ch == '\n')
            break;
    }
    
    return 0;
}

// put字符
// fputc/putc 也可以输入到文件
int fun_fputc()
{
    char ch = 'A';

    printf("fputc output character:\n");
    // 使用 fputc 将字符写入文件
    if (fputc(ch, stdout) == EOF) {
        perror("fputc");
    }

    printf("\nputc output character:\n");
    // 使用 putc 将字符写入标准输出
    if (putc(ch, stdout) == EOF) {
        perror("putc");
    }

    // 使用 putchar 将字符写入标准输出
    printf("\nputchar output character:\n");
    putchar(ch);
    putchar('\n');
    
    return 0;
}

// 字符串
int fun_fgets()
{
#if 0
    const char* path = API_FILE_NAME;
    const char* data = "Hello, World!";

    FILE *outputFile = fopen(path, "w");
    if (outputFile == NULL) {
        perror("fopen");
        return 1;
    }

    // 使用 fputs 将字符串写入文件
    if (fputs(data, outputFile) == EOF) {
        perror("fputs");
    }
    else{
        printf("Write line from file: %s\n", data); 
    }
    fclose(outputFile);

    char buffer[100];
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    // 使用 fgets 读取文件中的一行字符串
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("Read line from file: %s\n", buffer);
    } 
    else {
        perror("fgets");
    }
    fclose(file);
#else
    char input[100];

    printf("请你输入字符串：");
    fgets(input, sizeof(input), stdin);

    printf("你输入的字符串：");
    fputs(input, stdout);
#endif
    return 0;
}

// fscanf也可以输入到文件里
// %*[^0-9]跳过非数字
int fun_print()
{
    int   number = 10;
    char  buffer[100]; 

    sprintf(buffer, "sprintf: %d\n", number);
    fprintf(stdout, "fprintf: %s", buffer);

    number = 0;
    printf("请输入一个数字\n");
    scanf("%d", &number);
    printf("scanf %d\n", number);

    number = 0;
    printf("请输入一个数字\n");
    fscanf(stdin, "%d", &number);
    printf("fscanf %d\n", number);


    // 使用 sscanf 解析字符串中的数据
    const char *str = "John Doe 25";
    printf("sscanf\n");
    number = 0;
    memset(buffer, 0, 100);
    int num = sscanf(str, "%s%*[^0-9]%d", buffer, &number);

    if (num == 2) {
        printf("Name: %s\n", buffer);
        printf("Number: %d\n", number);
    } 
    else {
        printf("Failed to parse data.\n");
    }

    return 0;
}


// fgetpos fsetpos rewind freopen setvbuf remove
int fun_fqx()
{
    return 0;
}



#ifdef LINUX_MAIN_API_TEST
int main(int argc, char* argv[])
{
    printf("__[fun_fwrite() test]__\n");
    const char* path = API_FILE_NAME;
    const char* data = "Hello, World!";
    fun_fwrite(path, data);

    printf("__[fun_fgetc() test]__\n");
    fun_fgetc();

    printf("__[fun_fputc() test]__\n");
    fun_fputc();

    printf("__[fun_fgets() test]__\n");
    fun_fgets();

    printf("__[fun_print() test]__\n");
    fun_print();

    return 0;
}
#endif