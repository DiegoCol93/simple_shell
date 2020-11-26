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
	char *buffer = NULL, *cp_buff = NULL;
	int position = 0, c = 0;

	buffer = _calloc(BUFSIZ, sizeof(char));
	if (!buffer)
	{
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	while ((c = _getchar())) /* Read a character */
	{
		/* If we hit EOF, replace it with a null character and return.*/
		if (c == EOF)
		{
			buffer[position] = '\0';
			cp_buff = _strdup(buffer);
			free(buffer);
			return (cp_buff);
		}
		if (c == '\n')
		{
			buffer[position] = '\n';
			cp_buff = _strdup(buffer);
			free(buffer);
			return (cp_buff);
		}
		else
		{
			buffer[position] = c;
		}
		position++;
	}
	return (NULL);
}
