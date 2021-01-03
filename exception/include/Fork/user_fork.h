//
// Created by 程威 on 2020/12/6.
//

#ifndef EXCEPTION_USER_FORK_H
#define EXCEPTION_USER_FORK_H
#include "sys/types.h"


/*
 * wrapper syscall fork a new process
 * printf message if fork failed
 */
pid_t Fork();

void unix_error(char *message);

#endif //EXCEPTION_USER_FORK_H
