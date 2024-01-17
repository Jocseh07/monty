#include "monty.h"

/**
 * _pall - prints the stack
 * @head: stack head
 * @count: line number
 * Return: None
 */

void _pall(stack_t **head, unsigned int count)
{
	stack_t *temp;
	(void)count;

	temp = *head;
	if (temp == NULL)
		return;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
