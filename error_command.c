#include "monty.h"

/**
 * error_command - handle commands with errors
 * @stack: pointer to head of stack
 */

void error_command(stack_t **stack)
{
	fclose(store.file);
	free(store.content);
	error_exit(stack);
}
