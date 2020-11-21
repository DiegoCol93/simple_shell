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
 *      ______   __   __    __   ______  __       ______
 *     /\  ___\ /\ \ /\  -./  \ /\  == \/\ \     /\  ___\
 *     \ \___  \\ \ \\ \ \-./\ \\ \  _-/\ \ \____\ \  __\
 *      \/\_____\\ \_\\ \_\ \ \_\\ \_\   \ \_____\\ \_____\
 *       \/_____/ \/_/ \/_/  \/_/ \/_/    \/_____/ \/_____/
 *             ______   __  __   ______   __       __
 *            /\  ___\ /\ \_\ \ /\  ___\ /\ \     /\ \
 *            \ \___  \\ \  __ \\ \  __\ \ \ \____\ \ \____
 *             \/\_____\\ \_\ \_\\ \_____\\ \_____\\ \_____\
 *              \/_____/ \/_/\/_/ \/_____/ \/_____/ \/_____/
 *
 * |----------------- Written by Daniel Cortes -----------------|
 * |--------------------- and Diego Lopez ----------------------|
 * |-------------------- November 12 2020 ----------------------|
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL;
	int built = 0;
	char **arguments_e = NULL, **arguments_b = NULL;
	int i = 0;

	(void)ac;
	(void)av;

	signal(SIGINT, ctrl_C);
	while (1)
	{
		if (isatty(STDIN_FILENO) > 0) /* Manages non-interactive use. */
			write(STDOUT_FILENO, "$ ", 2); /* Writes the prompt */
		buffer = _getline(); /* Custom get line function. */
		if (buffer[0] == '\n')
			continue; /* If newline found continue. */
		if (buffer[0] == '\0')
			break; /* If null found break. */
		for (i = 0; buffer[i]; i++)
			if (buffer[i] == '\n') /* Change newline for null */
				buffer[i] = '\0';
		arguments_b = divide_string(buffer, " "); /* Tokenize string. */
		built = get_built_in(arguments_b, env, buffer); /* Get builtin functions. */
		arguments_e = divide_string(buffer, " "); /* Tokenize string. */
		if (built == -1)
			execute(arguments_e, env); /*Execute the commands. */
	}
	if (isatty(STDIN_FILENO) > 0) /* Manages non-interactive use. */
		write(STDOUT_FILENO, "\n", 2); /* Newline after ending. */
	free(buffer);
	return (0); /* Manage non-interactive use. */
}
