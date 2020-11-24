#include "holberton.h"

/**
 * _which       - Function that looks for files in the PATH.
 *
 *  Arguments:
 *  @filename:  - Name of the file to find on PATH.
 *     @env:    - Pointer to enviroment variables.
 *
 *   Return:    - On succes returns a concatenated string with
 *                the absolute path to the file being called or
 *                NULL if it fails.
 *
 * |----------------- Written by Daniel Cortes -----------------|
 * |--------------------- and Diego Lopez ----------------------|
 * |---------------------- November 2020 -----------------------|
 */
char *_which(char *filename, char **env)
{
	list_t *head = NULL;
	list_t *tmp = NULL;
	int i, j, k;
	char *directory = NULL, *ptr = NULL;
	struct stat st;

	head = list_path("PATH", env);
	tmp = head;
	if (tmp)
	{
		for (i = 0; tmp; i++)
		{
			directory = tmp->str;
			for (j = 0; directory[j]; j++)
			{}; /* Length of path. */
			for (k = 0 ; filename[k]; k++)
			{}; /* Length of command. */
			ptr = malloc(sizeof(char) * (k + j + 2));
			if (!ptr)
				return (NULL);
			for (j = 0; directory[j]; j++) /* For Writing dir. */
				ptr[j] = directory[j];
			ptr[j] = '/'; /* For writing '/' */
			for (k = 0; filename[k]; k++)
				ptr[j + k + 1] = filename[k]; /* for writing command  */
			ptr[j + k + 1] = '\0'; /* For writing NULL */
			if (stat(ptr, &st) == 0)
			{
				free_list(head);
				return (ptr);
			}
			free(ptr);
			tmp = tmp->next;
		}
	}
	free_list(head);
	return (NULL);
}
