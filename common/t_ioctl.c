#include <sys/ioctl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    struct winsize ws;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) < 0) {
        perror("ioctl");
        return 1;
    }

    printf("窗口大小：宽 %d, 高 %d\n", ws.ws_col, ws.ws_row);
    return 0;
}