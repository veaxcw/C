//
// Created by 程威 on 2021/1/3.
//

#include "../../include/Fork/Fork.h"
#include "../../include/Fork/user_fork.h"
#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"
#include "unistd.h"

void fork_demo() {
    pid_t pid;
    int x = 1;
    pid = Fork();
    if (pid == 0) {
        printf("here is child process,pid:%d,get pid result:%d", pid, getpid());
        exit(0);
    }
    printf("here is parent process,child pid:%d, parent pid:%d", pid,getpid());
}