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
	int bytes = 0;
	char **arguments;

	(void)ac;
	(void)av;

	if (isatty(STDIN_FILENO) > 0)
		write(STDOUT_FILENO, "$ ", 2);
	while (1)
	{
		bytes = getline(&buffer, &len, stdin);
		if (bytes == -1)
			break;
		buffer[bytes - 1] = '\0';
		arguments = divide_string(buffer, " ");
		execute(arguments, env);
		if (isatty(STDIN_FILENO) > 0)
			write(STDOUT_FILENO, "$ ", 2);
	}
	if (isatty(STDIN_FILENO) > 0)
		write(STDOUT_FILENO, "\n", 2);
	free(buffer);
	return (0);
}
