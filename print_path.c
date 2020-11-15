#include "holberton.h"

/**
 * print_path - function that prints directories of the path env.
 *
 *  Arguments:
 *    @name:    - Pointer to PATH of env variable.
 *
 *
 * |---------------------- Written by Daniel Cortes ----------------------|
 * |-------------------------- and Diego Lopez ---------------------------|
 * |-------------------------- November 14 2020 --------------------------|
 */
void print_path(char *name)
{
	char *value, **directories;
	int i = 0;

	name = "PATH";
	value = _getenv(name, NULL);
	directories = divide_string(value, ":");
	if (directories)
	{
		for (i = 0; directories[i]; i++)
			printf("%s\n", directories[i]);
	}
	else
		printf("(null)\n");
}
