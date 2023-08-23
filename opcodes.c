#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, "\n\t\r ");
    int n;

    if (arg == NULL || _isdigit(arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(arg);

    if (!push_to_stack(stack, n))
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * pall - Prints all the values on the stack.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * pint - Prints the value at the top of the stack.
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (!stack || !*stack)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top element of the stack.
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (!stack || !*stack)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;
    if (*stack)
        (*stack)->prev = NULL;
    free(temp);
}

/**
 * swap - Swaps the top two elements of the stack.
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int temp;

    if (!stack || !*stack || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}
