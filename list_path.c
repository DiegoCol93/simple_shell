#include "holberton.h"

/**
 * list_path - function that gets the value of a env variable.
 *
 *  Arguments:
 *    @name:    - Pointer to name of env variable.
 *
 *   Return:  - on success, pointer to value of env variable. NULL for fail.
 *
 * |---------------------- Written by Daniel Cortes ----------------------|
 * |-------------------------- and Diego Lopez ---------------------------|
 * |-------------------------- November 14 2020 --------------------------|
 */
list_t *list_path(const char *name)
{
	int i;
	char *value, **directories;
	list_t *head;

	head = NULL;
	value = _getenv(name, NULL);
	directories = divide_string(value, ":");
	for (i = 0; directories[i]; i++)
	{
		add_node_end(&head, directories[i]);
		free(directories[i]);
	}
	free(value);
	free(directories);
	print_list(head);
	return (head);
}
