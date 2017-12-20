#include "monty.h"

data_t *data_g;

void error_handler(int error)
{
	switch(error)
	{
	case 1 :
		printf("USAGE: monty file\n");
		break;
	case 2 :
		printf("Error: Can't open file %s\n", data_g->file_name);
		break;
	case 3:
		printf("Error: malloc failed\n");
		break;
	case 4:
		printf("L%d: unknown instruction %s\n", data_g->line_num, data_g->argument_1);
		break;
	case 5:
		printf("L%d: usage: push integer\n", data_g->line_num);
		break;
	default:
		printf("Not sure why this failed, but please start over.\n");
	}
	free(data_g);
	exit(EXIT_FAILURE);
}

void my_pall(stack_t **stack, unsigned int line_number)
{
	printf("PALLLLLL\n");
	if (stack == NULL)
		printf("stack is NULL at %d\n", line_number);
}

void my_push(stack_t **stack, unsigned int line_number)
{
	printf("PUSHHHHH\n");
	if (stack == NULL)
		printf("stack is NULL at %d\n", line_number);
}

void execute_func(stack_t **stack)
{
	int i = 0;
	instruction_t find_func[] = {
		{"pall", my_pall},
		{"push", my_push},
		{NULL, NULL}
	};
	while (find_func[i].opcode != NULL)
	{
		if (strcmp(data_g->argument_1, find_func[i].opcode) == 0)
		{
			find_func[i].f(stack, data_g->line_num);
		}
		++i;
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
		error_handler(4);
	}
	else
	{
		data_g->argument_1 = NULL;
	}
}

char **parse_args(char *line)
{
	size_t i = 0, len = BUF_SIZE;
	char *token;
	char **args = malloc(len * sizeof(char *));
	/*if (args == NULL)
	  error_handler(3, );*/
	token = strtok(line, " $");
	while(token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " $");
	}
	args[i] = NULL;
	return (args);
}


void read_file(FILE *fp)
{
	ssize_t read;
	size_t len = 0;
	char *line = NULL, **args;
	stack_t **stack = NULL;
	while ((read = getline(&line, &len, fp)) != -1)
	{
		++data_g->line_num;
		args = parse_args(line);
		argument_check(args[0], args[1]);
		printf("arg 1: %s; arg 2: %d\n", data_g->argument_1, data_g->argument_2);
		execute_func(stack);
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
	data_g->file_name = argv[1];
	printf("test: %d\n", data_g->line_num);
	printf("file name: %s\n", data_g->file_name);
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		error_handler(2);
	read_file(fp);

	return (0);
}
