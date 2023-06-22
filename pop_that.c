#include "monty.h"

/**
 * pop_op - removes the top element of the stack
 * @head : pointer to the top
 * @line_number : file line where current command is
 *
 * Return: void
 */
void pop_op(stack_t **head, unsigned int line_number)
{
	stack_t *current, *next;

	if (!*head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);

		fclose(collector.file);
		free(collector.cmd_line);
		free_list(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	next = current->next;

	free(current);
	*head = next;

}
