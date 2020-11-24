#include "holberton.h"
/**
 * _calloc     - Function that allocates memory for an array.
 *
 * Arguments:
 *    @nmemb:  - elements of the array.
 *     @size:  - Bytes of each element fo the array.
 *
 *
 * Return:     - pointer with the memory location of the array.
 *
 * |----------------- Written by Daniel Cortes -----------------|
 * |--------------------- and Diego Lopez ----------------------|
 * |---------------------- November 2020 -----------------------|
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr = NULL;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (i = 0 ; i < nmemb * size; i++)
	{
		ptr[i] = 0;
	}
	return ((void *)ptr);
}
