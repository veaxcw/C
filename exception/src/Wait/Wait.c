//
// Created by 程威 on 2021/1/3.
//

#include <stdlib.h>
#include "Wait/Wait.h"
#include "common/csapp .h"
#include "stdio.h"
#include "sys/types.h"
#include "sys/wait.h"
#include "unistd.h"
#include "errno.h"
#include "signal.h"
#include "../../include/common/csapp .h"

#define N 2

void wait_demo() {
    int status, i;
    pid_t pid;
    pid_t pids[N];
    for (i = 0; i < N; i++) {
        if ((pids[i] = Fork()) == 0) {
            printf("creat child process success. pid=%d, pid :%d\n",pid, getpid());
            sleep(5);
            exit(100 + i);
        }
    }
    kill(pids[N-1],SIGABRT);
    // 挂起父进程，等待子进程结束, 成功则返回子进程pid
    while ((pid = wait(&status)) > 0) {
        if (WIFEXITED(status)) {
            // 进程正常结束
            printf("child process:%d has exited normally. status:%d\n", pid, WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("child process:%d has been killed by SIG. status:%d\n", pid, WTERMSIG(status));
        } else {
            printf("child process:%d has exited abnormally.\n", pid);
        }
    }
    if (errno != ECHILD) {
        unix_error("wait pid error");
    }

    exit(0);
}

