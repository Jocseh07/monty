#include "monty.h"

/**
 * _rotl - add top 2 of stack
 * @head: stack head
 * @count: line number
 * Return: None
 */

void _rotl(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *temp;
	stack_t *temp2;

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
