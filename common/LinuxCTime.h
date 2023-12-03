#ifndef  _LINUX_CTIME_H__
#define  _LINUX_CTIME_H__
#ifdef __cplusplus
extern "C" {
#endif

// 幂次方
int power10(int s, int cnt);
// 延时秒
int delay_s(int cnt);
// 延时毫秒
int delay_ms(int cnt);
// 延时微秒
int delay_us(int cnt);
// 延时纳秒
int delay_ns(int cnt);

#ifdef __cplusplus
}
#endif
#endif