#include "monty.h"

/**
 * sub_op - subtracts the top elements of the stack from the second top
 * @head: pointer to stack top
 * @line_number: line number of command on file
 *
 * Return: void
 */
void sub_op(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, diff;

	h = *head;
	len = list_len(h);

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);

		fclose(collector.file);
		free(collector.cmd_line);
		free_list(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	diff = h->next->n - h->n;
	h->next->n = diff;
	*head = h->next;
	free(h);
}
