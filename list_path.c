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
 * |-------------------------- November 14 2020 --------------------------|
 */
list_t *list_path(const char *name, char **env)
{
	int i;
	char *value = NULL, *value_2 = NULL, **directories = NULL;
	list_t *head;

	head = NULL;
	value = _getenv(name, env);
	value_2 = _strdup(value);
	directories = divide_string(value_2, ":");
	for (i = 0; directories[i]; i++)
	{
		add_node_end(&head, directories[i]);
		free(directories[i]);
	}
	free(directories);
	free(value_2);
	/*print_list(head);*/
	return (head);
}
