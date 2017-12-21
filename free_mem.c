#include "monty.h"

/**
 * free_stack - free linked list.
 * @stack: pointer to head of linked list.
 * Return: nothing.
 */
void free_stack(stack_t **stack)
{
	stack_t *temp, *current;

	current = *stack;
	while (current)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}

/**
 * free_data - free struc.
 * Return: nothing.
 */
void free_data(void)
{
	if (data_g != NULL)
	{
		if (data_g->fp != NULL)
			fclose(data_g->fp);
		if (data_g->stack != NULL)
			free_stack(&data_g->stack);
		if (data_g->args != NULL)
			free(data_g->args);
		if (data_g->line != NULL)
			free(data_g->line);
		free(data_g);
	}
}
