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
#include <signal.h>
#include <errno.h>

/**
 * struct built_in_s - Structure to save the built_in functions.
 *
 *    Data types:
 *       @str:      - To save the name of the built-in command.
 *        @f:       - Pointer to the corresponding built-in function.
 *
 *   Description:   - This is a structure to save the command name and
 *                    the pointer to its corresponding function.
 */
typedef struct built_in_s
{
	char *str;
	int (*f)();
} built_in_t;

/**
 * struct list_s   - Structure for a linked list PATH env.variable.
 *
 *  Data types:
 *    @str:        - Malloc'ed string to save each dir from PATH.
 *    @next:       - Pointer to the next node.
 *
 *  Description:   - Singly linked list node structure
 *                   for storing and using the PATH variable.
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

/* Duplicates a string using malloc. */
char *_strdup(char *str);

/* Executes a program. */
int execute(unsigned int command_Num, char **argv, char **env);

/* Function that divides a string into an arraw of word. */
char **divide_string(char *str, const char *delim);

/* Function that gets an environment variable. */
char *_getenv(const char *name, char **env);

/* Function that compare strings. */
int _strcmp(const char *s1, const char *s2);

/* Function that prints directories of the path env. */
void print_path(char *name);

/* Function adds a new node at the end of linked list. */
list_t *add_node_end(list_t **head, char *str);

/* Function that builds a linked list of the PATH directories. */
list_t *list_path(const char *name, char **env);

/* Function that print a linked list. */
size_t print_list(const list_t *h);

/* Function that frees a linked list. */
void free_list(list_t *head);

/* Function that frees a child execution. */
void free_exec(char **argv);

/* Function that looks for files in the current PATH. */
char *_which(char *filename, char **env);

/* Function to get the correct built-in being called. */
int get_built_in(char **arguments, char **env, char *buffer);

/* Exit function to cause normal exit of the program. */
int exit_shell(char *buffer);

/* Function to print the enviroment variables. */
int print_env(char **env);

/* Function to handle the ctrl + C event, ^C */
void ctrl_C(int n);

/* Function that sustitute the getline function*/
char *_getline(void);

/* Function that get the line from the prompt*/
int _getchar(void);

/*Function that allocates memory for an array*/
void *_calloc(unsigned int nmemb, unsigned int size);

/*Function to manage execve errors*/
void err_exec(char **argv, unsigned int command_Num);

/*Function to print a number*/
void _itoa(unsigned int number);

/*Function to manage child process for executing a program*/
void child_process(char **argv, char **env, unsigned int command_Num);

/*Function to print error 127*/
void err_not_found(char **argv, unsigned int command_Num);

#endif /*FILE_H*/
