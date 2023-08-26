#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 *
 * @topstack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void add(stack_t **topstack, unsigned int line_number) {
    stack_t *nextNode;

    if (*topstack == NULL || (*topstack)->next == NULL) {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    nextNode = (*topstack)->next;
    nextNode->n += (*topstack)->n;
    pop(topstack, line_number);
}

/**
 * nop - Does nothing.
 *
 * @topstack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void nop(stack_t **topstack, unsigned int line_number) {
    (void)topstack;
    (void)line_number;
}

/**
 * sub - Subtracts the top two elements of the stack.
 *
 * @topstack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void sub(stack_t **topstack, unsigned int line_number) {
    stack_t *nextNode;

    if (*topstack == NULL || (*topstack)->next == NULL) {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    nextNode = (*topstack)->next;
    nextNode->n -= (*topstack)->n;
    pop(topstack, line_number);
}
/**
 * open_error - Handles error when the file cannot be opened.
 * @argv: Command-line arguments.
 */
void open_error(char **argv) {
    char *filename = argv[1]; // Declare variables at the beginning of the block
    fprintf(stderr, "Error: can't open file %s\n", filename);
    exit(EXIT_FAILURE);
}

/**
 * int_err - Handles error when "push" is incorrect.
 * @line: The line number where the error occurred.
 */
void int_err(unsigned int line) {
    fprintf(stderr, "L%u: usage: push integer\n", line);
    exit(EXIT_FAILURE);
}
