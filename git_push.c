#include "monty.h"

/**
 * add_node - adds a new node at the head of a linked list
 * @head : pointer to first node
 * @n : value of the element n
 *
 * Return: void
 */
void add_node(stack_t **head, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new_node;

	*head = new_node;
}

/**
 * push_op - pushes an element to the stack
 * @head:  pointer to current top
 * @line_number: file line containing current running command
 *
 * Return: void
 */
void push_op(stack_t **head, unsigned int line_number)
{
	int n, i = 0;
	int int_check = 0;
	/* checks if arg is between integer values of ASCII */

	if (collector.arg)
	{
		if (collector.arg[0] == '-')
			i++;
		for (; collector.arg[i] != '\0'; i++)
		{
			if (collector.arg[i] > 57 || collector.arg[i] < 48)
				int_check = 1;
		}

		if (int_check == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(collector.file);
			free(collector.cmd_line);
			free_list(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(collector.file);
		free(collector.cmd_line);
		free_list(*head);
		exit(EXIT_FAILURE);
	}

	n = atoi(collector.arg);
	add_node(head, n);
}
