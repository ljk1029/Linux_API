/*
 * 文件名: LinuxMmap.c
 * 作者: ljk
 * 创建时间: 2023-07-15
 * 文件描述: mmap测试
 */
#include "../common.h"



// 将文件映射到内存
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
int test_mmap()
{
    const char *message = "Hello, mmap!";
    const char *file_path = API_FILE_NAME;

    int fd = open(file_path, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) 
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fun_mmap(fd, 100, message);

    close(fd);
}



// 测试例程
int main(int argc, char* argv[]) 
{
    printf("__[fun_mmap() test]__\n");
    test_mmap();
    return 0;
}
