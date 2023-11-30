#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Validate.h"

#define D 0
#define DD 0
#define MODULO 10007

void print_matrix(int **a, int nl, int nc)
{
	if (D)
		printf("print_matrix [%p] %dx%d\n", (void *)a, nl, nc);
	int i, j;
	for (i = 0; i < nl; i++) {
		for (j = 0; j < nc; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

int sum_matrix(int **a, int nl, int nc)
{
	if (D)
		printf("sum_matrix %dx%d = ", nl, nc);
	int i, j;
	int s = 0;
	for (i = 0; i < nl; i++) {
		for (j = 0; j < nc; j++)
			s = s + a[i][j];
	}
	s = modulo_positive(s);
	return s;
}

void free_matrix(int **a, int nl)
{
	if (DD)
		printf("free_matrix %d\n", nl);
	for (int i = 0; i < nl; i++)
		free(a[i]);
	free(a);
}

int **cut_matrix(int **b, int *l, int *c, int nl, int *li, int nc, int *ci)
{
	if (D)
		printf("cut_matrix %dx%d --> %dx%d\n", *l, *c, nl, nc);
	int **a;
	int i, j;

	a = malloc(nl * sizeof(int *));
	for (i = 0; i < nl; i++) {
		a[i] = malloc(nc * sizeof(int));
		for (j = 0; j < nc; j++) {
			if ((li[i] + 1 > *l) || (ci[j] + 1 > *c)) {
				printf("Invalid cut index. Return original matrix.\n");
				free_matrix(a, nl);
				return b;
			} else {
				a[i][j] = b[li[i]][ci[j]];
			}
		}
	}
	free_matrix(b, *l);
	*l = nl;
	*c = nc;
	return a;
}

int **transpose_matrix(int **b, int *l, int *c)
{
	if (D)
		printf("transpose_matrix %dx%d --> %dx%d\n", *l, *c, *c, *l);
	int **a;
	int i, j;
	int nl = *c;
	int nc = *l;

	a = malloc(nl * sizeof(int *));
	for (i = 0; i < nl; i++) {
		a[i] = malloc(nc * sizeof(int));
		for (j = 0; j < nc; j++)
			a[i][j] = b[j][i];
	}
	free_matrix(b, *l);
	*l = nl;
	*c = nc;
	return a;
}

int **read_matrix(int nl, int nc)
{
	if (DD)
		printf("read_matrix %dx%d\n", nl, nc);
	int **a;
	int i, j;

	a = malloc(nl * sizeof(int *));

	for (i = 0; i < nl; i++) {
		a[i] = malloc(nc * sizeof(int));
		for (j = 0; j < nc; j++)
			scanf("%d", &a[i][j]);
	}
	return a;
}

int **init_alloc_matrix(int nl, int nc, int v)
{
	int **a;
	int i, j;

	a = malloc(nl * sizeof(int *));
	for (i = 0; i < nl; i++)
		a[i] = malloc(nc * sizeof(int));

	for (i = 0; i < nl; i++) {
		for (j = 0; j < nc; j++) {
			a[i][j] = v;
			if (v < 0)
				a[i][j] = -v;
		}
	}
	return a;
}
