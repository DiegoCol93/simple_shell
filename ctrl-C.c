#include "holberton.h"
/**
 * ctrl_C     - Function to handle the ^C event.
 *
 * Arguments:
 *    @n:     - Input number from signal().
 *
 * |-------- Written by Daniel Cortes --------|
 * |------------ and Diego Lopez -------------|
 * |------------- November 2020 --------------|
 */
void ctrl_C(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n\033[38;5;51m$ | \033[0m", 19);
}
