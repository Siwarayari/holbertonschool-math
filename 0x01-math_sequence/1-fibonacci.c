#include "fibonacci.h"
#define GOLD 1.618034

/**
 * create_node - creates new node for the Fibonacci sequence
 * @n: a member of the Fibonacci sequence
 *
 * Return: a new node for the Fibonacci sequence
 */
t_cell *create_node(double n)
{
	t_cell *fibo = malloc(sizeof(t_cell));

	if (fibo == NULL)
	{
		free(fibo);
		return (NULL);
	}
	fibo->elt = n;
	fibo->next = NULL;
	return (fibo);
}


/**
 * reverse - an auxiliar function to revert the linked list
 * @head: a list of elements with a pointer to the first element
 * @prev: a pointer to a node of the linked list
 * @node: a pointer to another node of the linked list
 *
 * Return: Nothing
 */
void reverse(t_cell **head, t_cell *prev, t_cell *node)
{
	if (node->next != NULL)
	{
		prev = node;
		node = node->next;
		*head = (*head)->next;
		reverse(head, prev, node);
		node->next = prev;
	}
}


/**
 * reverse_cell - reverses a linked list
 * @head: a list of elements with a pointer to the first element
 *
 * Return: a pointer to the first node of the reversed list
 */
t_cell *reverse_cell(t_cell **head)
{
	t_cell *prev, *node;

	if (head == NULL || *head == NULL)
	{
		return (NULL);
	}
	node = *head;
	prev = node;
	reverse(head, prev, node);
	node->next = NULL;
	return (*head);
}

/**
 * Fibonnaci - do the Fibonacci sequence until a golden geometric proportion
 * is found
 *
 * Return: the Fibonacci
 * or equal to 10^(-7)
 */
t_cell *Fibonnaci()
{
	int t1 = 1, t2 = 1, aux;
	t_cell *fib = create_node(t1);
	t_cell *ptr = fib;
	double error;
	double divs;
	ptr->next = create_node(t2);
	ptr = ptr->next;

	while (1)
	{
		aux = (int)t1;
		t1 = (int)t2;
		t2 += (int)aux;

		divs = (double)t2 / (double)t1;
		error = divs - GOLD;
		if (error < 0)
			error *= -1;
		ptr->next = create_node(t2);
		ptr = ptr->next;
		if (error <= 0.00000005)
			break;
	}
	reverse_cell(&fib);
	return (fib);
}

/**
 * gold_ number - find the golden number with a precision of 6 decimals
 * @head: a pointer to the Fibonacci seuence
 *
 * Return: the gold number
 */
double gold_number(t_cell *head)
{
	double goldfib = (double)(head->elt) / (double)(head->next->elt);

	return (goldfib);
}
