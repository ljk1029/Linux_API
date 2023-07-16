#include <stdio.h> 
#include <stdarg.h>

#define PRINT_ERROR            3
#define PRINT_INFO             2
#define PRINT_DEBUG            1
#define SWITCH_DEBUG_PRINT     0

static int print_level = SWITCH_DEBUG_PRINT;

int init_print(int level)
{
    print_level = level;
    return print_level;
}

void log_print(int level, const char *msg, ...)
{
    #define LOG_BUF_SIZE           (1024)
    if( print_level > level)
        return ;
    
    va_list ap;    
    char message[LOG_BUF_SIZE] = {0}; 
    va_start(ap, msg);  
    vsnprintf(message, LOG_BUF_SIZE, msg, ap);  
    va_end(ap);

    if(PRINT_ERROR == level){
        fprintf(stderr,message);
    }
    else{
        fprintf(stdout,message);
    }
}