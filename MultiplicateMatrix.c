//multiplication of two matrices
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Validate.h"

#define MODULO 10007

// get_row(matrix, index, nr columns)
int *get_row(int **a, int k, int nc)
{
	int *v = malloc(nc * sizeof(int));
	for (int i = 0; i < nc ; i++)
		v[i] = a[k][i];
	return v;
}

// get_column(matrix, index, nr lines)
int *get_column(int **a, int k, int nl)
{
	int *v = malloc(nl * sizeof(int));
	for (int i = 0; i < nl ; i++)
		v[i] = a[i][k];
	return v;
}

int multiplicate_vectors(int *v, int *w, int n)
{
	int s = 0;
	for (int i = 0; i < n; i++)
		s = s + modulo_positive(v[i] * w[i]);

	s = modulo_positive(s);
	return s;
}

//multiplicate matrix(matrix1, nr rows, nr col, matrix2, nr rows, nr col)
int multiplicate(int **m, int x1, int y1, int **n, int x2, int y2, int **a)
{
	if (y1 == x2) {
		int i, j;
		int *l;
		int *c;
		for (i = 0; i < x1; i++) {
			l = get_row(m, i, y1);
			for (j = 0; j < y2; j++) {
				c = get_column(n, j, x2);
				a[i][j] = multiplicate_vectors(l, c, y1);
				free(c);
			}
			free(l);
		}
	} else {
		printf("Cannot perform matrix multiplication\n");
		return 1;
	}
	return 0;
}

int **mat_multiply(int **m, int x1, int y1, int **n, int x2, int y2)
{
	int **a;
	if (y1 == x2) {
		int i, j;
		a = malloc(x1 * sizeof(int *));
		for (i = 0; i < x1; i++)
			a[i] = malloc(y2 * sizeof(int));
		int *l;
		int *c;
		for (i = 0; i < x1; i++) {
			l = get_row(m, i, y1);
			for (j = 0; j < y2; j++) {
				c = get_column(n, j, x2);
				a[i][j] = multiplicate_vectors(l, c, y1);
				free(c);
			}
			free(l);
		}
	} else {
		printf("Cannot perform matrix multiplication\n");
		return NULL;
	}
	return a;
}
