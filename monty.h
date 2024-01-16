#ifndef _MONTY_H
#define _MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>

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

/**
 * struct store_s - store args, files, linecontent
 * @arg: value stored
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
	int *change;
} store_t;
extern store_t store;

void free_dlistint(stack_t *head);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
void error_exit(stack_t **stack);
void error_command(stack_t **stack);
void _push(stack_t **head, unsigned int count);
int handle_execute(stack_t *stack, unsigned int count);
int handle_file(char *filename, stack_t **stack);
int main(int ac, char **av);
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
void print_dlistint(stack_t *h);
void _pall(stack_t **head, unsigned int count);

#endif
