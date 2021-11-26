#include "heron.h"

/**
 * reverse_list - reverses a linked list.
 * @head: Pointer to list's head pointer
 * Return: Pointer to first node of reversed list
 */

t_cell *reverse_list(t_cell **head)
{
	t_cell *aux, *tmp;

	aux = *head;
	tmp = NULL;
	while (*head)
	{
		(*head) = (*head)->next;
		aux->next = tmp;
		tmp = aux;
		aux = *head;
	}
	(*head) = tmp;
	return (*head);
}

/**
 * heronaux - Heron sequence until having convergence with an error
 * less or equal to 10^-7.
 * @p: Independent term of the sequence
 * @x0: First term of the sequence
 * Return: Pointer to sequence
 */


t_cell *heronaux(double p, double x0)
{
	double d;
	t_cell *ret;

	d = (0.5) * (x0 + (p / x0));
	ret = (t_cell *)malloc(sizeof(t_cell));
	if (ret == NULL)
		return (NULL);
	ret->elt = x0;
	if (((d - x0) * (d - x0)) <= 10E-14)
		ret->next = NULL;
	else
		ret->next = heronaux(p, d);
	return (ret);
}

/**
 * heron - Heron sequence until having convergence with an error
 * less or equal to 10^-7.
 * @p: Independent term of the sequence
 * @x0: First term of the sequence
 * Return: Pointer to sequence
 */

t_cell *heron(double p, double x0)
{
	t_cell *ret;

	ret = heronaux(p, x0);
	ret = reverse_list(&ret);
	return (ret);
}
