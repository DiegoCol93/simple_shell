#include "holberton.h"
/**
 * execute       - Creates the processes for executing a program.
 *
 *  Arguments:
 *  @cmd_Num:    - Number to count commands input.
 *  @args_Ex:    - Pointer to array of arguments.
 *    @env:      - Pointer to the enviroment variables.
 *  @prg_name:   - Name used to run the program from the main.
 *
 *   Return:     - 0 on success or :
 *               - 127, if the executable file could not be found.
 *
 * |------------------ Written by Daniel Cortes -----------------|
 * |---------------------- and Diego Lopez ----------------------|
 * |----------------------- November 2020 -----------------------|
 */
int execute(unsigned int cmd_Num, char **args_Ex, char **env, char *prg_name)
{
/*	char *path_name = NULL; */
	int status, result = 0;
	struct stat st;
	pid_t pid;

	if (stat(args_Ex[0], &st) == -1)
	{
		if (check_path(args_Ex, cmd_Num, env, prg_name) != 0)
			return (127);
	}
	if (args_Ex && args_Ex[0])
	{ /*Fork a child process.*/
		pid = fork();
		if (pid < 0)
		{
			perror("Fork, I could not have a child");
			free_exec(args_Ex);
			return (1);
		}
		/*Child process*/
		else if (pid == 0)
			child_Ex(args_Ex, env, cmd_Num, prg_name);
		/*Parent Process*/
		else
			if (wait(&status) == -1)
			{
				perror("Wait, I could not wait");
				result = -1;
			}
			else if (WIFEXITED(status))
				result = WEXITSTATUS(status);
	}
	free_exec(args_Ex);
	return (result);
}
/**
 * child_Ex        - Manage the child process for executing a program.
 *
 *   Arguments:
 *    @args_Ex:    - Pointer to array of arguments.
 *      @env:      - Pointer to the enviroment variables.
 *    @cmd_Num:    - Number to count commands input.
 *   @prg_name:    - Name used to run the program from the main.
 *
 * |------------------- Written by Daniel Cortes -------------------|
 * |----------------------- and Diego Lopez ------------------------|
 * |---------------------- November 12 2020 ------------------------|
 */
void child_Ex(char **args_Ex, char **env, unsigned int cmd_Num, char *prg_name)
{
/*	struct stat st; */
	char *path_name = NULL;

	if (args_Ex[0][0] == '/')
	{
		execve(args_Ex[0], args_Ex, env);
		err_not_found(args_Ex, cmd_Num, prg_name);
		exit(127);
	}
	path_name = _which(args_Ex[0], env);
	if (path_name)
	{
		if ((execve(path_name, args_Ex, env)) == -1)
		{
			execve(args_Ex[0], args_Ex, env);
		}
	}
/*	if (stat(args_Ex[0], &st))*/
/*		free(path_name);*/
}
/**
 * check_path    - Function to check for the given file name on the PATH.
 *
 *  Arguments:
 *   @args_Ex:   - Arguments of the command to be freed if not found.
 *    @cmd_N:    - Counter of the command number being run.
 *    @env:      - Pointer to the eviroment variables.
 *  @prg_name:   - Name of the program used to run the shell.
 *
 *   Return:     - 0 if path was found, 127 when not.
 *
 * |-------------------- Written by Daniel Cortes --------------------|
 * |------------------------ and Diego Lopez -------------------------|
 * |----------------------- November 12 2020 -------------------------|
 */
int check_path(char **args_Ex, unsigned int cmd_N, char **env, char *prg_name)
{
	char *path_name = NULL;

	path_name = _which(args_Ex[0], env);
	if (path_name == NULL)
	{
		err_not_found(args_Ex, cmd_N, prg_name);
		return (127);
	}
	free(path_name);
	return (0);
}
