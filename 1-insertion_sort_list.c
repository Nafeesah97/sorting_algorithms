#include "sort.h"

/**
 * swap_node - function to swap nodes
 * @list: The list of nodes
 * @node1: the first node
 * @node2: the second node
*/

void swap_node(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1 == NULL || node2 == NULL || node1 == node2)
		return;

	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * insertion_sort_list -  sorts a doubly linked list of integers
 * @list: list to be sorting
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *next_node, *current, *temp;

	if (list == NULL || *list == NULL)
	{
		print_list(*list);
		return;
	}

	current = *list;
	while (current != NULL)
	{
		next_node = current->next;
		if (current && current->next != NULL && current->n > next_node->n)
		{
			swap_node(list, current, next_node);
			if (next_node && next_node->prev == NULL)
				*list = next_node;
			print_list(*list);
			while (next_node && next_node->prev && next_node->n < next_node->prev->n)
			{
				temp = next_node->prev;
				swap_node(list, temp, next_node);
				if (next_node->prev == NULL)
				*list = next_node;
				print_list(*list);
			}
		}
		else
			current = current->next;
	}
}
