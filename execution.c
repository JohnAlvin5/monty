#include "monty.h"

int execute(char *text_line, stack_t **stack, unsigned int line_number, FILE *op_file)
{
	unsigned int i;
	char *cmd, *delim = " \n\t";

	instruction_t opcode_list[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"swap", swap_op},
		{"add", add_op},
		{"nop", nop_op},
		{NULL, NULL}
	};

	cmd = strtok(text_line, delim);
	if (cmd && cmd[0] == '#')
		return (0);

	collector.arg = strtok (NULL, delim);

	while (cmd && opcode_list[i].opcode)
	{
		if (strcmp(cmd, opcode_list[i].opcode) == 0)
		{
			opcode_list[i].f(stack, line_number);
			return (EXIT_SUCCESS);
		}
		i++;
	}

	if (opcode_list[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, cmd);
		fclose(op_file);
		free(text_line);
		free_list(*stack);
		return (EXIT_FAILURE);
	}
	return (1);
}
