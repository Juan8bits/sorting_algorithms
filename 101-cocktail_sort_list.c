#include "sort.h"

/**
 * swap_nds - Swap two nodes in a double linked list.
 * @list: Pointer to double linked list head
 * @n1: Pointer to first node.
 * @n2: Pointer to second node.
 */
void swap_nds(listint_t **list, listint_t *n1, listint_t *n2)
{
	if (!(n1->prev))
	{
		n1->next = n2->next;
		if (n2->next)
			n2->next->prev = n1;
		n2->next = n1;
		n2->prev = NULL;
		n1->prev = n2;
		*list = n2;
	}
	else
	{
		n2->prev->next = n2->next;
		if (n2->next)
			n2->next->prev = n2->prev;
		n1->prev->next = n2;
		n2->prev = n1->prev;
		n1->prev = n2;
		n2->next = n1;
	}
}

/**
 * cocktail_sort_list - Sort a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm.
 * @list: Pointer to double linked list head
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node = NULL, *next = NULL, *prev = NULL;
	int end; /* Boolean 1 -> false, 0 -> true */

	if (!list || !(*list) || !(*list)->next)
		return;

	node = *list;
	do {
		end = 0;
		while (node->next)
		{
			next = node->next;
			if (next && node->n > next->n)
			{
				swap_nds(list, node, next);
				end = 1;
				print_list((const listint_t *)*list);
			}
			else
				node = node->next;
		}
		node = node->prev;
		while (node->prev)
		{
			prev = node->prev;
			if (prev && node->n < prev->n)
			{
				swap_nds(list, prev, node);
				end = 1;
				print_list((const listint_t *)*list);
			}
			else
				node = node->prev;
		}
		node = node->next;
	} while (end);
}
