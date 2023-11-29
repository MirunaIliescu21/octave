// printCollection (collection, size, linesvector, columnsvector)
void printCollection(int ***a, int z, int *l, int *c);

// freeCollection(collection, size, linesvector)
void freeCollection(int ***a, int z, int *l);

void freeCube(int ***q, int nk, int* ql);

int addMatrixtoCube(int ***q, int* qz, int* ql, int* qc, int **a, int l, int c);

int*** sortCube(int ***q, int qk, int z, int *ql, int *qc, int *top);
