#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

# define D 0  //debug messages
# define DD 0 //detail debug messages

// print_collection (collection, size, linesvector, columnsvector)
void print_collection(int ***a, int z, int *l, int *c)
{
	if (D)
		printf("print_collection /%d/\n", z);
	int i, j, k;
	for (k = 0; k < z; k++) {
		printf("#%d\n", k);
		for (i = 0; i < l[k]; i++) {
			for (j = 0; j < c[k]; j++)
				printf("%d ", a[k][i][j]);
			printf("\n");
		}
	}
}

// free_collection(collection, size, linesvector)
void free_collection(int ***a, int z, int *l)
{
	if (DD)
		printf("free_collection /%d/\n", z);
	int k;
	for (k = 0; k < z; k++)
		free_matrix(a[k], l[k]);
	free(a);
}

void free_cube(int ***q, int nk, int *ql)
{
	if (D)
		printf("free_cube [%p]\n", (void *)q);

	int k;

	for (k = 0; k < nk ; k++)
		free_matrix(q[k], ql[k]);
}

int add_matrix(int ***q, int *qz, int *ql, int *qc, int **a, int l, int c)
{
	if (*qz < 0)
		return 1;
	int i, j;
	int nz = *qz + 1;

	ql[*qz] = l;
	qc[*qz] = c;

	q[*qz] = malloc(l * sizeof(int *));
	for (i = 0; i < l; i++) {
		q[*qz][i] = malloc(c * sizeof(int));
		for (j = 0; j < c; j++)
			q[*qz][i][j] = a[i][j];
	}
	*qz = nz;

	return 0;
}

int ***sort_cube(int ***q, int qk, int z, int *ql, int *qc, int *top)
{
	int ***a;
	int i, j, k;
	int *ol = malloc(z * sizeof(int));
	int *oc = malloc(z * sizeof(int));
	for (k = 0; k < z ; k++) {
		ol[k] = ql[k];
		oc[k] = qc[k];
	}
	a = malloc(qk * sizeof(int **));
	for (k = 0; k < z; k++) {
		a[k] = malloc(ql[top[k]] * sizeof(int *));
		for (i = 0; i < ql[top[k]]; i++) {
			a[k][i] = malloc(qc[top[k]] * sizeof(int));
			for (j = 0; j < qc[top[k]]; j++)
				a[k][i][j] = q[top[k]][i][j];
		}
	}
	free_collection(q, z, ql);
	for (k = 0; k < z ; k++) {
		ql[k] = ol[top[k]];
		qc[k] = oc[top[k]];
	}
	free(ol);
	free(oc);
	return a;
}
