#ifndef  _LINUX_LOG67890_H__
#define  _LINUX_LOG67890_H__

// 打印等级
#define PRINT_ERROR            3
#define PRINT_INFO             2
#define PRINT_DEBUG            1
#define SWITCH_DEBUG_PRINT     0  // 打印等级开关

#ifdef __cplusplus
extern "C" {
#endif

// 1、宏定义打印
#define __DEBUG__

#ifdef __DEBUG__
#define DPRINTF(...) printf(__VA_ARGS__)  //宏打印函数定义
#else
#define DPRINTF(...)
#endif


// 2、初始化打印
int init_print(int level);
// 打印
void log_print(int level, const char *msg, ...);


// 3、打印文件，函数，行号
int log_debug(char* info);

#ifdef __cplusplus
}
#endif
#endif