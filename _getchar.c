#include "holberton.h"
/**
 * _getchar - Function to read a character from stdin, simple buffered version.
 *
 *  Return: - Pointer to the current character being stored or
 *            EOF when all characters were read, when n = 0.
 *
 * |----------------------- Written by Daniel Cortes ------------------------|
 * |--------------------------- and Diego Lopez -----------------------------|
 * |---------------------------- November 2020 ------------------------------|
 */
int _getchar(void)
{
	static char buf[BUFSIZ];
	static char *bufp = buf;
	static int n;

	if (n == 0)
	{
		n = read(STDIN_FILENO, buf, sizeof(buf));
		bufp = buf;
	}
	return ((--n >= 0) ? (unsigned char)*bufp++ : EOF);
}
