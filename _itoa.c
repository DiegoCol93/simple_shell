#include "holberton.h"
/**
 * _itoa_err   - Prints any number.
 *
 *  Arguments:
 *   @number:  - Number to print.
 *
 *
 *   Return:   - Number of digits printed.
 *
 * |------- Written by Daniel Cortes -------|
 * |----------- and Diego Lopez ------------|
 * |------------ November 2020 -------------|
 */
void _itoa_err(unsigned int number)
{
	unsigned int abs, cypher, div = 1, i, num, last, digit, abs_num;
	char p;

	abs_num = number;
	abs = number;
	for (cypher = 1;  abs_num / 10 > 0; cypher++)
		abs_num = abs_num / 10;
	for (i = cypher - 1; i > 0; i--)
		div = div * 10;
	for (digit = cypher; digit >= 1; digit--)
	{
		num = abs / div;
		if (num >= 10)
		{
			last = num % 10;
			p = last + '0';
			write(STDERR_FILENO, &p, 1);
		}
		else
		{
			p = num + '0';
			write(STDERR_FILENO, &p, 1);
		}
		div = div / 10;
	}
}
