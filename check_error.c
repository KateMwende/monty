#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <monty.h>
/**
 *check_errors - function that checks for errors
 *@argc: integer
 *@argv: pointer
 *return: 0
 */
void check_errors(int argc, char *argv)
{

	FILE *fp = fopen(argv[1], "r");

	stack_t *stack = NULL;

	char *line = NULL;
	size_t len = 0;

	while (getline(&line, &len, fp) != -1)
	{
		line_number++;
		char *instr = strtok(line, " \n\t");

		if (strcmp(instr, "op_push") == 0)
			op_push(&stack, line_number);
		else if (strcmp(instr, "op_pall") == 0)
			op_pall(&stack, line_number);
		else
		{
			dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", line_number, instr);
			exit(EXIT_FAILURE);
		}
	}
}
