#include "monty.h"
store_t store = {NULL, NULL, NULL, 0};

/**
 * main - main function of the program
 * @ac: no of arguments
 * @av: opcode file
 * Return: 0
 */

int main(int ac, char **av)
{
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		error_exit(&stack);
	}
	handle_file(av[1], &stack);
	return (0);
}
