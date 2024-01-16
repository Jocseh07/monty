#include "monty.h"

/**
 * error_exit - exits and free list
 * @stack: pointer to head of stack
 * Return: None
 */

void error_exit(stack_t **stack)
{
	if (*stack)
		free_dlistint(*stack);
	exit(EXIT_FAILURE);
}
