int sumMatrix(int **a, int nl, int nc);
// sum = sumMatrix (matrix, lines, colums);

void printMatrix(int **a, int nl, int nc);
// printMatrix(matrix, lines, columns)

int** transposeMatrix(int **b, int *l, int *c);
// transpose = transposeMatrix(matrix, lines-pointer, columns-pointer)

int** cutMatrix(int **b, int *l, int *c, int nl, int *li, int nc, int *ci);
// matrix = (matrix, lines-p, columns-p, n-lines-to-cut, lines-to-cut, n-col-to-cut, cols-to-cut)

void freeMatrix(int **, int);
// freeMatrix(matrix, lines)

int** readMatrixforKeyboard(int nl, int nc);
int** initAllocMatrix(int nl, int nc, int v);
