#include "sort.h"

void swap_tail(listint_t **list, listint_t **head, listint_t **tail)
{
	listint_t *temp = (*tail)->next;

	if ((*tail)->prev != NULL)
	{
		(*tail)->prev->next = temp;
	}
	else
		*list = temp;
	temp->prev = (*tail)->prev;
	(*tail)->next = temp->next;
	if (temp->next !=NULL)
	{
		temp->next->prev = *tail;
	}
	else
		*head = *tail;
	(*tail)->prev = temp;
	temp->next = *tail;
	*tail = temp;
}
void swap_head(listint_t **list, listint_t **tail, listint_t **head)
{
	listint_t *temp = (*head)->next;

	if ((*head)->next != NULL)
		(*head)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*tail)->next;
	(*head)->prev = temp->prev;
	if (temp->prev !=NULL)
	{
		temp->prev->next = *head;
	}
	else
		*list = *head;
	(*head)->next = temp;
	temp->prev = *head;
	*head = temp;
}
void cocktail_sort_list(listint_t **list)
{
	bool booln = false;
	listint_t *head;
	listint_t *tail;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;
	
	for (;booln == false; booln = true)
	{
		for (head = *list; head != tail; head = head->next)
		{
			if (head->n > head->next->n)
			{
				swap_tail(list, &tail, &head);
				print_list((const listint_t *) *list);
				booln = false;
			}
		}
		for (head = head->prev; head != *list; head = head->prev)
		{
			if (head->n < head->prev->n)
			{
				swap_head(list, &tail, &head);
				print_list((const listint_t *) *list);
				booln = false;
			}
		}
	}
}
