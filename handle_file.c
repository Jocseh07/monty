#include "monty.h"

/**
 * handle_file - reads bytcode from file and run file
 * @filename: pathname to file
 * @stack: pointer to top of stack
 * Return: 0
 */

int handle_file(char *filename, stack_t *stack)
{
	ssize_t line = 1;
	size_t size = 0;
	unsigned int count = 0;

	store.file = fopen(filename, "r");
	if (!store.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		error_exit(&stack);
	}
	while (line > 0)
	{
		store.content = NULL;
		line = getline(&store.content, &size, store.file);
		count++;

		if (line > 0)
			handle_execute(&stack, count);
		free(store.content);
	}
	free_dlistint(stack);
	fclose(store.file);
	return (0);
}
