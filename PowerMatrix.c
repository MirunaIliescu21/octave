#include <stdlib.h>
#include <stdio.h>
#include "Matrix.h"
#include "Validate.h"

#define D 0
#define MAXPOW 1000000001
#define MODULO 10007

// Function to multiply two matrices
void multiply_matrices(int **A, int **B, int **result, int size)
{
	int i, j, k;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			result[i][j] = 0;
			for (k = 0; k < size; k++)
				result[i][j] += modulo_positive(A[i][k] * B[k][j]);
			result[i][j] = modulo_positive(result[i][j]);
		}
	}
}

// Function to copy the source matrix to the destination matrix
void copy_matrix(int **source, int **destination, int size)
{
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++)
			destination[i][j] = source[i][j];
	}
}

// Function to raise a matrix to a power
int power_matrix(int **matrix, int l, int c, int exponent)
{
	if (D)
		printf("power_matrix [%p] %dx%d\n", (void *)matrix, l, c);
	if (exponent < 0) {
		printf("Power should be positive\n");
		return 1;
	}
	if (l != c) {
		printf("Cannot perform matrix multiplication\n");
		return 1;
	}

	// The resulting matrix is initialized with the identity matrix
	int size = l;
	if (exponent > MAXPOW)
		return 2;
	exponent = exponent % MAXPOW;
	int **temp = (int **)malloc(size * sizeof(int *));
	int **result = (int **)malloc(size * sizeof(int *));
	for (int i = 0; i < size; i++) {
		temp[i] = (int *)malloc(size * sizeof(int));
		result[i] = (int *)malloc(size * sizeof(int));

		for (int j = 0; j < size; j++) {
			if (i == j)
				temp[i][j] = 1;
			else
				temp[i][j] = 0;
		}
	}

	// Matrix exponentiation using the logarithmic exponential method
	while (exponent > 0) {
		if (exponent % 2 == 1) {
			multiply_matrices(temp, matrix, result, size);
			copy_matrix(result, temp, size);
		}

		multiply_matrices(matrix, matrix, result, size);
		copy_matrix(result, matrix, size);
		exponent /= 2;
	}
	// Copy the final result into the result array
	copy_matrix(temp, matrix, size);

	// Free the allocated memory for the temporary array
	for (int i = 0; i < size; i++) {
		free(temp[i]);
		free(result[i]);
	}
	free(result);
	free(temp);
	return 0;
}
