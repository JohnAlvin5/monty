#include "monty.h"

/**
 * pall_op - prints all the elements of  a dlistint_t
 * @head : pointer to first node
 * @line_count : line with code being executed
 *
 * Return: void
 */
void pall_op(stack_t **head, unsigned int line_count)
{
	stack_t *current;
	(void) line_count;

	current = *head;
	if (!current)
		return;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}

}
