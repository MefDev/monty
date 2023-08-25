#ifndef MOUNTY_H
#define  MOUNTY_H
#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

extern int n;

#define uint unsigned int

extern int number;
#define DELIM "\n\t\r"

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

typedef struct interpreter_s
{
	stack_t **stack;
	unsigned int line_number;
	instruction_t *op_func;
} interpreter_t;

// Function prototypes
void push(stack_t **topstack, uint line_number);
void pall(stack_t **topstack, uint line_number);
void pint(stack_t **topstack, uint line_number);
void pop(stack_t **topstack, uint line_number);
void swap(stack_t **topstack, uint line_number);
void add(stack_t **topstack, uint line_number);
void nop(stack_t **topstack, uint line_number);
void sub(stack_t **topstack, uint line_number);
void _div(stack_t **topstack, uint line_number);
void mul(stack_t **topstack, uint line_number);
void mod(stack_t **topstack, uint line_number);
void (*get_opcodes(char *token, uint line_number))(stack_t **, uint);

void open_error(char **argv);
void int_err(uint line);

void free_stack(stack_t *topstack);
void exec_cmd(char **argv);
int is_number(const char *token);
int is_comment(const char *token);
#endif
