#include "monty.h"

collect_x collector = {NULL, NULL, NULL};

/**
 * main - main function
 * @argc: number of arguements
 * @argv: array of arguements
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	unsigned int line_number = 0;
	FILE *op_file;
	char *text_line;
	size_t n = 300;
	ssize_t op_line = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	op_file = fopen(argv[1], "r");
	if (!op_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	collector.file = op_file;

	while (op_line > 0)
	{
		text_line = NULL;
		op_line = getline(&text_line, &n, op_file);
		collector.cmd_line = text_line;
		line_number++;

		if (op_line > 0)
			execute(text_line, &stack, line_number, op_file);

		free(text_line);
	}

	fclose(op_file);
	free_list(stack);

	return (0);
}
