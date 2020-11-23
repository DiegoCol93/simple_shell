#include "holberton.h"
/**
 * execute      - Creates the processes for executing a program.
 *
 * Arguments:
 *           @argv:     - Pointer to array of arguments.
 *            @env:     - Pointer to the enviroment variables.
 *    @command_Num:     - Number to count commands input.
 *
 *   Return:    - 0 on success.
 *
 * |----------------- Written by Daniel Cortes -----------------|
 * |--------------------- and Diego Lopez ----------------------|
 * |-------------------- November 12 2020 ----------------------|
 */
int execute(unsigned int command_Num, char **argv, char **env)
{
	pid_t pid;
	(void)command_Num;

	if (argv && argv[0])
	{
		/*Fork a child process.*/
		pid = fork();
		if (pid < 0)
		{
			perror("Fork");
			free_exec(argv);
			return (1);
		}
		/*Child process*/
		else if (pid == 0)
			child_process(argv, env, command_Num);
		/*Parent Process*/
		else
		{
			if (wait(NULL) < 0)
				perror("Wait");
		}
	}
	free_exec(argv);
	return (0);
}
/**
 * child_process        - Manage the child process for executing a program.
 *
 * Arguments:
 *           @argv:     - Pointer to array of arguments.
 *            @env:     - Pointer to the enviroment variables.
 *    @command_Num:     - Number to count commands input.
 *
 *
 *
 *
 * |----------------- Written by Daniel Cortes -----------------|
 * |--------------------- and Diego Lopez ----------------------|
 * |-------------------- November 12 2020 ----------------------|
 */
void child_process(char **argv, char **env, unsigned int command_Num)
{
/*	struct stat st; */
	char *path_name = NULL;

	if (argv[0][0] == '/')
	{
		execve(argv[0], argv, env);
		err_exec(argv, command_Num);
	}
	path_name = _which(argv[0], env);
	if (path_name)
	{
		if ((execve(path_name, argv, env)) == -1)
		{
			execve(argv[0], argv, env);
		}
	}
	err_exec(argv, command_Num);
/*	if (stat(argv[0], &st))*/
/*		free(path_name);*/
}
