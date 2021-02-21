//
// Created by 程威 on 2021/1/3.
//

#include "command/command.h"
#include "string.h"

#define SPACE ' '


void execute_command(char *cmdline) {

}

int parse_line(char *buf, char **argv) {

    char *delimiter;
    int argc;
    int background;
    buf[strlen(buf) - 1] = SPACE;

    while (*buf && (*buf == SPACE)) {
        buf++;
    }



}

int builtin_command(char **argv) {

}


