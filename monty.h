#ifndef monty_h
#define monty_h

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct collect - stores data that needs to move between files and functions
 * @arg: value of n in the stack
 * @file: file opened with the push/pop functions
 * @cmd_line: single command line from file
 *
 * Description: what I've said above
 */
typedef struct collect
{
	char *arg;
	FILE *file;
	char *cmd_line;
} collect_x;
extern collect_x collector;


int execute(char *text_line, stack_t **stack, unsigned int line_number, FILE *op_file);
void push_op(stack_t **head, unsigned int line_number);
void pall_op(stack_t **head, unsigned int line_number);
void pint_op(stack_t **head, unsigned int line_number);
void pop_op(stack_t **head, unsigned int line_number);
void swap_op(stack_t **head, unsigned int line_number);
void add_op(stack_t **head, unsigned int line_number);
void nop_op(stack_t **head, unsigned int line_number);
void free_list(stack_t *head);
int list_len(stack_t *h);


#endif
