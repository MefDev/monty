#include "monty.h"

int data_structure_type = 0;
int number;

/**
 * push - Pushes an element to the stack.
 *
 * @topstack: Pointer to the topstack of the stack.
 * @line_number: Line number of the opcode.
 */
void push(stack_t **topstack, unsigned int line_number) {
    stack_t *new_node;

    new_node = (stack_t *)malloc(sizeof(stack_t));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = line_number;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*topstack == NULL) {
        *topstack = new_node;
    } else if (data_structure_type == 1) {
        stack_t *last;

        last = *topstack;
        while (last->next != NULL)
            last = last->next;
        new_node->prev = last;
        last->next = new_node;
    } else {
        new_node->next = *topstack;
        (*topstack)->prev = new_node;
        *topstack = new_node;
    }
}

/**
 * pall - Prints all the values on the stack.
 *
 * @topstack: Pointer to the topstack of the stack.
 * @line_number: Line number of the opcode.
 */
void pall(stack_t **topstack, unsigned int line_number) {
    stack_t *tmp;

    tmp = *topstack;
    while (tmp != NULL) {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
    (void)line_number;
}



/**
 * pint - Prints the value at the top of the stack.
 *
 * @topstack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void pint(stack_t **topstack, unsigned int line_number) {
    if (*topstack == NULL) {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n", (*topstack)->n);
}



/**
 * swap - Swaps the top two elements of the stack.
 *
 * @topstack: Pointer to the top of the stack.
 * @line_number: Line number of the opcode.
 */
void swap(stack_t **topstack, unsigned int line_number) {
    if (*topstack == NULL || (*topstack)->next == NULL) {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }
    int num = (*topstack)->n;
    (*topstack)->n = (*topstack)->next->n;
    (*topstack)->next->n = num;
}
