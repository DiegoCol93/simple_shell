#include "holberton.h"
/**
 * exit_shell  - Built-in function to call the "exit" command.
 *
 *  Arguments:
 *   @buffer:  - Pointer to the command buffer to free.
 *   @arg_B:   - Pointer to the array of strings. from the
 *               tokenized user's input.
 *   @cmd_Num: - Number to count number of commands ran so far.
 *  @prg_name: - Pointer to argv[0] of main function,
 *
 *  Return:    - EXIT_SUCCESS code for a correct execution.
 *
 * |--------------- Written by Daniel Cortes ---------------|
 * |------------------- and Diego Lopez --------------------|
 * |-------------------- November 2020 ---------------------|
 */
int exit_shell(char *buffer, char **arg_B, unsigned int cmd_Num,
	       char *prg_name)
{
	int ret = 0, i = 0;

	if (arg_B[1] != NULL)
	{
		for (i = 0; arg_B[1][i]; i++)
		{
			if (arg_B[1][i] < 48 || arg_B[1][i] > 57)
			{
				err_exit(arg_B, cmd_Num, prg_name);
				return (2);
			}
			else
				ret = _atoi(arg_B[1]);
		}
	}
	if (arg_B)
		free_exec(arg_B);
	free(buffer);
	exit(ret);
}
