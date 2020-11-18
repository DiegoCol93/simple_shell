#include "holberton.h"

/**
 * divide_string - Function that splits a string into words,
 *                 using the space character as a divider
 *                 and creates an array of words.
 *   Arguments:
 *     @str:     - String to split.
 *    @delim:    - Delimiter character.
 *
 *    Return:    - Array of words of from string.
 *
 * |-------------- Written by Daniel Cortes --------------|
 * |------------------- and Diego Lopez ------------------|
 * |---------------- November - 12 - 2020 ----------------|
 */
char **divide_string(char *str, const char *delim)
{
	char *token, *token2;
	int i = 0, count = 0;
	char **buffer;
	char *str2;

	str2 = _strdup(str);
	token = strtok(str, delim);
	while (token != NULL) /* for counting words */
	{
		token = strtok(NULL, delim);
		count++;
	}
	buffer = malloc(sizeof(char *) * (count + 1));
	token2 = strtok(str2, delim);
	while (token2 != NULL) /* for writing on buffer */
	{
		buffer[i] = _strdup(token2);
		token2 = strtok(NULL, delim);
		i++;
	}
	buffer[i] = NULL;
	free(str2);
	return (buffer);
}
