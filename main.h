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
int get_bit(unsigned long int n, unsigned int index);
int set_bit(unsigned long int *n, unsigned int index);
void cret_ver_2(void);
void my_parent_id(pid_t proc);
void cret_ver(void);
void read_inp(void);
void exit_shell(void);
void print_env(void);
extern char **environ;
#endif
