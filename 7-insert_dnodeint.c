#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h : pointer to the first node
 * @idx : index of the list for insertion starting from 0
 * @n : value of element n
 *
 * Return: address of the new node
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new = NULL, *head = *h;
	unsigned int i;

	if (idx == 0)
		new = add_dnodeint(h, n);
	else
	{
		i = 1;
		if (head != NULL)
			while (head->prev != NULL)
				head = head->prev;

		while (head != NULL)
		{
			if (i == idx)
			{
				if (head->next == NULL)
					new = add_dnodeint_end(h, n);
				else
				{
					new = malloc(sizeof(dlistint_t));
					if (new != NULL)
					{
						new->n = n;
						new->next = head->next;
						new->prev = head;
						head->next->prev = new;
						head->next = new;
					}
				}
				break;
			}
			head = head->next;
			i++;
		}
	}
	return (new);
}
