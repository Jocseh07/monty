#include "monty.h"

/**
 * _swap - swap top of stack
 * @head: stack head
 * @count: line number
 * Return: None
 */

void _swap(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *temp;
	int a = 0, b = 0;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		a++;
	}

	if (a < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", count);
		error_command(head);
	}
	temp = *head;
	b = temp->n;
	temp->n = temp->next->n;
	temp->next->n = b;
}
