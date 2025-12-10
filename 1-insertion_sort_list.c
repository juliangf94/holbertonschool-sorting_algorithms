#include "sort.h"

/**
* insertion_sort_list - sorts a doubly linked list
* in ascending order via insertion sort
* @list: - pointer to pointer to list of elements to sort
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next = current->next;

		while (current->prev != NULL && insert->n > current->n)
		{
			prev = current->prev;

			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;

			current->prev = prev->prev;
			current->next = prev;

			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;

			prev->prev = current;

			print_list(*list);

		}
		current = next;
	}
}
