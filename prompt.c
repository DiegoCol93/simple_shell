#include "holberton.h"
/**
 * main         - Program that prints "$ " on the standard output,
 *                waits for the user to enter a command and then
 *	          executes the command entered.
 *
 *  Arguments:
 *     @ac:     - Number of arguments passed when starting shell.
 *     @av:     - Pointer to array of arguments given.
 *    @env:     - Pointer to the enviroment variables.
 *
 *    Return:   - 0 on completion.
 *
 * |----------------- Written by Daniel Cortes -----------------|
 * |--------------------- and Diego Lopez ----------------------|
 * |-------------------- November 12 2020 ----------------------|
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	size_t len = 0;
	int bytes = 0, built = 0;
	char **arguments_e = NULL, **arguments_b = NULL;

	(void)ac;
	(void)av;

	if (isatty(STDIN_FILENO) > 0) /* Manages non-interactive use. */
		write(STDOUT_FILENO, "$ ", 2); /* Writes the prompt */
	while (1)
	{
		bytes = getline(&buffer, &len, stdin); /* Get line as input. */
		if (bytes == -1)
			break;
		buffer[bytes - 1] = '\0'; /* Set null character at end. */
		arguments_b = divide_string(buffer, " "); /* Tokenize string. */
		built = get_built_in(arguments_b, env); /* Get builtin function*/
		arguments_e = divide_string(buffer, " "); /* Tokenize string. */
		if (built == -1)
			execute(arguments_e, env); /* Execute the commands. */
		if (isatty(STDIN_FILENO) > 0) /* Manages non-interactive use. */
			write(STDOUT_FILENO, "$ ", 2); /* Writes prompt. */
	}
	if (isatty(STDIN_FILENO) > 0) /* Manages non-interactive use. */
		write(STDOUT_FILENO, "\n", 2); /* Newline after ending. */
	free(buffer); /* Free the buffer used. */
	return (0); /* Manage non-interactive use. */
}
