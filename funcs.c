#include "monty.h"

/**
 * free_dlistint - frees a stack_t list
 * @head: pointer to head
 * Return: None
 */

void free_dlistint(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * print_dlistint - prints all emenents of list
 * @h: head of list
 * Return: number of nodes
 */

void print_dlistint(stack_t *h)
{
	if (h == NULL)
		return;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * add_dnodeint - adds new node at begining of stack_t list
 * @head: pointer to head
 * @n: value of head
 * Return: address of new element or NULL if failed
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;
	stack_t *temp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	temp = *head;
	if (temp != NULL)
	{
		while (temp->prev != NULL)
			temp = temp->prev;
	}
	new->next = temp;
	if (temp != NULL)
		temp->prev = new;
	*head = new;
	return (new);
}

/**
 * add_dnodeint_end - adds a new node at the end of a list
 * @head: head of the list
 * @n: element to add
 * Return: address of new element or NULL
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new;
	stack_t *temp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	temp = *head;
	new->n = n;
	new->next = NULL;
	if (temp != NULL)
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	else
		*head = new;
	new->prev = temp;
	return (new);
}

/**
 * delete_dnodeint_at_index - delete node at index
 * @head: head of linkedl ist
 * @index: index to delete the node
 * Return: 1 ifsucceeded of -1 if failed
 */

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	unsigned int a = 0;
	stack_t *temp;

	temp = *head;
	if (temp == NULL)
		return (-1);

	while (temp->prev != NULL)
		temp = temp->prev;
	while (temp != NULL)
	{
		if (a == index)
			break;
		a++;
		temp = temp->next;
	}
	if (a < index)
		return (-1);
	if (a == 0)
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
	}
	else
	{
		temp->prev->next = temp->next;
		if (temp->next != NULL)
			temp->next->prev = temp->prev;
	}
	free(temp);

	return (1);
}
