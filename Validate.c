#include <stdio.h>
#define MODULO 10007

int validate_index(int k, int size)
{
	if (k >= size || k < 0) {
		printf("No matrix with the given index\n");
		return 0;
	}
	return 1;
}

int validate_size(int k1, int k2, int *ql, int *qc)
{
	if (qc[k1] == ql[k2]) {
		if (ql[k1] != qc[k2] || ql[k2] != qc[k2]) {
			printf("Cannot perform matrix multiplication\n");
			return 0;
		}
	} else {
		printf("Cannot perform matrix multiplication\n");
		return 0;
	}
	return 1;
}

int modulo_positive(int s)
{
	s = s % MODULO;
	if (s < 0)
		s = s + MODULO;
	return s;
}
