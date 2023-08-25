#include "monty.h"
/**
 * exec_cmd - Opens and reads the Monty file, executing the commands.
 * @argv: pointer to array of arguments.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

void exec_cmd(char **argv) {
    FILE *fp = fopen(argv[1], "r");

    if (!fp)
        open_error(argv);

    ssize_t read;

    char *line = NULL;
    size_t len = 0;
    stack_t *topstack = NULL;
    unsigned int line_counter = 1;

    while ((read = getline(&line, &len, fp)) != -1) {
        char *token = strtok(line, DELIM);
        if (!token)
            continue;

        char command[1024];
        strcpy(command, token);

        if (is_comment(token)) {
            line_counter++;
            continue;
        }

        void (*p_func)(stack_t **, unsigned int);
        if (!strcmp(token, "push")) {
            token = strtok(NULL, DELIM);
            if (!token || is_number(token) == -1)
                int_err(line_counter);
            number = atoi(token);
            p_func = get_opcodes(command, line_counter);
            p_func(&topstack, line_counter);
        } else {
            p_func = get_opcodes(token, line_counter);
            p_func(&topstack, line_counter);
        }
        line_counter++;
    }
    fclose(fp);
    if (line)
        free(line);
    free_stack(topstack);
}
