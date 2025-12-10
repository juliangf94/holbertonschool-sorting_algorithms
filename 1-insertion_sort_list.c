#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using insertion sort
 * @list: pointer to pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next = current->next;

		while (current->prev != NULL && current->prev->n > current->n)
		{
			prev = current->prev;

			/* detach current */
			prev->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev;

			/* move current before prev */
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
