#include "fibonacci.h"

/**
* Fibonnaci - fibonacci
* Return: void
*/

t_cell *Fibonnaci()
{
double goldn = 1.618034;
double togold = 2;
int mflag = 1;
double diff = 0.00000005, oper;
t_cell *prevnode, *preprevnode, *tempnode, *fibon;

fibon = malloc(sizeof(t_cell));
	if (fibon == NULL)
		free(fibon);
fibon->elt = 1;
fibon->next = NULL;
preprevnode = fibon;
prevnode = fibon;
tempnode = malloc(sizeof(t_cell));
	if (tempnode == NULL)
		free(tempnode);
tempnode->elt = 1;
tempnode->next = preprevnode;
preprevnode = tempnode;
	while (mflag)
	{
		tempnode = malloc(sizeof(t_cell));
			if (tempnode == NULL)
				free(tempnode);
		tempnode->elt = preprevnode->elt + prevnode->elt;
		tempnode->next = preprevnode;
		prevnode = preprevnode;
		preprevnode = tempnode;
		togold = (double) preprevnode->elt / prevnode->elt;
			if (togold > goldn)
				oper = togold - goldn;
			else
				oper = goldn - togold;

			if (oper <= diff)
				mflag = 0;
	}
return (preprevnode);
}

/**
* gold_number - calculate gold number from fibonacci numbers
* @head: list
* Return: void
*/
double gold_number(t_cell *head)
{
double thediv;
t_cell *a;
t_cell *b;
/* receive a SLL divide the last number with the previous */
a = head;
head = head->next;
b = head;
thediv = (double) a->elt / b->elt;
/* Thats it */
return (thediv);
}
