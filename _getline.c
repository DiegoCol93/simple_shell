#include "holberton.h"
/**
 * _getline - Function to get the input of the user from stdin.
 *
 *  Return: - Pointer to a string stored in *buffer taken
 *            from stdin.
 *
 * |--------------- Written by Daniel Cortes ----------------|
 * |------------------- and Diego Lopez ---------------------|
 * |-------------------- November 2020 ----------------------|
 */
char *_getline(void)
{
	int position = 0;
	int c;
	char *buffer = malloc(sizeof(char) * BUFSIZ);

	if (!buffer)
	{
		perror("lsh");
		exit(EXIT_FAILURE);
	}
	while ((c = _getchar())) /* Read a character */
	{
		/* If we hit EOF, replace it with a null character and return.*/
		if (c == EOF)
		{
			buffer[position] = '\0';
			return (buffer);
		}
		if (c == '\n')
		{
			buffer[position] = '\n';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}
		position++;
	}
	return (NULL);
}
