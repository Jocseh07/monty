#include "monty.h"

/**
 * _pint - prints the top of stack
 * @head: stack head
 * @count: line number
 * Return: None
 */

void _pint(stack_t **head, __attribute__((unused)) unsigned int count)
{

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", count);
		error_command(head);
	}

	printf("%d\n", (*head)->n);
}
