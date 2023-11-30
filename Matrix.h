int sum_matrix(int **a, int nl, int nc);
// sum = sum_matrix (matrix, lines, colums);

void print_matrix(int **a, int nl, int nc);
// print_matrix(matrix, lines, columns)

int **transpose_matrix(int **b, int *l, int *c);
// transpose = transpose_matrix(matrix, lines-pointer, columns-pointer)

int **cut_matrix(int **b, int *l, int *c, int nl, int *li, int nc, int *ci);
// matrix = (matrix, lines, columns, n-lines-to-cut, lines, n-col-to-cut, cols)

void free_matrix(int **a, int nl);
// free_matrix(matrix, lines)

int **read_matrix(int nl, int nc);
int **init_alloc_matrix(int nl, int nc, int v);
