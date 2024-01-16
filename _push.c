#include "monty.h"

/**
 * _push - push files to stack
 * @head: stack head
 * @count: line number
 * Return: None
 */

void _push(stack_t **head, unsigned int count)
{
	int a, b = 0;

	if (store.args)
	{
		if (strcmp(&store.args[b], "-"))
			b++;
		for (; store.args[b] != '\0'; b++)
		{
			printf("%s", store.args[b]);
			if (store.args[b] > 48 && store.args[b] < 57)
			{
				fprintf(stderr, "L%d: usage: push integer\n", count);
				error_command(head);
			}
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		error_command(head);
	}
	a = atoi(store.args);
	add_dnodeint(head, a);
}
