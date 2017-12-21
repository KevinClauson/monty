#include "monty.h"

/**
 * execute_func - goes through list of functions to see if available.
 * @stack: argument count
 * Return: nothing.
 */
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

/**
 * check_if_int - for push it checks if 2nd arg is a number
 * @arg_2: 2nd argument from tokenized string.
 * Return: a 0 if there are chars that are not digits and a 1 if is digit
 */
int check_if_int(char *arg_2)
{
	int i;

	for (i = 0; arg_2[i]; ++i)
	{
		if (i == 0 && arg_2[0] == '-' && arg_2[i + 1] >= 1 && arg_2[i + 1] <= '9')
		{
			continue;
		}
		else if (arg_2[i] < '0' || arg_2[i] > '9')
		{
			return (0);
		}
	}
	return (1);
}

/**
 * parse_args - tokenizes the line into separate arguments
 * @line: a string from the file reading from
 * Return: a double pointer to an array of strings.
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
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " $\n");
	}
	args[i] = NULL;
	return (args);
}

/**
 * read_file - reads line by line from monty m files
 * @fp: pointer to the open file.
 * Return: no return just exit on success.
 */
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
		if (data_g->line == NULL)
			error_handler(3);
		data_g->args = parse_args(data_g->line);
		if (data_g->args[0] != NULL)
			execute_func(&data_g->stack);

		free(data_g->args);
		free(data_g->line);
		data_g->line = NULL;
		data_g->args = NULL;
	}
	free_stack(&data_g->stack);
	free_data();
	fclose(fp);
	exit(EXIT_SUCCESS);
}

/**
 * main - main function that controls the whole monty program
 * @argc: argument count
 * @argv: array of arguments
 * Return: always 0
 */

int main(int argc, char **argv)
{
	FILE *fp;

	if (argc != 2)
		error_handler(1);
	data_g = malloc(sizeof(data_t));
	if (data_g == NULL)
		error_handler(3);
	data_g->line_num = 0;
	data_g->stack_len = 0;
	data_g->file_name = argv[1];
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		error_handler(2);
	data_g->fp = fp;
	read_file(fp);

	return (0);
}
