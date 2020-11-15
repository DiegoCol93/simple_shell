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

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

/* Duplicates a string using malloc. */
char *_strdup(char *str);

/* Executes a program. */
int execute(char **argv);

/* Function that divides a string into an arraw of word. */
char **divide_string(char *str, const char *delim);

/* Function that gets an environment variable. */
char *_getenv(const char *name, char **env);

/* Function that compare strings. */
int _strcmp(const char *s1, const char *s2);

/* Function that prints directories of the path env. */
void print_path(char *name);

/* Function adds a new node at the end of linked list. */
list_t *add_node_end(list_t **head, const char *str);

/* Function that builds a linked list of the PATH directories. */
list_t *list_path(const char *name);

/* Function that print a linked list. */
size_t print_list(const list_t *h);

/* Function that frees a linked list. */
void free_list(list_t *head);

/* Function that frees a child execution. */
void free_exec(char **argv);

#endif /*FILE_H*/
