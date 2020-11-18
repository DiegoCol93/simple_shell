#include "holberton.h"

/**
 * add_node_end - function adds a new node at the end of linked list.
 * @head: pointer to the head of linked list.
 * @str: string to copy.
 *
 * Return: the address of the new element, or NULL if it failed.
 */
list_t *add_node_end(list_t **head, char *str)
{
	list_t *new_node;
	list_t *last_node;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);
	new_node->str = strdup(str);
	new_node->next = NULL;
	last_node = *head;
	if (*head == NULL)
		*head = new_node;
	else
	{
		while (last_node->next != NULL)
		{
			last_node = last_node->next;
		}
		last_node->next =  new_node;
	}
	return (*head);
}
