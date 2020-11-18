#include "holberton.h"
/**
 * execute      - Creates the processes for executing a program.
 *
 * Arguments:
 *   @argv:     - Pointer to array of arguments.
 *
 *   Return:    - 0 on success.
 *
 * |----------------- Written by Daniel Cortes -----------------|
 * |--------------------- and Diego Lopez ----------------------|
 * |-------------------- November 12 2020 ----------------------|
 */
int execute(char **argv, char **env)
{
	pid_t pid;
	char *path_name;

	path_name = _which(argv[0], env);
	if (path_name)
	{
		/*Fork a child process.*/
		pid = fork();
		if (pid < 0)
		{
			perror("Error");
			free_exec(argv);
			return (1);
		}
		/*Child process*/
		else if (pid == 0)
		{
			execve(path_name, argv, NULL);
			perror("./hsh");
			free_exec(argv);
			exit(EXIT_FAILURE);
		}
		/*Parent Process*/
		else
		{
			wait(NULL);
		}
		free_exec(argv);
	}
	return (0);
}

/**
 * free_exec    - Creates the processes for executing a program.
 *
 *  Arguments:
 *    @argv:    - Pointer to array of arguments.
 *
 * |---------------- Written by Daniel Cortes ----------------|
 * |-------------------- and Diego Lopez ---------------------|
 * |------------------- November 12 2020 ---------------------|
 */

void free_exec(char **argv)
{
	int i = 0;

	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
