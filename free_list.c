#include "monty.h"

/**
 * free_list - frees a linked list
 * @head : pointer to first node
 *
 * Return: void
 */
void free_list(stack_t *head)
{
	dlistint_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
