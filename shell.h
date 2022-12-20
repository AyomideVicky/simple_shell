#ifndef SHELL_H
#define SHELL_H

/* Macro Definition */
#define TRUE 1
#define EOF -1

/*Libraries Inclusion */
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Function Declaration */
char *_getline(FILE *stream);
void _puts(char *str);
void prompt(int fd, struct stat buf);
#endif
