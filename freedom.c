#include "holberton.h"
/**
 * free_exec    - Creates the processes for executing a program.
 *
 *  Arguments:
 *    @argv:    - Pointer to array of arguments.
 *
 * |---------------- Written by Daniel Cortes ----------------|
 * |-------------------- and Diego Lopez ---------------------|
 * |------------------- November 12 2020 ---------------------|
 */

void free_exec(char **argv)
{
	int i = 0;

	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
