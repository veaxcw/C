//
// Created by 程威 on 2021/1/24.
//

#ifndef EXCEPTION_CSAPP_H
#define EXCEPTION_CSAPP_H
#define MAXSIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <glob.h>
#include "sys/wait.h"
#include "time.h"

/** unix style error**/
void unix_error(char *message);


/*******************************
 * Wrappers for the Fork routines
 ******************************/
pid_t Fork();

/** Sio (Signal-safe I/O) routines */
ssize_t sio_puts(char s[]);

ssize_t sio_putl(long v);

void sio_error(char s[]);

/** safe signal handler**/
void sigint_handler(int sig);

/*******************************
 * Wrappers for the SIO routines
 ******************************/
ssize_t Sio_puts(char s[]);

ssize_t Sio_putl(long v);

void Sio_error(char s[]);

/*******************************
 * Wrappers for the signal
 ******************************/
handler_t *Signal(int signum, handler_t *handler);

/*******************************
 * Wrappers for Process Controller
 ******************************/
unsigned int Sleep(unsigned int seconds);

#endif //EXCEPTION_CSAPP_H

