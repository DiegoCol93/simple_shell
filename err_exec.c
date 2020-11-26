#include "holberton.h"

/**
 * err_exec - Function to print the error 127 to STDERR.
 *
 *  Arguments:
 *    @argv:     - Pointer to array of arguments.
 *   @cmd_Num:   - Number to count number of commands ran so far.
 *  @prg_name:   - Pointer to argv[0] of main function,
 *                 The name of the program.
 *
 * |----------------- Written by Daniel Cortes ------------------|
 * |--------------------- and Diego Lopez -----------------------|
 * |---------------------- November 2020 ------------------------|
 */
void err_exec(char **argv, unsigned int cmd_Num, char *prg_name)
{
	int i = 0;

/*- - - - - - - - All writing below is directed to the STDERR - - - - - - - -*/

	for (i = 0; prg_name[i]; i++) /* For getting lenght of prg_name. */
	{}
	write(STDERR_FILENO, prg_name, i); /* Write prg_name. */
	write(STDERR_FILENO, ": ", 2); /* Write format ": " string. */

	_itoa_err(cmd_Num); /* Converts cmd # and prints it to STDERR. */
	write(STDERR_FILENO, ": ", 2); /* Write format ": " string. */

	for (i = 0; argv[0][i]; i++) /* For getting lenght of input cmd. */
	{}
	write(STDERR_FILENO, argv[0], i); /* Writes cmd used by user. */

	write(STDERR_FILENO, ": not found\n", 12); /* Writes err msg. */

	free_exec(argv);
	exit(EXIT_FAILURE);
}
/**
 * err_not_found - Function to print the error 127 to STDERR.
 *
 *  Arguments:
 *    @argv:     - Pointer to array of arguments.
 *   @cmd_Num:   - Number to count number of commands ran so far.
 *  @prg_name:   - Pointer to argv[0] of main function,
 *                 The name of the program.
 *
 * |----------------- Written by Daniel Cortes ------------------|
 * |--------------------- and Diego Lopez -----------------------|
 * |---------------------- November 2020 ------------------------|
 */
void err_not_found(char **argv, unsigned int cmd_Num, char *prg_name)
{
/*- - - - - - - - All writing below is directed to the STDERR - - - - - - - -*/

	_putsERR(prg_name);
	write(STDERR_FILENO, ": ", 2); /* Write format ": " string. */
	_itoa_err(cmd_Num); /* Converts cmd # and prints it to STDERR. */
	write(STDERR_FILENO, ": ", 2); /* Write format ": " string. */
	_putsERR(argv[0]);
	perror(" ");
	free_exec(argv);
}
/**
 * err_exit - Function to print the error when exit receive bad argument.
 *
 *  Arguments:
 *    @argv:     - Pointer to array of arguments.
 *   @cmd_Num:   - Number to count number of commands ran so far.
 *  @prg_name:   - Pointer to argv[0] of main function,
 *                 The name of the program.
 *
 * |----------------- Written by Daniel Cortes ------------------|
 * |--------------------- and Diego Lopez -----------------------|
 * |---------------------- November 2020 ------------------------|
 */
void err_exit(char **argv, unsigned int cmd_Num, char *prg_name)
{
	int i = 0;

/*- - - - - - - - All writing below is directed to the STDERR - - - - - - - -*/

	for (i = 0; prg_name[i]; i++) /* For getting lenght of prg_name. */
	{}
	write(STDERR_FILENO, prg_name, i); /* Write prg_name. */
	write(STDERR_FILENO, ": ", 2); /* Write format ": " string. */

	_itoa_err(cmd_Num); /* Converts cmd # and prints it to STDERR. */
	write(STDERR_FILENO, ": ", 2); /* Write format ": " string. */

	for (i = 0; argv[0][i]; i++) /* For getting lenght of input cmd. */
	{}
	write(STDERR_FILENO, argv[0], i); /* Writes cmd used by user. */
	write(STDERR_FILENO, ": ", 2); /* Write format ": " string. */

	write(STDERR_FILENO, "Illegal number: ", 16); /* Writes err msg. */

	for (i = 0; argv[1][i]; i++) /* For getting lenght of input argument. */
	{}
	write(STDERR_FILENO, argv[1], i); /* Writes argument used by user. */
	write(STDERR_FILENO, "\n", 1); /* Writes a new line. */
}
/**
 * err_perm - Function to print the error 126 to STDERR.
 *
 *  Arguments:
 *    @argv:     - Pointer to array of arguments.
 *   @cmd_Num:   - Number to count number of commands ran so far.
 *  @prg_name:   - Pointer to argv[0] of main function,
 *                 The name of the program.
 *
 * |----------------- Written by Daniel Cortes ------------------|
 * |--------------------- and Diego Lopez -----------------------|
 * |---------------------- November 2020 ------------------------|
 */
void err_perm(char **argv, unsigned int cmd_Num, char *prg_name)
{
	int i = 0;

/*- - - - - - - - All writing below is directed to the STDERR - - - - - - - -*/

	for (i = 0; prg_name[i]; i++) /* For getting lenght of prg_name. */
	{}
	write(STDERR_FILENO, prg_name, i); /* Write prg_name. */
	write(STDERR_FILENO, ": ", 2); /* Write format ": " string. */

	_itoa_err(cmd_Num); /* Converts cmd # and prints it to STDERR. */
	write(STDERR_FILENO, ": ", 2); /* Write format ": " string. */

	for (i = 0; argv[0][i]; i++) /* For getting lenght of input cmd. */
	{}
	write(STDERR_FILENO, argv[0], i); /* Writes cmd used by user. */

	write(STDERR_FILENO, ": Permission denied\n", 20); /* Writes err msg. */

	free_exec(argv);
}
