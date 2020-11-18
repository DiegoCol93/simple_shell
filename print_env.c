#include "holberton.h"
/**
 * print_env   - Prints the enviroment variables.
 *
 *  Arguments:
 *    @env:    - Pointer to enviroment variables.
 *
 *    Return:  - EXIT_SUCCES on completion.
 *
 * |-------- Written by Daniel Cortes --------|
 * |------------ and Diego Lopez -------------|
 * |------------ November 18 2020 ------------|
 */
int print_env(char **env)
{
	unsigned int i, j;

	for (i = 0; env[i]; i++)
	{
		for (j = 0; env[i][j]; j++)
		{}
		write(STDOUT_FILENO, env[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
