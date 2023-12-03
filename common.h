#ifndef  _COMMON_5767_H__
#define  _COMMON_5767_H__
#define LINUX_MAIN_API_TEST       // 单独测试开关

#ifdef __cplusplus
extern "C" {
#endif


// Linux 
#include <dirent.h>
#include <fcntl.h>
#include <getopt.h>
#include <termios.h>
#include <sys/resource.h>
#include <sys/utsname.h>
#include <sys/syscall.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <semaphore.h>
#include <pthread.h>
#include <signal.h>
#include <syslog.h>
#include <pwd.h>


// C
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>
#include <stdarg.h>
#include <time.h>
#include <assert.h>


#ifdef __cplusplus
}
#endif
#endif