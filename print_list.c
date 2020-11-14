#include "holberton.h"

/**
 * print_list - Prints all the elements of a linked list.
 * @h: head of the linked list.
 *
 * Return: number of nodes in the list.
 */
size_t print_list(const list_t *h)
{
	unsigned int n = 0;

	if (h != NULL)
	{
		while (h != NULL)
		{
			if (h->str == NULL)
			{
				printf("(nil)\n");
			}
			else
			{
				printf("%s\n", h->str);
			}
			h = h->next;
			n++;
		}
		return (n);
	}
	return (0);
}
