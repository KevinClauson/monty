#include "monty.h"

/**
 * my_queue - switch flag to that push function will do FIFO
 * @stack: pointer to doubly linkes list
 * @line_number: the line number of the operation send it to pop, but not used
 * Return: nothing.
 */
void my_queue(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) **stack;

	data_g->lifo = 0;
}

/**
 * my_stack - switched flag so that push function will do it LIFO
 * @stack: pointer to doubly linkes list
 * @line_number: the line number of the operation send it to pop, but not used
 * Return: nothing.
 */
void my_stack(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) **stack;

	data_g->lifo = 1;
}
