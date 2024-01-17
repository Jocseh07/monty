#include "monty.h"

/**
 * _rotr - add top 2 of stack
 * @head: stack head
 * @count: line number
 * Return: None
 */

void _rotr(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *temp;
	stack_t *temp2;

	temp = *head;
	if (temp == NULL && temp->next == NULL)
		return;

	while (temp->next != NULL)
		temp = temp->next;

	temp2 = (*head);
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = temp2;
	temp2->prev = temp;
	*head = temp;
}
