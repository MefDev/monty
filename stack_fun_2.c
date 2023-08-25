#include "monty.h"

/**
 * add - Adds the topstack two elements of the stack.
 *
 * @topstack: Pointer to the topstack of the stack.
 * @line_number: line_number number of the opcode.
 */

 void add(stack_t **topstack, unsigned int line_number) {
    if (*topstack == NULL || (*topstack)->next == NULL) {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *nextNode = (*topstack)->next;
    nextNode->n += (*topstack)->n;
    pop(topstack, line_number);
}

/**
 * nop - Does nothing.
 *
 * @topstack: Pointer to the topstack of the stack.
 * @line_number: line_number number of the opcode.
 */


 void nop(stack_t **topstack, unsigned int line_number) {
    (void)topstack;
    (void)line_number;
}

/**
 * sub - Subtracts the topstack two elements of the stack.
 *
 * @topstack: Pointer to the topstack of the stack.
 * @line_number: line_number number of the opcode.
 */

void sub(stack_t **topstack, unsigned int line_number) {
    if (*topstack == NULL || (*topstack)->next == NULL) {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
	stack_t *nextNode;

    nextNode = (*topstack)->next;
    nextNode->n -= (*topstack)->n;
    pop(topstack, line_number);
}
 
/**
 * _div - Divides the topstack two elements of the stack.
 *
 * @topstack: Pointer to the topstack of the stack.
 * @line_number: line_number number of the opcode.
 */

 
void _div(stack_t **topstack, unsigned int line_number) {
    if (*topstack == NULL || (*topstack)->next == NULL) {
        fprintf(stderr, "L%u: can't _div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *tmp;
	tmp = *topstack;

    if (tmp->n == 0) {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    tmp->next->n /= tmp->n;
    *topstack = tmp->next;
    free(tmp);
}

/**
 * mul - Multiplies the topstack two elements of the stack.
 *
 * @topstack: Pointer to the topstack of the stack.
 * @line_number: line_number number of the opcode.
 */

 void mul(stack_t **topstack, unsigned int line_number) {
    if (*topstack == NULL || (*topstack)->next == NULL) {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *nextNode = (*topstack)->next;
    nextNode->n *= (*topstack)->n;
    pop(topstack, line_number);
}

/**
 * mod - Mods the topstack two elements of the stack.
 *
 * @topstack: Pointer to the topstack of the stack.
 * @line_number: line_number number of the opcode.
 */

 void mod(stack_t **topstack, unsigned int line_number) {
    if (*topstack == NULL || (*topstack)->next == NULL) {
        fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    stack_t *tmp;
	tmp = *topstack;

    if (tmp->n == 0) {
        fprintf(stderr, "L%u: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    tmp->next->n %= tmp->n;
    *topstack = tmp->next;
    free(tmp);
}
/**
 * open_error - Handles error when the file cannot be opened.
 * @argv: Command-line arguments.
 */
void open_error(char **argv) {
    char *filename;
	filename = argv[1];
    fprintf(stderr, "Error: can't open file %s\n", filename);
    exit(EXIT_FAILURE);
}
 
/**
 * int_err - Handles error when "push"
 * @line: The line number where the error was occurred.
 */

void int_err(unsigned int line) {
    fprintf(stderr, "L%u: usage: push integer\n", line);
    exit(EXIT_FAILURE);
}

 
















