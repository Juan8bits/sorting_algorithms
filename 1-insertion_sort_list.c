#include "sort.h"

/**
 * swap_nds - Swap two nodes in a double linked list.
 * @list: Pointer to double linked list head
 * @n1: Pointer to first node.
 * @n2: Pointer to second node.
 */
void swap_nds(listint_t **list, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*list = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: Pointer to double linked list head
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *prev = NULL, *tmp = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	for (node = (*list)->next; node; node = tmp)
	{
		tmp = node->next;
		prev = node->prev;
		while (prev && node->n < prev->n)
		{
			swap_nds(list, &prev, node);
			print_list((const listint_t *)*list);
		}
	}
}
