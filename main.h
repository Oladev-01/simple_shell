#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/wait.h>
#define BUFF 1024
void simple_shell(void);
void cret_ver_2(char *lineptr);
void my_parent_id(pid_t proc);
void exit_shell(char *input);
void print_env();
void exec_command(char *command, char **av);
extern char **environ;
#endif
