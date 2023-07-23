#ifndef  _COMMON_5767_H__
#define  _COMMON_5767_H__


#define API_DIR_PATH   "/mnt/hgfs/MyWork/github/API"      // 测试文件目录
#define API_FILE_NAME  API_DIR_PATH "/build/" "file.txt"   // 测试文件名称
#define LINUX_MAIN_API_TEST                          // 单独测试目录

#ifdef __cplusplus
extern "C" {
#endif

// linux 
#include <dirent.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/wait.h>



// c
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#if 0
#include "LinuxDir.h"
#include "LinuxFile.h"
#include "LinuxFileIO.h"
#include "LinuxLink.h"
#endif

#ifdef __cplusplus
}
#endif
#endif