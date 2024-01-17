#include "monty.h"

/**
 * _pstr - prints the top of stack
 * @head: stack head
 * @count: line number
 * Return: None
 */

void _pstr(stack_t **head, __attribute__((unused)) unsigned int count)
{
	stack_t *temp;

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
