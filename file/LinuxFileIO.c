/*
 * 文件名: LinuxFileIO.c
 * 作者: ljk
 * 创建时间: 2023-07-15
 * 文件描述: 文件IO读写操作例程
 */
// 0、1 和 2 标准输入、标准输出和标准错误
#include "common.h"


// 文件权限确认
int fun_access(const char* path)
{
    const char* file_path = path;

    if (access(file_path, R_OK|W_OK|X_OK|F_OK) != 0) {
        perror("access");
    }
    
    return 0;
}

// 文件IO写
int fun_write(const char* path, const char* data)
{
    const char* file_path = path;
    const char* file_data = data;
    int fd; 

    // 打开文件（如果不存在则创建），返回文件描述符
    fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // 写入数据到文件
    if (write(fd, file_data, strlen(file_data)) == -1) {
        perror("write");
        exit(1);
    }

    printf("write: %s, len: %ld\n", file_data, strlen(file_data));
    
     // 刷新缓冲区并将数据写入磁盘 == fflush
    if (fsync(fd) == -1) {
        perror("fsync");
        exit(1);
    }
    
    // 关闭文件
    if (close(fd) == -1) {
        perror("close");
        exit(1);
    }
    
    return 0;
}

// 文件IO读
int fun_read(const char* path)
{
    const char* file_path = path;
    char buffer[256];
    int fd; 
     
    // 重新打开文件进行读取
    fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // 从文件中读取数据到缓冲区
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead == -1) {
        perror("read");
        exit(1);
    }
    
    printf("read: %s, len: %d\n", buffer, (int)bytesRead);
    
    // 关闭文件
    if (close(fd) == -1) {
        perror("close");
        exit(1);
    }

    return 0;
}

// 文件lseek
int fun_lseek(const char* path)
{
    const char* file_path = path;
    int fd; 

    // 打开文件（如果不存在则创建），返回文件描述符
    fd = open(file_path, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // 将文件指针移动到文件的开头
    off_t newOffset = lseek(fd, 0, SEEK_SET);
    if (newOffset == -1) {
        perror("lseek");
        exit(1);
    }

    printf("lseek: %lld\n", (long long)newOffset);

    // 关闭文件
    if (close(fd) == -1) {
        perror("close");
        exit(1);
    }

    return 0;
}

// int fstat(int fd, struct stat *buf);            fd是描述符
// int lstat(const char *path, struct stat *buf);  是指软连接
// 文件stat
int fun_stat(const char* path)
{
    const char* file_path = path;
    struct stat fileStat;

    if (stat(file_path, &fileStat) == -1) {
        perror("stat");
        return 1;
    }

    printf("File Size: %lld bytes\n", (long long)fileStat.st_size);
    printf("File Permissions: %o\n", fileStat.st_mode & 0777);
    printf("File Owner: %d\n", fileStat.st_uid);
    printf("File Group: %d\n", fileStat.st_gid);

    return 0;
}

// 文件dup
int fun_dup(const char* path)
{
    const char* file_path = path;
    int fd1, fd2, fd3;

    // 打开文件 example.txt，并获取文件描述符 fd1
    fd1 = open(file_path, O_RDONLY);
    if (fd1 == -1) {
        perror("open");
        return 1;
    }

    // 使用 dup 复制文件描述符 fd1，创建一个新的文件描述符 fd2
    fd2 = dup(fd1);
    if (fd2 == -1) {
        perror("dup");
        close(fd1);
        return 1;
    }

    // 使用 dup2 复制文件描述符 fd1，创建一个新的文件描述符 fd3
    fd3 = dup2(fd1, 5);
    if (fd3 == -1) {
        perror("dup2");
        close(fd1);
        close(fd2);
        return 1;
    }
    close(fd1);
    close(fd2);
    close(fd3);

    printf("fd1:  %d\n", fd1);
    printf("dup:  %d\n", fd2);
    printf("dup2: %d\n", fd3);

    return 0;
}

int main(int argc, char* argv[])
{
    const char* path = API_FILE_NAME;
    const char* data = "Hello, World!";

    printf("__[fun_write() test]__\n");
    fun_write(path, data);

    printf("__[fun_read() test]__\n");
    fun_read(path);

    printf("__[fun_lseek() test]__\n");
    fun_lseek(path);

    printf("__[fun_stat() test]__\n");
    fun_stat(path);

    printf("__[fun_dup() test]__\n");
    fun_dup(path);

    printf("__[fun_access() test]__\n");
    fun_access(path);

    return 0;
}