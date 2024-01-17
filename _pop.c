#include "monty.h"

/**
 * _pop - pops the top of stack
 * @head: stack head
 * @count: line number
 * Return: None
 */

void _pop(stack_t **head, unsigned int count)
{
	stack_t *temp;
	(void)count;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		error_command(head);
	}
	temp = *head;
	*head = temp->next;
	free(temp);
}
