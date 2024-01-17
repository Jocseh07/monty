#include "monty.h"

/**
 * _pchar - prints the top of stack
 * @head: stack head
 * @count: line number
 * Return: None
 */

void _pchar(stack_t **head, __attribute__((unused)) unsigned int count)
{

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		error_command(head);
	}
	if ((*head)->n > 127 || (*head)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		error_command(head);
	}

	printf("%c\n", (*head)->n);
}
