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
		free(data_g);
		exit(EXIT_FAILURE);
	case 3:
		printf("Error: malloc failed\n");
		break;
	case 4:
		printf("L%d: unknown instruction %s\n", data_g->line_num, data_g->args[0]);
		break;
	case 5:
		printf("L%d: usage: push integer\n", data_g->line_num);
		break;
	case 6:
		printf("L%d: can't pint, stack empty\n", data_g->line_num);
		break;
	case 7:
		printf("L%d: can't pop an empty stack\n", data_g->line_num);
		break;
	case 8:
		printf("L%d: can't swap, stack too short\n", data_g->line_num);
		break;
	case 9:
		printf("L%d: can't add, stack too short\n", data_g->line_num);
		break;
	default:
		printf("Not sure why this failed, but please start over.\n");
		exit(EXIT_FAILURE);
	}
	if (data_g != NULL)
	{
		free_data();
	}
	exit(EXIT_FAILURE);
}


/**
 * error_handler_2 - handles all errors for the program
 * @error: an int that signifies the error that occured.
 * Return: nothing but exits with an exit_failure.
 */

void error_handler_2(int error)
{
	switch (error)
	{
	case 1:
		printf("L%d: can't sub, stack too short\n", data_g->line_num);
		break;
	case 2:
		printf("L%d: can't div, stack too short\n", data_g->line_num);
		break;
	case 3:
		printf("L%d: division by zero\n", data_g->line_num);
		break;
	case 4:
		printf("L%d: can't mul, stack too short\n", data_g->line_num);
		break;
	case 5:
		printf("L%d: can't mod, stack too short\n", data_g->line_num);
		break;
	case 6:
		printf("L%d: can't pchar, value out of range\n", data_g->line_num);
		break;
	case 7:
		printf("L%d: can't pchar, stack empty\n", data_g->line_num);
		break;
	case 8:
		printf("L%d: can't swap, stack too short\n", data_g->line_num);
		break;
	case 9:
		printf("L%d: can't add, stack too short\n", data_g->line_num);
		break;
	default:
		printf("Not sure why this failed, but please start over.\n");
		exit(EXIT_FAILURE);
	}
	if (data_g != NULL)
	{
		free_data();
	}
	exit(EXIT_FAILURE);
}
