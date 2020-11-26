#include "holberton.h"

/**
 * _strcmp     - function that compare strings.
 *
 *  Arguments:
 *     @s1:    - string 1.
 *   @built:   - string 2.
 *
 *   Return:   - integer with the difference between strings.
 *
 * |----------------- Written by Daniel Cortes ----------------------------|
 * |--------------------- and Diego Lopez ---------------------------------|
 * |---------------------- November 2020 ----------------------------------|
 */
int _strcmp(const char *s1, const char *built)
{
	int i = 0;
	int dif;

	for (i = 0 ; s1[i] != '\0' || built[i] != '\0'; i++)
	{
		dif = s1[i] - built[i];
		if (dif != 0)
		{
			return (dif);
		}
		else
		{
			continue;
		}
	}
	return (dif);
}
