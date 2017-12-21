#include "monty.h"

/**
 * error_handler - handles all errors for the program
 * @error: an int that signifies the error that occured.
 * Return: nothing but exits with an exit_failure.
 */
void error_handler(int error)
{
	switch (error)
	{
	case 1:
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	case 2:
		printf("Error: Can't open file %s\n", data_g->file_name);
		exit(EXIT_FAILURE);
	case 3:
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	case 4:
		printf("L%d: unknown instruction %s\n", data_g->line_num, data_g->args[0]);
		exit(EXIT_FAILURE);
	case 5:
		printf("L%d: usage: push integer\n", data_g->line_num);
		exit(EXIT_FAILURE);
	case 6:
		printf("L%d: can't pint, stack empty\n", data_g->line_num);
		exit(EXIT_FAILURE);
	case 7:
		printf("L%d: can't pop an empty stack\n", data_g->line_num);
		exit(EXIT_FAILURE);
	case 8:
		printf("L%d: can't swap, stack too short\n", data_g->line_num);
		exit(EXIT_FAILURE);
	case 9:
		printf("L%d: can't add, stack too short\n", data_g->line_num);
		exit(EXIT_FAILURE);
	default:
		printf("Not sure why this failed, but please start over.\n");
		exit(EXIT_FAILURE);
	}
}