#include "holberton.h"
#define BUFSIZE 1024

char *_getline(void)
{
	int position = 0;
	int c;
	char *buffer = malloc(sizeof(char) * BUFSIZE);

	if (!buffer)
	{
		perror("lsh");
		exit(EXIT_FAILURE);
	}
	while ((c = _getchar())) /*read a character, calls for another function*/
	{
		/* If we hit EOF, replace it with a null character and return.*/
		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
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
