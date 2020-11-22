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
int execute(unsigned int command_Num, char **argv, char **env)
{
	char *path_name = NULL;
	struct stat st;
	pid_t pid;

	if (argv && argv[0])
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
			if (argv[0][0] == '/')
			{
				execve(argv[0], argv, env);
				fprintf(stderr, "./hsh: %d: %s: not found\n", command_Num, argv[0]);
				printf("%d\n", errno);
				exit(127);
			}
			path_name = _which(argv[0], env);
			if ((execve(path_name, argv, env)) == -1)
			{
				execve(argv[0], argv, env);
			}
			fprintf(stderr, "./hsh: %d: %s: not found\n", command_Num, argv[0]);
			printf("%d\n", errno);
			free_exec(argv);
			exit(127);
		}
		/*Parent Process*/
		else
		{
			wait(NULL);
			if (stat(argv[0], &st) != 0)
				free(path_name);
		}
	}
	free_exec(argv);
	return (0);
}
