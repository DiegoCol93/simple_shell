#include "holberton.h"

/**
 * _which      - Function that looks for files in the current PATH
 *
 *  Arguments:
 *    @name:    - Name of the enviroment variable.
 *     @env:    - Pointer to enviroment variables.
 *
 *   Return:    - on success, pointer to value of env variable.
 *                NULL for fail.
 *
 * |----------------- Written by Daniel Cortes -----------------|
 * |--------------------- and Diego Lopez ----------------------|
 * |------------------- November - 14 / 2020 -------------------|
 */
char *_which(char *filename, char **env)
{
	list_t *head = NULL;
	list_t *tmp = NULL;
	int i, j, k;
	char *directory = NULL, *ptr = NULL;
	struct stat st;

	if(stat(filename, &st) == 0)
		return(filename);
	head = list_path("PATH", env);
	tmp = head;
	if (tmp)
	{
		for (i = 0; tmp; i++)
		{
			directory = tmp->str;
			for (j = 0; directory[j]; j++)
			{};
			for (k = 0 ; filename[k]; k++)
			{};
			ptr = malloc(sizeof(char) * (k + j + 2));
			if (!ptr)
				return (NULL);
			for (j = 0; directory[j]; j++)
				ptr[j] = directory[j];
			ptr[j] = '/';
			for(k = 0; filename[k]; k++)
				ptr[j + k + 1] = filename[k];
			ptr[j + k + 1] = '\0';
			if (stat(ptr, &st) == 0)
			{
				return (ptr);
			}
			free(ptr);
			tmp = tmp->next;
		}
	}
	return(NULL);
}
/**int main(int ac, char **av, char **env)
 *{
 *	char *path_name;
 *	(void)ac;
 *	(void)av;
 *
 *	path_name = _which(av[1], env);
 *	printf("%s\n", path_name);
 *	return (0);
 }*/
