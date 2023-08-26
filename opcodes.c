#include "monty.h"

/**
 * get_opcodes - Retrieves the appropriate function pointer for an opcode.
 *
 * @token: Opcode token to compare.
 * @line_number: Line number of the opcode.
 * Return: Pointer to the corresponding function.
 */
typedef void (*FunctionPtr)(stack_t **, uint);

void (*get_opcodes(char *token, uint line_number))(stack_t **, uint)
{

    struct Operation {
        char *opcode;
        FunctionPtr function;
    };

    struct Operation operations[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"nop", nop},
        {"add", add},
        {"sub", sub},
        {"_div", _div},
        {"mul", mul},
        {"mod", mod},
        {NULL, NULL}
    };

   
    for (int i = 0; operations[i].opcode != NULL; i++)
    {
        if (strcmp(token, operations[i].opcode) == 0)
        {
            return (operations[i].function);
        }
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
    exit(EXIT_FAILURE);

    return NULL;
}
