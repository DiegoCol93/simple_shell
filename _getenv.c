#include "holberton.h"

/**
 * _getenv - function that gets the value of a env variable.
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
char *_getenv(const char *name)
{
	unsigned int i, j;
	extern char **environ;
	char **argument = NULL, *env_value = NULL;
	int equal;

	i = 0;
	while (environ[i] != NULL) /* Runs through env variables */
	{
		argument = divide_string(environ[i], "=");
		equal = _strcmp(argument[0], name);
		if (equal == 0)
		{
			env_value = _strdup(argument[1]);
			for (j = 0; argument[j]; j++)
				free(argument[j]);
			free(argument);
			break;
		}
		for (j = 0; argument[j]; j++)
			free(argument[j]);
		free(argument);
		i++;
	}
	return (env_value);
}
