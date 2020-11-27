#include "holberton.h"

/**
 * _which       - Function that returns the absolute path.
 *
 *  Arguments:
 *  @args_Ex:   - Array of command and arguments.
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
char *_which(char **args_Ex, char **env)
{
	char *ptr = NULL;

	if (args_Ex && args_Ex[0])
	{
		ptr = cat_path(args_Ex, env); /* Concats. path */
		if (ptr)
			return (ptr);
	}
	return (NULL);
}
/**
 * cat_path     - Function that looks for files in the PATH.
 *
 *  Arguments:
 *  @args_Ex:   - Array of command and arguments.
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

char *cat_path(char **args_Ex, char **env)
{
	char *directory = NULL, *fn = NULL, *ptr = NULL;
	list_t *head = NULL, *tmp = NULL;
	int i, j, k = 0;
	struct stat st;

	fn = args_Ex[0];
	head = list_path("PATH", env);
	tmp = head;
	if (tmp)
	{
		for (i = 0; tmp; i++)
		{
			directory = tmp->str;
			for (j = 0; directory[j]; j++)
			{}; /* Length of path. */
			for (k = 0 ; fn[k]; k++)
			{}; /* Length of command. */
			ptr = malloc(sizeof(char) * (k + j + 2));
			if (!ptr)
				return (NULL);
			for (j = 0; directory[j]; j++) /* For Writing dir. */
				ptr[j] = directory[j];
			ptr[j] = '/'; /* For writing '/' */
			for (k = 0; fn[k]; k++)
				ptr[j + k + 1] = fn[k]; /* for writing command  */
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
	if (head)
		free_list(head);
	return (NULL);
}
