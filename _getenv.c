#include "holberton.h"

/**
 * _getenv      - Function that gets the value of a env variable.
 *
 *  Arguments:
 *    @name:    - Name of the enviroment variable.
 *     @env:    - Pointer to enviroment variables.
 *
 *   Return:    - on success, pointer to value of env variable.
 *                NULL for fail.
 *
 * |---------------- Written by Daniel Cortes -----------------|
 * |--------------------- and Diego Lopez ---------------------|
 * |---------------------- November 2020 ----------------------|
 */
char *_getenv(const char *name, char **env)
{
	unsigned int i, j;
	/* extern char **environ; Betty doesn't accept extern variable */
	char *env_value = NULL;
	int equal;

	for (i = 0; env[i] != NULL; i++) /* Runs through env variables */
	{
		for (j = 0; env[i][j] != '='; j++)
		{
			equal =	env[i][j] - name[j];
			if (equal != 0)
				break;
		}
		if (equal == 0)
		{
			for (j = 0; env[i][j]; j++)
			{
				if (env[i][j] == '=')
				{
					env_value = env[i] + j + 1;
					break;
				}
			}
		}
	}
	printf("return : %s\n", env_value);
	return (env_value);
}
