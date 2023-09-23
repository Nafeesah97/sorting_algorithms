#include "sort.h"

/**
 * insertion_sort_list -  sorts a doubly linked list of integers
 * @list: list to be sorting
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *lists, *head, *current, *tail;
    int i, j;

    lists = *list;
    if (lists == NULL || lists->next == NULL || lists->prev == NULL)
    {
        print_list(lists);
    }

    head = NULL;
    current = lists;
    while (lists != NULL)
    {
        lists = lists->next;
        if (head == NULL || current->n < head->n)
        {
            current->next = head;
            head = current;
            print_list(head);
        }
        else
        {
            tail = head;
            while (tail != NULL)
            {
                if (tail->next == NULL || current->n < tail->n)
                {
                    current->next = tail->next;
                    tail->next =  current;
                    print_list(head);
                    break;
                }
                tail = tail->next;
            }
        }
    }
}
