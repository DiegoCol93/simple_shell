#include "holberton.h"
/**
 * exit_shell  - Built-in function to call the "exit" command.
 *
 *  Arguments:
 *   @buffer:  - Pointer to the commands buffer to free.
 *
 *   Return:   - EXIT_SUCCESS code for a correct execution.
 *
 * |--------------- Written by Daniel Cortes ---------------|
 * |------------------- and Diego Lopez --------------------|
 * |------------------ November 18 2020 --------------------|
 */
int exit_shell(char *buffer)
{
	free(buffer);
	exit(EXIT_SUCCESS);
}
