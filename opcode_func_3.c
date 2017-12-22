#include "monty.h"

/**
 * my_div - divides the number in the top two nodes and stores it in the 2nd
 * and pops off the head node. thorws an error if less than 2 nodes.
 * also throws error if divide by 0
 * @stack: pointer to doubly linkes list
 * @line_number: the line number of the operation send it to pop, but not used
 * Return: nothing.
 */
void my_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (data_g->stack_len < 2)
		error_handler_2(5);
	first = *stack;
	second = first->next;
	if (first->n == 0)
		error_handler_2(3);
	second->n %= first->n;
	my_pop(stack, line_number);
}

/**
 * my_pchar - prints out the ascii value of the number at head of stack
 * if out side of ascii range throw an error.
 * @stack: pointer to doubly linkes list
 * @line_number: the line number of the operation send it to pop, but not used
 * Return: nothing.
 */
void my_pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *first;

	(void) line_number;

	if (data_g->stack_len < 1)
		error_handler_2(7);
	first = *stack;
	if (first->n < 33 || first->n >= 127)
		error_handler_2(6);
	printf("%c\n", first->n);
}
