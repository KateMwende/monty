#include "monty.h"

/**
 * op_push - function that push an element to the stack
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 *
 * Return: nothing
 */

void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *val = strtok(glo.line_buff, " \n\t");

	val = strtok(NULL, " \n\t");

	if (val == NULL || !atoi(val))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	glo.node_data = atoi(val);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_buff();
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = glo.node_data;
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*stack)
	{
		new_node->next = *stack;

		(*stack)->prev = new_node;
	}
	*stack = new_node;

}

/**
 * op_pall - function that prints out all the elements of a linked list
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 *
 * Return: nothing
 */

void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
