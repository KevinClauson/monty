#include "monty.h"

data_t *data_g;

void error_handler(int error)
{
	switch(error)
	{
	case 1 :
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	case 2 :
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

void my_nop(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) stack;
}
void execute_func(stack_t **stack)
{
	int i = 0;

	instruction_t find_func[] = {
		{"pall", my_pall},
		{"push", my_push},
		{"pint", my_pint},
		{"pop", my_pop},
		{"swap", my_swap},
		{"add", my_add},
		{"nop", my_nop},
		{NULL, NULL}
	};
	while (find_func[i].opcode != NULL)
	{
		if (strcmp(data_g->args[0], find_func[i].opcode) == 0)
		{
			find_func[i].f(stack, data_g->line_num);
			break;
		}
		++i;
	}

	if (find_func[i].opcode == NULL)
	{
		error_handler(4);
	}
}

int check_if_int(char *arg_2)
{
	int i;

	i = 0;
	while (arg_2[i])
	{
		if (arg_2[i] < '0' || arg_2[i] > '9')
			return (0);
		++i;
	}
	return (1);
}
/*
void argument_check(char *arg_1, char *arg_2)
{
	if (strcmp(arg_1, "push") == 0)
	{
		data_g->argument_1 = arg_1;
		if (arg_2 == NULL || check_if_int(arg_2) == 0)
			error_handler(5);
		data_g->argument_2 = atoi(arg_2);
	}
	else if (strcmp(arg_1, "pall") == 0)
	{
		data_g->argument_1 = arg_1;
	}
	else if (arg_1 != NULL)
	{
		data_g->argument_1 = arg_1;
		printf("NOOOO\n");
		error_handler(4);
	}
	else
	{
		data_g->argument_1 = NULL;
	}
}
*/
char **parse_args(char *line)
{
	size_t i = 0, len = BUF_SIZE;
	char *token;
	/*char *delim = "$ ";*/

	char **args = malloc(len * sizeof(char *));
	if (args == NULL)
		error_handler(3);
	token = strtok(line, " $\n");
	while(token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " $\n");
	}
	args[i] = NULL;
	return (args);
}

void read_file(FILE *fp)
{
	ssize_t read;
	size_t len = 0;
	data_g->line = NULL;
	data_g->args = NULL;
	data_g->stack = NULL;
	while ((read = getline(&data_g->line, &len, fp)) != -1)
	{
		++data_g->line_num;
		data_g->args = parse_args(data_g->line);
		/*argument_check(data_g->args[0], data_g->args[1]);*/
		if (data_g->args[0] != NULL)
			execute_func(&data_g->stack);

		free(data_g->args);
	}
	fclose(fp);
	exit(EXIT_SUCCESS);
}

/**
 * main - main function that controls the whole monty program
 * @argc: argument count
 * @argument: array of arguments
 * Return: always 0
 */

int main(int argc, char **argv)
{
	FILE *fp;

	if (argc != 2)
		error_handler(1);
	data_g = malloc(sizeof(data_t));
	data_g->line_num = 0;
	data_g->stack_len = 0;
	data_g->file_name = argv[1];
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		error_handler(2);
	read_file(fp);

	return (0);
}
