#include "monty.h"

/**
 * _rotl - rotate left		h = h->next;
		len++;
 * @head: stack head
 * @count: line number
 * Return: None
 */

void _rotl(stack_t **head, unsigned int count)
{
	stack_t *temp;
	stack_t *temp2;
	(void)count;

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
