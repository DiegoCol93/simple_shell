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
	struct stat st;
	int status, result = 0;
	char *path_name = NULL;
	pid_t pid;
	(void)command_Num;

	if (stat(argv[0], &st) == -1)
	{
		path_name = _which(argv[0], env);
		if (path_name == NULL)
		{
			err_not_found(argv, command_Num);
			return (127);
		}
		free(path_name);
	}
	if (argv && argv[0])
	{
		/*Fork a child process.*/
		pid = fork();
		if (pid < 0)
		{
			perror("Fork, I could not have a child");
			free_exec(argv);
			return (1);
		}
		/*Child process*/
		else if (pid == 0)
			child_process(argv, env, command_Num);
		/*Parent Process*/
		else
		{
			if (wait(&status) == -1)
			{
				perror("Wait, I could not wait");
				result = -1;
			}
			else if (WIFEXITED(status))
			{
				result = WEXITSTATUS(status);
			}
		}
	}
	free_exec(argv);
	return (result);
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
		err_not_found(argv, command_Num);
		exit(127);
	}
	path_name = _which(argv[0], env);
	if (path_name)
	{
		if ((execve(path_name, argv, env)) == -1)
		{
			execve(argv[0], argv, env);
		}
	}
/*	if (stat(argv[0], &st))*/
/*		free(path_name);*/
}
