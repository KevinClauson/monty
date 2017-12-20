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
 * struct data - caries data around to use in various functions
 * @file_name: the file name reading from
 * @line_num: current linee number
 */
typedef struct data_s
{
	char *file_name;
	int line_num;
	char *argument_1;
	int argument_2;
} data_t;

/********* External Variables **********/

extern data_t *data_info_g;

#endif
