//
// Created by 程威 on 2021/1/3.
//

#ifndef BASH_COMMAND_H
#define BASH_COMMAND_H

#define MAXARGS 128

///
/// \param cmdline
void execute_command(char *cmdline);

///
/// \param buf
/// \param argv
/// \return
int parse_line(char *buf, char **argv);

///
/// \param argv
/// \return
int builtin_command(char **argv);


#endif; //BASH_COMMAND_H
