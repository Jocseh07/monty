#include "monty.h"

/**
 * _push - push files to stack
 * @head: stack head
 * @count: line number
 * Return: None
 */

void _push(stack_t **head, unsigned int count)
{
	int a = 0, b = 0, is_number = 1;

	if (store.args)
	{

		for (; store.args[b] != '\0'; b++)
		{
			if (isdigit(store.args[b]) == 0)
				is_number = 0;
		}
		if (is_number == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			error_command(head);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		error_command(head);
	}
	a = atoi(store.args);
	if (store.change == 0)
		add_dnodeint(head, a);
	else
		add_dnodeint_end(head, a);
}
