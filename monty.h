#ifndef _MONTY_H_
#define _MONTY_H_

/******* Libraries ********/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/****** Defintions ********/
#define BUF_SIZE 1024


/******* Structures *******/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data_s - caries data around to use in various functions
 * @file_name: the file name reading from
 * @line: the line that is read from the file
 * @args: tokenized string of arguments from line.
 * @line_num: current linee number
 * @argument_1: the first argument to read
 * @argument_2: the second argument to read
 * @stack: pointer to doubly linked list
 * @stack_len: counter of how many nodes in linked list
 * @fp: the pointer to the open file.
 * @line_len: length of line read;
 */
typedef struct data_s
{
	char *file_name;
	char *line;
	char **args;
	int line_num;
	char *argument_1;
	int argument_2;
	stack_t *stack;
	int stack_len;
	int line_len;
	FILE *fp;
} data_t;

/********* External Variables **********/

extern data_t *data_g;
data_t *data_g;

/******  Functions ********/
void error_handler(int error);
void error_handler_2(int error);

int check_if_int(char *arg_2);
char **parse_args(char *line);
void read_file(FILE *fp);

void free_stack(stack_t **stack);
void free_data(void);

void my_push(stack_t **stack, unsigned int line_number);
void my_pall(stack_t **stack, unsigned int line_number);
void my_pint(stack_t **stack, unsigned int line_number);
void my_pop(stack_t **stack, unsigned int line_number);
void my_swap(stack_t **stack, unsigned int line_number);
void my_add(stack_t **stack, unsigned int line_number);
void my_nop(stack_t **stack, unsigned int line_number);
void my_sub(stack_t **stack, unsigned int line_number);
void my_div(stack_t **stack, unsigned int line_number);
void my_mul(stack_t **stack, unsigned int line_number);
void my_mod(stack_t **stack, unsigned int line_number);
void my_pchar(stack_t **stack, unsigned int line_number);
void my_pstr(stack_t **stack, unsigned int line_number);
void my_rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

#endif
