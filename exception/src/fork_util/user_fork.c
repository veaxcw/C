//
// Created by 程威 on 2020/12/6.
//
#include <stdio.h>
#include <stdlib.h>
#include "unistd.h"
#include "Fork/user_fork.h"
#include "string.h"

pid_t Fork() {
    pid_t pid;
    if ((pid = fork()) < 0) {
        unix_error("Fork error");
        exit(0);
    }
    return pid;
}

void unix_error(char *message) {
    int errno = 0;
    fprintf(stderr, "%s: %s\n", message, strerror(errno)) ;
}