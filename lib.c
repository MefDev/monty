#include "monty.h"

stack_t *push_to_stack(stack_t **stack, const int value)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
        return NULL;

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack)
        (*stack)->prev = new_node;

    *stack = new_node;

    return new_node;
}

int _isdigit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
	}
	return (0);
}
