#include "holberton.h"
/**
 * _puts - Prints string.
 * @str: String input.
 */
void _putsERR(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		write(STDERR_FILENO, &str[i], 1);
		i++;
	}
}
