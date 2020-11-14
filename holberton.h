#ifndef __FILE_H_
#define __FILE_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

/* Duplicates a string using malloc */
char *_strdup(char *str);

/* Executes a program */
int execute(char **argv);

/* Function that divides a string into an arraw of word */
char **divide_string(char *str);

#endif /*FILE_H*/
