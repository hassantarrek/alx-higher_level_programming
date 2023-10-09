#include "lists.h"

listint_t *reverse_listint(listint_t **head);

/**
 * reverse_listint - Reverses a singly-linked listint_t
 * @head: pointer
 * Return: pointer
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *node = *head, *next, *prev = NULL;

	while (node)
	{
		next = node->next;
		node->next = prev;
		prev = node;
		node = next;
	}

	*head = prev;
	return (*head);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: pointer
 * Return: 0 or 1
 */

int is_palindrome(listint_t **head)
{
	listint_t *tmp, *rev, *mid;
	size_t size = 0, x;

	if (*head == NULL || (*head)->next == NULL)
	{
		return (1);
	}
	tmp = *head;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	tmp = *head;
	for (x = 0; x < (size / 2) - 1; x++)
	{
		tmp = tmp->next;
	}
	if ((size % 2) == 0 && tmp->n != tmp->next->n)
	{
		return (0);
	}
	tmp = tmp->next->next;
	rev = reverse_listint(&tmp);
	mid = rev;
	tmp = *head;
	while (rev)
	{
		if (tmp->n != rev->n)
		{
			return (0);
		}
		tmp = tmp->next;
		rev = rev->next;
	}
	reverse_listint(&mid);

	return (1);
}
