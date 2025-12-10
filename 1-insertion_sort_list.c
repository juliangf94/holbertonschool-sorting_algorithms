#include "sort.h"

/**
* insertion_sort_list - sorts a doubly linked list
* in ascending order via insertion sort
* @list: - pointer to pointer to list of elements to sort
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *insert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next = current->next;
		insert = current->prev;

		while (insert != NULL && insert->n > current->n)
		{
			insert->next = current->next;
			if (current->next != NULL)
				current->next->prev = insert;

			current->prev = insert->prev;
			current->next = insert;

			if (insert->prev != NULL)
				insert->prev->next = current;
			else
				*list = current;

			insert->prev = current;

			print_list(*list);

			insert = current->prev;
		}
		current = next;
	}
}
