#include "monty.h"

/**
 * handle_file - reads bytcode from file and run file
 * @filename: pathname to file
 * @stack: pointer to top of stack
 * Return: 0
 */

int handle_file(char *filename, stack_t **stack)
{
	ssize_t line = 0;
	char *content;
	char c;
	unsigned int count = 0;
	FILE *file;

	file = fopen(filename, "r");
	store.file = file;
	if (!store.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		error_exit(stack);
	}
	while (line >= 0)
	{
		content = NULL;
		while (fread(&c, sizeof(char), 1, file))
		{
			printf("%c", c);
			content = &c;
			content++;
		}
		store.content = content;
		count++;
		if (line > 0)
			handle_execute(*stack, count);
		free(store.content);
	}
	free_dlistint(*stack);
	fclose(store.file);
	return (0);
}
