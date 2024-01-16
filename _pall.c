#include "monty.h"

/**
 * _pall - prints the stack
 * @head: stack head
 * @count: line number
 * Return: None
 */

void _pall(stack_t **head, unsigned int count)
{
	(void)count;

	print_dlistint(*head);
}
