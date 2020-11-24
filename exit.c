#include "holberton.h"
/**
 * exit_shell  - Built-in function to call the "exit" command.
 *
 *  Arguments:
 *   @buffer:  - Pointer to the command buffer to free.
 *
 *   @arg_B:   - Pointer to the array of strings. from the
 *               tokenized user's input.
 *
 *   Return:   - EXIT_SUCCESS code for a correct execution.
 *
 * |--------------- Written by Daniel Cortes ---------------|
 * |------------------- and Diego Lopez --------------------|
 * |------------------ November 18 2020 --------------------|
 */
int exit_shell(char *buffer, char **arg_B)
{
	int ret = 0;

	if (arg_B[1])
		ret = _atoi(arg_B[1]);
	free_exec(arg_B);
	free(buffer);
	exit(ret);
}
