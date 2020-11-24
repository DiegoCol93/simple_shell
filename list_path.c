#include "holberton.h"

/**
 * list_path - function that gets the value of a env variable.
 *
 *  Arguments:
 *    @name:    - Pointer to name of env variable.
 *    @env:     - Pointer to the enviroment variables.
 *
 *   Return:  - on success, pointer to value of env variable. NULL for fail.
 *
 * |---------------------- Written by Daniel Cortes ----------------------|
 * |-------------------------- and Diego Lopez ---------------------------|
 * |--------------------------- November 2020 ----------------------------|
 */
list_t *list_path(const char *name, char **env)
{
	int i;
	char *value = NULL, *value_2 = NULL, **directories = NULL, *ptr = NULL;
	list_t *head = NULL;

	value = _getenv(name, env);
	value_2 = _strdup(value);
	if (value_2[0] == ':')
	{
		for (i = 0; value_2[i]; i++)
		{}
		ptr = malloc(sizeof(char) * i + 2);
		if (ptr == NULL)
			return (NULL);
		for (i = 0; value_2[i]; i++)
		{
			ptr[0] = '.';
			ptr[i + 1] = value_2[i];
		}
		directories = divide_string(ptr, ":");
		free(ptr);
	}
	else
	{
		directories = divide_string(value_2, ":");
		free(value_2);
	}
	for (i = 0; directories[i]; i++)
		if (directories[i])
		{
			add_node_end(&head, directories[i]);
			free(directories[i]);
		}
	free(directories);
/*	print_list(head);    */
	return (head);
}
