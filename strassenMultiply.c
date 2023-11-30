//Copyright Miruna-elena Iliescu 312CAb 2023-2024
#include <stdio.h>
#include <stdlib.h>
#include "Validate.h"

#define D 0

// Function to add two matrices
void add_matrices(int **A, int **B, int **C, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			C[i][j] = modulo_positive(A[i][j] + B[i][j]);
}

// Function to subtract two arrays
void subtract_matrices(int **A, int **B, int **C, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			C[i][j] = modulo_positive(A[i][j] - B[i][j]);
}

// Function to multiply two matrices using Strassen's algorithm
void strassen_multiply(int **A, int **B, int **C, int size)
{
	if (size == 1) {
		C[0][0] = modulo_positive(A[0][0] * B[0][0]);
		return;
	}
	int new_size = size / 2;
	int **A11 = (int **)malloc(new_size * sizeof(int *));
	int **A12 = (int **)malloc(new_size * sizeof(int *));
	int **A21 = (int **)malloc(new_size * sizeof(int *));
	int **A22 = (int **)malloc(new_size * sizeof(int *));
	int **B11 = (int **)malloc(new_size * sizeof(int *));
	int **B12 = (int **)malloc(new_size * sizeof(int *));
	int **B21 = (int **)malloc(new_size * sizeof(int *));
	int **B22 = (int **)malloc(new_size * sizeof(int *));
	int **C11 = (int **)malloc(new_size * sizeof(int *));
	int **C12 = (int **)malloc(new_size * sizeof(int *));
	int **C21 = (int **)malloc(new_size * sizeof(int *));
	int **C22 = (int **)malloc(new_size * sizeof(int *));
	int **M1 = (int **)malloc(new_size * sizeof(int *));
	int **M2 = (int **)malloc(new_size * sizeof(int *));
	int **M3 = (int **)malloc(new_size * sizeof(int *));
	int **M4 = (int **)malloc(new_size * sizeof(int *));
	int **M5 = (int **)malloc(new_size * sizeof(int *));
	int **M6 = (int **)malloc(new_size * sizeof(int *));
	int **M7 = (int **)malloc(new_size * sizeof(int *));
	for (int i = 0; i < new_size; i++) {
		A11[i] = (int *)malloc(new_size * sizeof(int));
		A12[i] = (int *)malloc(new_size * sizeof(int));
		A21[i] = (int *)malloc(new_size * sizeof(int));
		A22[i] = (int *)malloc(new_size * sizeof(int));
		B11[i] = (int *)malloc(new_size * sizeof(int));
		B12[i] = (int *)malloc(new_size * sizeof(int));
		B21[i] = (int *)malloc(new_size * sizeof(int));
		B22[i] = (int *)malloc(new_size * sizeof(int));
		C11[i] = (int *)malloc(new_size * sizeof(int));
		C12[i] = (int *)malloc(new_size * sizeof(int));
		C21[i] = (int *)malloc(new_size * sizeof(int));
		C22[i] = (int *)malloc(new_size * sizeof(int));
		M1[i] = (int *)malloc(new_size * sizeof(int));
		M2[i] = (int *)malloc(new_size * sizeof(int));
		M3[i] = (int *)malloc(new_size * sizeof(int));
		M4[i] = (int *)malloc(new_size * sizeof(int));
		M5[i] = (int *)malloc(new_size * sizeof(int));
		M6[i] = (int *)malloc(new_size * sizeof(int));
		M7[i] = (int *)malloc(new_size * sizeof(int));
	}
	for (int i = 0; i < new_size; i++) {
		for (int j = 0; j < new_size; j++) {
			A11[i][j] = A[i][j];
			A12[i][j] = A[i][j + new_size];
			A21[i][j] = A[i + new_size][j];
			A22[i][j] = A[i + new_size][j + new_size];
			B11[i][j] = B[i][j];
			B12[i][j] = B[i][j + new_size];
			B21[i][j] = B[i + new_size][j];
			B22[i][j] = B[i + new_size][j + new_size];
		}
	}
	// Calculation of values M1 to M7
	add_matrices(A11, A22, C11, new_size); // not true C11, use it temporary
	add_matrices(B11, B22, C12, new_size); // not true C12, use it temporary
	strassen_multiply(C11, C12, M1, new_size); // M1 = (A11 + A22) * (B11 + B22)
	add_matrices(A21, A22, C11, new_size);
	strassen_multiply(C11, B11, M2, new_size); // M2 = (A21 + A22) * B11
	subtract_matrices(B12, B22, C11, new_size);
	strassen_multiply(A11, C11, M3, new_size); // M2 = A11 * (B12 - B22)
	subtract_matrices(B21, B11, C11, new_size);
	strassen_multiply(A22, C11, M4, new_size); // M4 = A22 * (B21 - B11)
	add_matrices(A11, A12, C11, new_size);
	strassen_multiply(C11, B22, M5, new_size); // M5 = (A11 + A12) * B22
	subtract_matrices(A21, A11, C11, new_size);
	add_matrices(B11, B12, C12, new_size);
	strassen_multiply(C11, C12, M6, new_size); // M6 = (A21 - A11) * (B11 + B12)
	subtract_matrices(A12, A22, C11, new_size);
	add_matrices(B21, B22, C12, new_size);
	strassen_multiply(C11, C12, M7, new_size);
	add_matrices(M1, M4, A11, new_size);// Calculation the resulting submatrices
	subtract_matrices(A11, M5, A12, new_size);
	add_matrices(A12, M7, C11, new_size); // C11 = M1 + M4 - M5 + M7
	add_matrices(M3, M5, C12, new_size);  // C12 = M3 + M5
	add_matrices(M2, M4, C21, new_size);  // C21 = M2 + M4
	add_matrices(M1, M3, A11, new_size);
	subtract_matrices(A11, M2, A12, new_size);
	add_matrices(A12, M6, C22, new_size); // C22 = M1 + M3 - M2 + M6
	// Copy the result into the result matrix
	for (int i = 0; i < new_size; i++) {
		for (int j = 0; j < new_size; j++) {
			C[i][j] = C11[i][j];
			C[i][j + new_size] = C12[i][j];
			C[i + new_size][j] = C21[i][j];
			C[i + new_size][j + new_size] = C22[i][j];
		}
	}
	// Release memory allocated for subarrays
	for (int i = 0; i < new_size; i++) {
		free(A11[i]); free(A12[i]); free(A21[i]); free(A22[i]); free(B11[i]);
		free(B12[i]); free(B21[i]); free(B22[i]); free(C11[i]); free(C12[i]);
		free(C21[i]); free(C22[i]);	free(M1[i]); free(M2[i]); free(M3[i]);
		free(M4[i]); free(M5[i]); free(M6[i]); free(M7[i]);
	}
	free(A11); free(A12); free(A21); free(A22); free(B11); free(B12);
	free(B21); free(B22); free(C11); free(C12); free(C21); free(C22);
	free(M1); free(M2); free(M3); free(M4); free(M5); free(M6); free(M7);
}
