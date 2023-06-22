#include "monty.h"

/**
 * list_len - returns the number of elements in a linked list
 * @h : pointer to first node
 *
 * Return: number of elements
 */
int list_len(stack_t *h)
{
	int count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}

	return (count);
}
