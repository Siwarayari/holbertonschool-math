#include "fibonacci.h"

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
 * Create_Fib - Creates a fibonacci sequence
 * @num1: First term of fibonacci sequence
 * @num2: Second term of Fibonacci sequence
 * Return: Pointer to sequence
 */

t_cell *Create_Fib(double num1, double num2)
{
	t_cell *ret;

	ret = (t_cell *)malloc(sizeof(t_cell));
	if (ret == NULL)
		return (NULL);
	ret->elt = num1 + num2;
	if (fabs((ret->elt / num2) - (num2 / num1)) <= 10E-8)
		ret->next = NULL;
	else
		ret->next = Create_Fib(num2, ret->elt);
	return (ret);
}

/**
 * Fibonnaci - Fibonacci sequence until having a geometric behavior
 * Return: Pointer to F1
 */

t_cell *Fibonnaci()
{
	t_cell *f1, *f2;

	f1 = (t_cell *)malloc(sizeof(t_cell));
	if (f1 == NULL)
		return (NULL);
	f2 = (t_cell *)malloc(sizeof(t_cell));
	if (f2 == NULL)
		return (NULL);
	f1->elt = (double)1;
	f1->next = f2;
	f2->elt = (double)1;
	f2->next = Create_Fib(f1->elt, f2->elt);
	f1 = reverse_list(&f1);
	return (f1);
}

/**
 * gold_number - calcs the gold number
 * @head: Fibonacci's sequence head pointer
 * Return: Value of gold number
 */

double gold_number(t_cell *head)
{
	double gold, aux;

	gold =  (double)(head->elt) / (double)((head->next)->elt);
	aux = (double)((head->next)->elt) / (double)(((head->next)->next)->elt);
	if (fabs((aux / gold) - 1) >= 10E-7)
		gold = gold_number(head->next);
	return (gold);
}
