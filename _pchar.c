#include "monty.h"

/**
 * _pchar - prints char in ascii
 * @head: stack head
 * @count: line number
 * Return: None
 */

void _pchar(stack_t **head, unsigned int count)
{
	stack_t *temp;
	(void)count;

	temp = *head;
	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		error_command(head);
	}
	if (temp->n > 127 || temp->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		error_command(head);
	}

	printf("%c\n", temp->n);
}
