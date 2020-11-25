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
 * |------------- For important extra info please --------------|
 * |------- open the man page in your preffered txt editor -----|
 * |------------- and go to the comments section ---------------|
 *
 * |----------------- Written by Daniel Cortes -----------------|
 * |--------------------- and Diego Lopez ----------------------|
 * |---------------------- November 2020 -----------------------|
 */
int main(int ac, char **av, char **env)
{
	char *buffer = NULL, *prompt = "\033[38;5;51m$ | \033[0m";
	char **args_Ex = NULL, **args_Bu = NULL;
	int built = 0, exec_res = 0, i = 0;
	static int cmd_Num = 1;

	(void)ac;
	signal(SIGINT, ctrl_C);
	while (1)
	{
		if (isatty(STDIN_FILENO) > 0) /* Manages non-interactive use. */
			write(STDOUT_FILENO, prompt, 18); /* Writes the prompt */
		buffer = _getline(); /* Custom get line function. */
		if (buffer[0] == '\n')
		{
			free(buffer);
			continue; /* If newline found continue. */
		}
		if (buffer[0] == '\0')
			break; /* If null found break. */
		for (i = 0; buffer[i]; i++)
			if (buffer[i] == '\n') /* Change newline for null */
				buffer[i] = '\0';
		args_Bu = divide_string(buffer, " "); /* Tokenize string. */
		/*Get builtin functions. */
		built = get_built_in(args_Bu, env, buffer, cmd_Num, av[0]);
		if (built >= 0)
			exit(built);
		if (built == -1) /* If no built-in was found. */
		{
			args_Ex = divide_string(buffer, " "); /* Tokenize string. */
			free(buffer);/*Execute the commands. */
			exec_res = execute(cmd_Num, args_Ex, env, av[0]);
		}
		if (built == -3)/* If exit function received a bad argument. */
			exec_res = 2;
		cmd_Num++;
	}
	free(buffer);
	return (ret(exec_res));
}
/**
 * ret       - Function to manage execution returns.
 *
 *  Arguments:
 *  @exec_res:    - Result from child or built_in execution.
 *
 *
 *   Return:     - integer with execution result.
 *
 *
 * |------------------ Written by Daniel Cortes -----------------|
 * |---------------------- and Diego Lopez ----------------------|
 * |----------------------- November 2020 -----------------------|
 */
int ret(int exec_res)
{

	if (isatty(STDIN_FILENO) > 0) /* Manages non-interactive use. */
		write(STDOUT_FILENO, "\n", 1); /* Newline after ending. */
	if (exec_res == 127)
		exit(127);
	return (exec_res); /* Manage non-interactive use. */
}
