#ifndef HERON_H
#define HERON_H

#include <stddef.h>
#include <stdlib.h>

/**
 * struct cell - Struct for sequences
 * @d: Double number of the n'th term
 * @next: Pointer to next term
 */

typedef struct cell
{
	double elt;
	struct cell *next;
} t_cell;

t_cell *heron(double p, double x0);

#endif
