#include "monty.h"

/**
 * mul_op - multiplies the top two elements of the stack
 * @head: pointer to stack top
 * @line_number: line number of command on file
 *
 * Return: void
 */
void mul_op(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, result;

	h = *head;
	len = list_len(h);

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);

		fclose(collector.file);
		free(collector.cmd_line);
		free_list(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	result = h->n * h->next->n;
	h->next->n = result;
	*head = h->next;
	free(h);
}
