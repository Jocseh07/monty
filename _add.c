#include "monty.h"

/**
 * _add - add top 2 of stack
 * @head: stack head
 * @count: line number
 * Return: None
 */

void _add(stack_t **head, unsigned int count)
{
	stack_t *temp;
	int a = 0, b = 0;
	(void)count;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		a++;
	}

	if (a < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		error_command(head);
	}
	temp = *head;
	b = temp->n + temp->next->n;
	temp->next->n = b;
	*head = temp->next;
	temp->next->prev = NULL;
	free(temp);
}
