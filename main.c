#include "monty.h"

data_t *data_info_g;

void error_handler(int error)
{
	switch(error)
	{
	case 1 :
		printf("USAGE: monty file\n");
		free(data_info_g);
		exit(EXIT_FAILURE);
	case 2 :
		printf("Error: Can't open file %s\n", data_info_g->file_name);
		free(data_info_g);
		exit(EXIT_FAILURE);
	case 3:
		printf("Error: malloc failed\n");
		free(data_info_g);
		exit(EXIT_FAILURE);
	default:
		printf("Not sure why this failed, but please start over.\n");
		free(data_info_g);
		exit(EXIT_FAILURE);
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
	int i;
	char *line = NULL, **args;

	while ((read = getline(&line, &len, fp)) != -1)
	{
		++data_info_g->line_num;
		printf("%d, %s", data_info_g->line_num, line);
		args = parse_args(line);
		i = 0;
		while (args[i])
		{
			printf("args[%d]: %s\n", i, args[i]);
			++i;
		}
		data_info_g->argument_1 = args[0];
		if (strcmp(data_info_g->argument_1, "push") == 0)
		{
			printf("YEA its a push with argument: %d\n", atoi(args[1]));
		}

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
	data_info_g = malloc(sizeof(data_t));
	data_info_g->line_num = 0;
	data_info_g->file_name = argv[1];
	printf("test: %d\n", data_info_g->line_num);
	printf("file name: %s\n", data_info_g->file_name);
	fp = fopen(argv[1], "r");
	if (fp == NULL)
		error_handler(2);
	read_file(fp);

	return (0);
}
