#include "monty.h"

/**
 * my_push - creates a node and puts in on the stack
 * @stack: pointer to the head of the doubley linked list or to Null if empty
 * @line_number: not used in this function.
 * Return: nothing.
 */
void my_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void) line_number;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		error_handler(3);
	if (check_if_int(data_g->args[1]) == 0)
		error_handler(5);
	data_g->argument_2 = atoi(data_g->args[1]);
	new->n = data_g->argument_2;
	if (stack == NULL)
		new->next = NULL;
	else
		new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	data_g->stack = new;
	++data_g->stack_len;
}

/**
 * my_pall - prints the whole list or throws an error if empty.
 * @stack: pointer to the head of the doubley linked list or to Null if empty
 * @line_number: not used in this function.
 * Return: nothing.
 */
void my_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;
	current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * my_pint - prints the head of the list or throws an error if head is null.
 * @stack: pointer to the head of the doubley linked list or to Null if empty
 * @line_number: not used in this function.
 * Return: nothing.
 */
void my_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;
	current = *stack;
	if (current)
		printf("%d\n", current->n);
	else
		error_handler(6);
}

/**
 * my_pop - pops the head of the node off the list if exists else error.
 * @stack: pointer to the head of the doubley linked list or to Null if empty
 * @line_number: not used in this function.
 * Return: nothing.
 */
void my_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;
	current = *stack;

	if (current)
	{
		data_g->stack = current->next;
		if (current->next)
			current->next->prev = NULL;
		free(current);
		--data_g->stack_len;
	}
	else
		error_handler(7);
}
/**
 * my_swap - swaps the head of list with the one after it if 2 or more nodes
 * @stack: pointer to the head of the doubley linked list or to Null if empty
 * @line_number: not used in this function.
 * Return: nothing.
 */
void my_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	(void) line_number;
	if (data_g->stack_len < 2)
		error_handler(8);

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	data_g->stack = second;
	if (first->next)
		first->next->prev = first;
}
