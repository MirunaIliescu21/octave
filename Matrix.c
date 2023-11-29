/* Matrix.c 
   v1.3    */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Validate.h"

#define D 0
#define DD 0
#define MODULO 10007

void printMatrix(int **a, int nl, int nc)
{
    if (D) printf("printMatrix [%p] %dx%d\n", (void*)a, nl,nc);
	int i,j;
	for (i=0; i<nl; i++)
	{
		for (j = 0; j < nc; j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
}

int sumMatrix(int **a, int nl, int nc)
{
    if (D) printf("sumMatrix %dx%d = ",nl,nc);
	int i,j;
	int s = 0;
	for (i=0; i<nl; i++)
	{
		for (j=0; j<nc; j++){
			s = s + a[i][j];
		}
	}
	//modulo_positive(s);
	s = s % MODULO;
	if(s < 0)
		s = s + MODULO;
	return s;
}


void freeMatrix(int **a, int nl)
{
    if (DD) printf("freeMatrix %d\n",nl);
	for (int i = 0; i < nl; i++)
	{
		free(a[i]);
	}
	free(a);
}

int** cutMatrix(int **b, int *l, int *c, int nl, int *li, int nc, int *ci)
{
	if (D) printf("cutMatrix %dx%d --> %dx%d\n", *l, *c, nl, nc);
	int **a;
	int i, j;
	
	a = malloc(nl * sizeof(int*));
	for (i = 0; i < nl; i++) {
		a[i] = malloc(nc * sizeof(int));
		for (j = 0; j < nc; j++){
			if ((li[i] + 1 > *l) || (ci[j] + 1 > *c)) {
				printf("Invalid cut index. Return original matrix.\n");
				freeMatrix(a,nl);
				return b;
			}
			else{
				a[i][j] = b[li[i]][ci[j]];
			}
		}
	}
	freeMatrix(b, *l);
	*l = nl;
	*c = nc;
	return a;
}

int** transposeMatrix(int **b, int *l, int *c)
{
	if (D) printf("transposeMatrix %dx%d --> %dx%d\n", *l, *c, *c, *l);
	int **a;
	int i, j;
	int nl = *c;
	int nc = *l;
	
	a = malloc(nl * sizeof(int*));
	for (i = 0; i < nl; i++) {
		a[i] = malloc(nc * sizeof(int));
		for (j = 0; j < nc; j++){
			a[i][j] = b[j][i];
		}
	}
	freeMatrix(b, *l);
	*l = nl;
	*c = nc;
	return a;
}

int** readMatrixforKeyboard(int nl, int nc)
{
	if (DD) printf("readMatrixforKeyboard %dx%d\n",nl,nc);
	int **a;
	int i,j;

	a = malloc(nl * sizeof(int*));

	for (i = 0; i < nl; i++)
	{
		a[i] = malloc(nc * sizeof(int));
		for (j = 0; j < nc; j++){
			//TODO verificare interval [-10^4,10^4]
			scanf("%d",&a[i][j]);
		}
	}
	return a;
}

int** initAllocMatrix(int nl, int nc, int v)
{
	int **a;
	int i,j;

	a = malloc(nl * sizeof(int*));
	for (i = 0; i < nl; i++) {
		a[i] = malloc(nc * sizeof(int));
	}

	for (i = 0; i < nl; i++)
	{
		for (j = 0; j < nc; j++){
			a[i][j] = v;
			if (v<0) a[i][j] = -v;
		}
	}
	return a;
}

