//
// Created by 程威 on 2021/1/24.
//
#include "../../include/common/csapp .h"

/**
 * custom signal handler
 * */
void custom_handler(int sig) {
    int olderrno = errno;
    // 等待当前进程至少一个子进程结束
    pid_t pid;
    if ((pid=waitpid(-1, NULL, 0)) < 0) {
        sio_error("waitpid error");
    }
    Sio_puts("Handler reaped child,pid:");
    Sio_putl(pid);
    Sio_puts("\n");
    Sleep(1);
    errno = olderrno;
}

void wait_all_finished(int sig) {
    int olderrno = errno;
    // 等待当前进程至所有子进程结束
    pid_t pid;
    while ((pid=waitpid(-1, NULL, 0)) > 0) {
        Sio_puts("Handler reaped child,pid:");
        Sio_putl(pid);
        Sio_puts("\n");
        Sleep(1);
    }
    if (errno != ECHILD) {
        Sio_puts("wait pid failed");
    }
    errno = olderrno;
}

int buggy_demo1() {
    int i, n;
    char buf[MAXSIZE];
    if (signal(SIGCHLD, wait_all_finished) == SIG_ERR) {
        unix_error("signal error");
    }

    for (i = 0; i < 3; i++) {
        if (Fork() == 0) {
            printf("here is child process,pid:%d\n", getpid());
            Sleep(1);
            exit(0);
        }
    }

    if ((n = read(STDIN_FILENO, buf, sizeof(buf))) < 0) {
        unix_error("read");
    }
    printf("parent process input\n");
    while (1);
    exit(0);


}