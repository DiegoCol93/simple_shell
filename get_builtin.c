#include "holberton.h"

/**
 * get_built_in - Gets the correct built-in function called by
 *                the command prompt.
 *
 *  Arguments:
 *   @args_Bu:  - Pointer to array of strings with the tokens
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
 * |--------------------- November 2020 ----------------------|
 *
 */
int get_built_in(char **args_Bu, char **env, char *buffer)
{
	int i, equal = 0;
	int (*f)();
	built_in_t built[] = {
		{"exit", exit_shell},
		{"env", print_env},
		{NULL, NULL}
	};
	if (args_Bu && args_Bu[0])
	{
		for (i = 0; built[i].str; i++)
		{
			/*Compare args_Bu with structure string*/
			equal = _strcmp(args_Bu[0], built[i].str);
			if (equal == 0)
			{
				f = built[i].f;
				if (i == 0) /* Call for exit function. */
				{
/*					free_exec(args_Bu); free inside exit. */
					f(buffer, args_Bu);
				}
				if (i == 1) /* Call for env function. */
				{
					free_exec(args_Bu);
					f(env);
					free(buffer);
					return (-2);
				}
			}
		}
	}
	free_exec(args_Bu);
	return (-1);
}
