#include <stdlib.h>
/**
 * _strdup     - Returns a pointer to a new copy of the string str.
 *
 *  Arguments:
 *    @str:    - Source string.
 *
 *   Return:   - Pointer cpy to new string.
 *
 * |------------------ Written by Daniel Cortes -----------------|
 * |---------------------- and Diego Lopez ----------------------|
 * |----------------------- November 2020 -----------------------|
 */
char *_strdup(char *str)
{
	unsigned int j = 0;
	unsigned int i;
	char *ptr;

	if (str == '\0')
		return ('\0');

	while (str[j] != '\0')
		j++;

	ptr = malloc(sizeof(char) * (j + 1));

	if (ptr != NULL)
		for (i = 0; i <= j; i++)
			ptr[i] = str[i];
	else
		return (NULL);

	return (ptr);
}
