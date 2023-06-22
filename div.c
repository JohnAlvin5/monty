#include "monty.h"

/**
 * div_op - divides the second top elements of the stack by the top
 * @head: pointer to stack top
 * @line_number: line number of command on file
 *
 * Return: void
 */
void div_op(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, result;

	h = *head;
	len = list_len(h);

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);

		fclose(collector.file);
		free(collector.cmd_line);
		free_list(*head);
		exit(EXIT_FAILURE);
	}

	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(collector.file);
		free(collector.cmd_line);
		free_list(*head);
		exit(EXIT_FAILURE);
	}

	result = h->next->n / h->n;
	h->next->n = result;
	*head = h->next;
	free(h);
}
