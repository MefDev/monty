#include "monty.h"

void execute_instruction(char *instruction, interpreter_t *interpreter)
{
    int i;

    if (instruction && instruction[0] != '#') /* Ignore comments */
    {
        for (i = 0; interpreter->op_func[i].opcode; i++)
        {
            if (strcmp(instruction, interpreter->op_func[i].opcode) == 0)
            {
                interpreter->op_func[i].f(interpreter->stack, interpreter->line_number);
                return;
            }
        }
        if (!interpreter->op_func[i].opcode) /* Opcode not found */
        {
            fprintf(stderr, "L%d: unknown instruction %s\n",
                    interpreter->line_number, instruction);
            exit(EXIT_FAILURE);
        }
    }
}

void process_script(FILE *script, interpreter_t *interpreter)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, script)) != -1)
    {
        interpreter->line_number++;
        execute_instruction(line, interpreter);
    }

    free(line);
}

int main(int argc, char *argv[])
{
    FILE *script;
    stack_t *stack = NULL;
    instruction_t op_func[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"sub", sub},
        {"mul", multiply},
        {"div", divide},
        {"nop", nop},
        {NULL, NULL}};
    interpreter_t interpreter;

    interpreter.stack = &stack;
    interpreter.line_number = 0;
    interpreter.op_func = op_func;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    script = fopen(argv[1], "r");
    if (!script)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    process_script(script, &interpreter);

    fclose(script);

    return EXIT_SUCCESS;
}
