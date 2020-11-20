#include "holberton.h"
/**
 * execute      - Creates the processes for executing a program.
 *
 * Arguments:
 *   @argv:     - Pointer to array of arguments.
 *    @env:     - Pointer to the enviroment variables.
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
	struct stat st;

	if (argv && argv[0])
	{
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
				if (stat(argv[0], &st) != 0)
					free(path_name);
			}
		}
	}
	free_exec(argv);
	return (0);
}
