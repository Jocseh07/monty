#include "monty.h"

/**
 * _pstr - prints string from ascii number
 * @head: stack head
 * @count: line number
 * Return: None
 */

void _pstr(stack_t **head, unsigned int count)
{
	stack_t *temp;
	(void)count;

	temp = *head;
	while (temp)
	{
		if ((temp)->n > 127 || (temp)->n <= 0)
			break;
		printf("%c", (temp)->n);
		temp = temp->next;
	}
	printf("\n");
}
