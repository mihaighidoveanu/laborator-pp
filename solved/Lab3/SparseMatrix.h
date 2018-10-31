#ifndef SPARSEMATRIX_H_INCLUDED
#define SPARSEMATRIX_H_INCLUDED

#include <stdio.h>

typedef struct SparseMatrix {
    unsigned msize;
    int matrix[3][100];
} SparseMatrix;

void readMatrix(SparseMatrix* matrix);
void printMatrix(SparseMatrix matrix);

/* Not implemented yet */
void sum(SparseMatrix* a, SparseMatrix* b, SparseMatrix* result);
void product(SparseMatrix* a, SparseMatrix* b, SparseMatrix* result);


#endif // SPARSEMATRIX_H_INCLUDED
