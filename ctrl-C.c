#include "holberton.h"
/**
 * ctrl_C     - Function to handle the ^C event.
 *
 * Arguments:
 *    @n:     - Input number from signal().
 */
void ctrl_C(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n\033[38;5;40m$ | \033[0m", 19);
}
