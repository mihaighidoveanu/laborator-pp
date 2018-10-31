#include "SparseMatrix.h"

void readMatrix(SparseMatrix* sparse){
    int index = 0;
    for(; index < sparse->msize; ++index){
        scanf("%d %d %d",&(sparse->matrix[0][index]), &(sparse->matrix[1][index]), &(sparse->matrix[2][index]));
    }
}

void printMatrix(SparseMatrix sparse){
    int index, level;
    for(level = 0; level < 3; ++level){
        for(index = 0; index < sparse.msize; ++index){
            printf("%d ",sparse.matrix[level][index]);
        }
        printf("\n");
    }

}


/* Not finished */
void sum(SparseMatrix* a, SparseMatrix* b, SparseMatrix* result){
    unsigned aIndex = 0, bIndex = 0, rIndex = 0;
    if(a->msize != b->msize || a->msize != result->msize){
        return;
    }
    while(aIndex < a->msize && bIndex < b->msize){
        if(a->matrix[0][aIndex] < b->matrix[0][bIndex]){
            result->matrix[2][aIndex] = a->matrix[2][aIndex];
            ++aIndex;
        }else{
            // if element exists at this line for both sides, check for columns
            if(a->matrix[0][aIndex] == b->matrix[0][bIndex] && a->matrix[1][aIndex] < b->matrix[1][bIndex]){
                result->matrix[2][aIndex] = a->matrix[2][aIndex];
                ++aIndex;
            }
        }
        //if element exists for row and column on both matrices, add them
        if(a->matrix[0][aIndex] == b->matrix[0][bIndex] && a->matrix[1][aIndex] == b->matrix[1][bIndex]){
            result->matrix[2][aIndex] = a->matrix[2][aIndex] + b->matrix[2][bIndex];
        }

    }
    while(a->matrix[0][aIndex] < b->matrix[0][bIndex])
    {


    }


    while(aIndex < a->msize){


        bIndex = 0;
        ++aIndex;
    }
}
