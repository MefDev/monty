#include "monty.h"

/**
 * is_number - Checks if a string represents a valid number.
 * @token: The string to check.
 *
 * Return: 1 if a valid number, -1 otherwise.
 */

int is_number(const char *token)
{
	if (token == NULL)
		return (-1);

	for (size_t i = 0; token[i] != '\0'; i++)
	{
		if ((token[i] != '-' && !isdigit(token[i])))
			return (-1);
	}
	return (1);
}

/**
 * is_comment - Checks if a token is a comment.
 * @token: The token to check.
 * @line_counter: The current line_number counter.
 *
 * Return: 1 if the token is a comment, -1 otherwise.
 */

int is_comment(const char *token)
{
	if (token == NULL || token[0] == '#')
		return (1);
	return (0);
}

/**
 * free_stack - Frees the stack.
 *
 * @topstack: Pointer to the topstack of the stack.
 */

void free_stack(stack_t *topstack)
{
	while (topstack != NULL)
	{
		stack_t *temp = topstack;
		topstack = topstack->next;
		free(temp);
	}
}
