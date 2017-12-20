#include "monty.h"

/*data_t *data_info_g;*/

void error_handler(int error, char **argv)
{
	switch(error)
	{
	case 1 :
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	case 2 :
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	case 3:
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	default:
		printf("Not sure why this failed, but please start over.\n");
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
	token = strtok(line, " ");
	while(token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
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
	int line_num = 0;
	while ((read = getline(&line, &len, fp)) != -1)
	{
		++line_num;
		printf("%d, %s", line_num, line);
		args = parse_args(line);
		i = 0;
		while (args[i])
		{
			printf("args[%d]: %s\n", i, args[i]);
			++i;
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
		error_handler(1, argv);

	/*data_info_g->line_num = 3;*/

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		error_handler(2, argv);
	read_file(fp);

	return (0);
}
