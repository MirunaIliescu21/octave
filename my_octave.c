// Copyright Miruna-elena Iliescu 312CAb 2023-2024
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Validate.h"
#include "Matrix.h"
#include "Collection.h"
#include "Radix.h"
#include "PowerMatrix.h"
#include "strassenMultiply.h"
#include "MultiplicateMatrix.h"
# define D 0 // debug messages: 0 - no, 1 -yes
# define P 0 // command prompt: 0 - no, 1 -yes

int main(void)
{
	int qz = 0, qk = 1, *ql, *qc;//size, capacity, lines vector, columns vector
	int *sum = malloc(qk * sizeof(int)); // the sum of each matrix
	int *top = malloc(qk * sizeof(int));// the position of the matrix
	int ***q = malloc(qk * sizeof(int **)); //resizable array
	int **a, l, c, k, k1, k2, p;
	ql = malloc(qk * sizeof(int));
	qc = malloc(qk * sizeof(int));
	char key = '\0';
	while (1) {
		int ok = 0;
		scanf("%c", &key);
		if (key == 'L') {
			ok = 1;
			scanf("%d%d", &l, &c);
			a = read_matrix(l, c);
			if (qz == qk) {
				qk = qk * 2;
				q = (void *)realloc(q, qk * sizeof(int **));
				ql = realloc(ql, qk * sizeof(int));
				qc = realloc(qc, qk * sizeof(int));
			}
			add_matrix(q, &qz, ql, qc, a, l, c);
			free_matrix(a, l);
		}
		if (key == 'D') {
			ok = 1;
			scanf("%d", &k);
			if (validate_index(k, qz))
				printf("%d %d\n", ql[k], qc[k]);
		}
		if (key == 'P') {
			ok = 1;
			scanf("%d", &k);
			if (validate_index(k, qz))
				print_matrix(q[k], ql[k], qc[k]);
		}
		if (key == 'C') {
			ok = 1;
			scanf("%d", &k);
				int lx, cx;
				scanf("%d", &lx); // nr of lines
				int li[lx];
				for (int i = 0; i < lx; i++)
					scanf("%d", &li[i]);
				scanf("%d", &cx); // nr of columns
				int ci[cx];
				for (int i = 0; i < cx; i++)
					scanf("%d", &ci[i]);
			if (validate_index(k, qz))
				q[k] = cut_matrix(q[k], &ql[k], &qc[k], lx, li, cx, ci);
		}
		if (key == 'M') {
			ok = 1;
			scanf("%d%d", &k1, &k2);
			if (validate_index(k1, qz) && validate_index(k2, qz)) {
				a = mat_multiply(q[k1], ql[k1], qc[k1], q[k2], ql[k2], qc[k2]);
				l = ql[k1]; c = qc[k2];
				if (a) {
					if (qz == qk) {
						qk = qk * 2;
						q = (void *)realloc(q, qk * sizeof(int **));
						ql = realloc(ql, qk * sizeof(int));
						qc = realloc(qc, qk * sizeof(int));
					}
					ql[qz] = l; qc[qz] = c;
					add_matrix(q, &qz, ql, qc, a, l, c);
					free_matrix(a, l);
				}
			}
		}
		if (key == 'O') {
			ok = 1;
			if (qz > 0) {
				sum = realloc(sum, qz * sizeof(int));
				top = realloc(top, qz * sizeof(int));
				for (int i = 0; i < qz; i++)
					sum[i] = sum_matrix(q[i], ql[i], qc[i]);
				sort_vector(sum, qz, top);
				q = sort_cube(q, qk, qz, ql, qc, top);
			}
		}
		if (key == 'T') {
			ok = 1;
			scanf("%d", &k);
			if (validate_index(k, qz))
				q[k] = transpose_matrix(q[k], &ql[k], &qc[k]);
		}
		if (key == 'R') {
			ok = 1;
			scanf("%d%d", &k, &p);
			if (validate_index(k, qz))
				power_matrix(q[k], ql[k], qc[k], p);
		}
		if (key == 'F') {
			ok = 1;
			int ki;
			scanf("%d", &ki);
			if (validate_index(ki, qz)) {
				int *qlo = malloc(qz * sizeof(int));
				int *qco = malloc(qz * sizeof(int));
				for (int i = 0; i < qz; i++) {
					qlo[i] = ql[i];
					qco[i] = ql[i];
				}
				int ***w, nz = qz - 0;
				if (nz != 0) {
					int ka = 0;
					w = malloc((qk) * sizeof(int **));
					for (k = 0; k < qz; k++) {
						if (k != ki) {
							ql[ka] = ql[k]; qc[ka] = qc[k];
							w[ka] = malloc(ql[k] * sizeof(int *));
							for (int i = 0; i < ql[k]; i++) {
								w[ka][i] = malloc(qc[k] * sizeof(int));
								for (int j = 0; j < qc[k]; j++)
									w[ka][i][j] = q[k][i][j];
							}
							ka++;
						}
					}
					qz = qz - 1;
					free_cube(q, qz + 1, qlo);
					free(q); free(qlo); free(qco);
					q = w;
				}
			}
		}
		if (key == 'Q') {
			ok = 1;
			free_collection(q, qz, ql);
			free(sum); free(top); free(ql); free(qc);
			break;
		}
		if (key == 'S') {
			ok = 1;
			scanf("%d%d", &k1, &k2);
			if (validate_index(k1, qz) && validate_index(k2, qz)) {
				if (validate_size(k1, k2, ql, qc) != 0) {
					l = ql[k2];
					a = init_alloc_matrix(l, l, -1);
					strassen_multiply(q[k1], q[k2], a, l);
					if (qz == qk) {
						qk = qk * 2;
						q = (void *)realloc(q, qk * sizeof(int **));
						ql = realloc(ql, qk * sizeof(int));
						qc = realloc(qc, qk * sizeof(int));
					}
					ql[qz] = l; qc[qz] = l;
					add_matrix(q, &qz, ql, qc, a, l, l); free_matrix(a, l);
				}
			}
		}
		if (ok == 0)
			if (key != '\n' && key != '\r')
				printf("Unrecognized command\n");
	}
	return 0;
}
