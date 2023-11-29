#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"
#include "Exponent.h"

# define D 0  //debug messages
# define DD 0 //detail debug messages

// printCollection (collection, size, linesvector, columnsvector)
void printCollection(int ***a, int z, int *l, int *c)
{
    if (D) printf("printCollection /%d/\n", z);
	int i,j,k;
	for(k = 0; k < z; k++) {
		printf("#%d\n",k);
		for (i = 0; i < l[k]; i++)
		{
			for (j = 0; j < c[k]; j++){
				printf("%d ", a[k][i][j]);
			}
			printf("\n");

		}
	}
}

// freeCollection(collection, size, linesvector)
void freeCollection(int ***a, int z, int *l)
{
    if (DD) printf("freeCollection /%d/\n", z);
	int k;
	for(k = 0; k < z; k++) {
		freeMatrix(a[k],l[k]);
	}
	free(a);
}

void freeCube(int ***q, int nk, int* ql)
{
    if(D) printf("freeCube [%p]\n", (void *)q);

	int k;

    for(k = 0; k < nk ; k++)
    {
		freeMatrix(q[k],ql[k]);
    }
    //free(q); do it in caller function
}

int addMatrixtoCube(int ***q, int* qz, int* ql, int* qc, int **a, int l, int c)
{
    if (D) printf("addMatrixtoCube /%d/ \n", *qz);

	if (*qz < 0) return 1;
    
    int i,j;

    int nz = *qz + 1; 
  
    ql[*qz] = l;
    qc[*qz] = c;

    q[*qz] = malloc (l * sizeof(int*));
	for (i = 0; i < l; i++)
		{
            q[*qz][i] = malloc( c * sizeof(int));		
			for (j = 0; j < c; j++){
				q[*qz][i][j] = a[i][j];
			}
		}
    *qz = nz;

    return 0;

}

int*** sortCube(int ***q, int qk, int z, int *ql, int *qc, int *top)
{
    if (D) printf("sortCollection #%d \n", z);
	int ***a;
	int i,j,k;
	int *ol = malloc(z * sizeof(int));
	int *oc = malloc(z * sizeof(int));
	for (k=0 ; k < z ; k++) {
		ol[k] = ql[k];
		oc[k] = qc[k];
	}

	a = malloc(qk * sizeof(int**));
	for (k = 0; k < z; k++) {
		a[k]=malloc(ql[top[k]] * sizeof(int*));
		for (i = 0; i < ql[top[k]]; i++) {
			a[k][i] = malloc(qc[top[k]] * sizeof(int));
				for (j = 0; j < qc[top[k]]; j++){
						a[k][i][j] = q[top[k]][i][j];
				}
		}
	}
	freeCollection(q,z,ql);
	for (k=0 ; k < z ; k++) {
		ql[k] = ol[top[k]]; 
		qc[k] = oc[top[k]]; 
	}
	free(ol);
	free(oc);
	return a;
}
