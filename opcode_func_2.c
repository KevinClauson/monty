#include "monty.h"
/**
 * my_add - adds the numbers in the top to nodes and stores it in the 2nd node
 * and pops off the head node. thorws an error if less than 2 nodes.
 * @stack: pointer to doubly linkes list
 * @line_number: the line number of the operation send it to pop, but not used
 * Return: nothing.
 */
void my_add(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (data_g->stack_len < 2)
		error_handler(9);

	first = *stack;
	second = first->next;
	second->n += first->n;
	my_pop(stack, line_number);
}

/**
 * my_nop - does nothing, but just keeps going if run into this opcode
 * @stack: pointer to doubly linkes list, not used here.
 * @line_number: the line number of the operation not used
 * Return: nothing.
 */
void my_nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}
