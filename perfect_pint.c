#include "monty.h"

/**
 * pint_op - prints the value at the top of the stack
 * @head: pointer to top of stack
 * @line_number: file line where current command is located
 *
 * Return: void
 */
void pint_op(stack_t **head, unsigned int line_number)
{
	if (*head = NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);

		fclose(collector.file);
		free(bus.cmd_line);
		free_list(*head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
