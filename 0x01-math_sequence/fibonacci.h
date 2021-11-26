#ifndef FIBONACCI_H
#define FIBONACCI_H


#include  <stdlib.h>
#include  <math.h>

/**
 * struct s_cell - un struct para almacenar una secuencia de Heron
 * @elt: la aproximación de una raíz cuadrada de un número
 * @next: a pointer to the next node
 */

typedef struct s_cell
{
	double elt;
	struct s_cell *next;
} t_cell;

t_cell *Fibonnaci();
double gold_number(t_cell *head);


#endif
