#include "monty.h"

/**
 * nop_op - nope, doesn't do anything
 * @head: pointer to stack top
 * @line_number: line number of command on file
 *
 * Return: void
 */
void nop_op(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}
