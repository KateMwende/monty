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
	int value;
	stack_t *new_node;

	if (glo.node_data == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = glo.node_data;
	if (value == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node = (stack_t *) malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
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

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}

	(void)line_number;
}

/**
 * op_pint - function that prints the value at the top of the stack
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 *
 * Return: nothing
 */

void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (current)
	{
		printf("%d\n", current->n);
	}
	else
	{
		pint_error(line_number);
	}
}

/**
 * op_pop - function that removes the top element of the stack
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 *
 * Return: nothing
 */

void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *tmp;

	if (!current)
		pop_error(stack, line_number);

	tmp = current->next;
	free(current);
	*stack = tmp;
	current = *stack;
	if (current)
	{
		current->prev = NULL;
	}
}

/**
 * op_add - adds the first two nodes together
 * @stack: a pointer to the head of a linked list
 * @line_number: the line number
 * Return: nothing
 */

void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *second_node;

	if (!current || !current->next)
		add_error(line_number);

	second_node = current->next;
	second_node->n = second_node->n + current->n;
	op_pop(stack, line_number);
}
