#ifndef  _LINUX_TIME_H__
#define  _LINUX_TIME_H__
#ifdef __cplusplus
extern "C" {
#endif

//  1970年1月1日至今的秒数
int fun_time();
//  时间差
int fun_difftime(int cnt);
//  现在时间
int fun_gmtime();
//  现在时间
int fun_localtime();
//  时间戳
int fun_mktime();
//  现在时间
int fun_astime();
//  时间格式化
int fun_strtime();


#ifdef __cplusplus
}
#endif
#endif