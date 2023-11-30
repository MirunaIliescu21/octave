// get_row(matrix, index, nr columns)
int *get_row(int **a, int k, int nc);

// get_column(matrix, index, nr lines)
int *get_column(int **a, int k, int nl);

// multiplicate matrix(mat1, nr rows, nr cols, mat2, nr rows, nr cols, result)
int multiplicate(int **m, int x1, int y1, int **n, int x2, int y2, int **a);

// new_matrix_multiplicate(mat1, nr rows, nr cols, mat2, nr rows, nr cols)
int **mat_multiply(int **m, int x1, int y1, int **n, int x2, int y2);
