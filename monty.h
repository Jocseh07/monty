#ifndef _MONTY_H
#define _MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct store_s - store args, files, linecontent
 * @args: value stored
 * @file: pointer to file
 * @content: content of the file
 * @change: for either stack or queue
 * Description: store values
 */

typedef struct store_s
{
	char *args;
	FILE *file;
	char *content;
	int change;
} store_t;
extern store_t store;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void free_dlistint(stack_t *head);
void *add_dnodeint(stack_t **head, int n);
void *add_dnodeint_end(stack_t **head, int n);
void delete_dnodeint_at_index(stack_t **head, unsigned int index);
void error_exit(stack_t **stack);
void error_command(stack_t **stack);
int main(int ac, char **av);
int handle_file(char *filename, stack_t *stack);
int handle_execute(stack_t **stack, unsigned int count);
void _push(stack_t **head, unsigned int count);
void _pall(stack_t **head, unsigned int count);
void _pint(stack_t **head, unsigned int count);
void _pop(stack_t **head, unsigned int count);
void _swap(stack_t **head, unsigned int count);
void _add(stack_t **head, unsigned int count);
void _nop(stack_t **head, unsigned int count);
void _sub(stack_t **head, unsigned int count);
void _div(stack_t **head, unsigned int count);
void _mul(stack_t **head, unsigned int count);
void _mod(stack_t **head, unsigned int count);
void _pchar(stack_t **head, unsigned int count);
void _pstr(stack_t **head, unsigned int count);
void _rotl(stack_t **head, unsigned int count);
void _rotr(stack_t **head, unsigned int count);
void _queue(stack_t **head, unsigned int count);
void _stack(stack_t **head, unsigned int count);

#endif
