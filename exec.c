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
int execute(char **argv)
{
	pid_t pid;
	int i = 0;

	/*Fork a child process.*/
	pid = fork();
	if (pid < 0)
	{
		perror("Error");
		return (1);
	}
	/*Child process*/
	else if (pid == 0)
	{
		execve(argv[0], argv, NULL);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	/*Parent Process*/
	else
	{
		wait(NULL);
	}
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	return (0);
}
