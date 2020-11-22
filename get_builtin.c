#include "holberton.h"
/**
 * get_built_in - Gets the correct built-in function called by
 *                the command prompt.
 *
 *  Arguments:
 *  @argument:  - Pointer to array of strings with the tokens
 *                for the command used and its arguments.
 *
 *     @env:    - Pointer to the enviroment variables.
 *
 *   @buffer:   - Pointer to buffer of commands.
 *
 *    Return:   - On success executes the built-in function,
 *                if the function was not found returns -1.
 *
 * |---------------- Written by Daniel Cortes ----------------|
 * |-------------------- and Diego Lopez ---------------------|
 * |------------------- November 18 2020 ---------------------|
 *
 */
int get_built_in(char **argument, char **env, char *buffer)
{
	int i, j, equal;
	int (*f)();
	built_in_t built[] = {
		{"exit", exit_shell},
		{"env", print_env},
		{NULL, NULL}
	};
	if (argument && argument[0])
	{
		for (i = 0; built[i].str; i++)
		{
			for (j = 0; argument[0][j]; j++)
				equal = argument[0][j] - built[i].str[j];
			if (equal == 0)
			{
				f = built[i].f;
				if (i == 0) /* Call for exit function. */
				{
					free_exec(argument);
					f(buffer);
				}
				if (i == 1) /* Call for env function. */
				{
					f(env);
					return(0);
				}
			}
		}
	}
	free_exec(argument);
	return (-1);
}
