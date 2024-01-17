#include "monty.h"

/**
 * _rotl - rotate left
 * @head: stack head
 * @count: line number
 * Return: None
 */

void _rotl(stack_t **head, unsigned int count)
{
	stack_t *temp;
	stack_t *temp2;
	int a = 0;
	(void)count;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		a++;
	}
	if (a < 2)
	{
		fprintf(stderr, "L%d: can't rotl, stack too short\n", count);
		error_command(head);
	}

	temp = *head;
	if (temp == NULL && temp->next == NULL)
		return;

	temp2 = (*head)->next;
	temp2->prev = NULL;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *head;
	(*head)->prev = temp;
	(*head)->next = NULL;
	*head = temp2;
}
