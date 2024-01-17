#include "monty.h"

/**
 * handle_execute - handle executing of commands in line
 * @stack: pointer to stack head
 * @count: count commands ran
 * Return: 1 or 0
 */

int handle_execute(stack_t **stack, unsigned int count)
{
	instruction_t commands[] = {
			{"push", _push}, {"pall", _pall}, {"pint", _pint},
			 {"pop", _pop}, {"swap", _swap}, {"add", _add}, {"sub", _sub},
			  {"div", _div}, {"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
				 {"pstr", _pstr}, {"rotl", _rotl}, {"rotr", _rotr},
				  {"queue", _queue}, {"stack", _stack}, {"nop", _nop}, {NULL, NULL}};
	unsigned int a = 0;
	char *command;

	command = strtok(store.content, " \n\t");
	if (command && command[0] == '#')
		return (0);
	store.args = strtok(NULL, "\n\t ");
	while (commands[a].opcode && command)
	{
		if (strcmp(command, commands[a].opcode) == 0)
		{
			commands[a].f(stack, count);
			return (0);
		}
		a++;
	}
	if (command && commands[a].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, command);
		error_command(stack);
	}
	return (1);
}
