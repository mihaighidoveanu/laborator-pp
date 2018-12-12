#include <stdio.h>
#include <stdlib.h>

#include "bdims.h"

int** new_matrix(int rows, int cols){
    int **m = malloc(sizeof(int*) * rows);
    if(m == NULL){
        return NULL;
    }
    for(int i = 0; i < rows; ++i){
        m[i] = malloc(sizeof(int) * cols);
        if(m[i] == NULL){
            // free all the columns that succeeded in allocation
            for(int j = 0; j < i; ++j){
                free(m[j]);
            }
            // free the array of columns
            free(m);
            return NULL;
        }
    }
    return m;
}

void print_matrix(int** matrix, int rows, int cols){
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void free_matrix(int **matrix, int cols){
    for(int i = 0; i < cols; ++i){
        if(matrix[i] != NULL){
            free(matrix[i]);
        }
    }
    if(matrix != NULL){
        free(matrix);
    }
}

void ex1(){
    int n;
    scanf("%d",&n);

    int** m1 = new_matrix(n, n);
    if(m1 == NULL){
        printf("Eroare la alocare\n");
        return;
    }
    for(int i =0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            scanf("%d",&m1[i][j]);
        }
    }
    printf("Matricea 1 : \n");
    print_matrix(m1,n, n);
    int** m2 = new_matrix(n, n - 1);
    if(m2 == NULL){
        printf("Eroare la alocare\n");
        return;
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i == j){
                continue;
            }
            // if we reached elements aboce the first diagonal, subtract 1 from the col index
            if(j > i){
                m2[i][j - 1] = m1[i][j];
            }
            else{
                m2[i][j] = m1[i][j];
            }
        }
    }
    printf("Matricea 2 : \n");
    print_matrix(m2,n, n - 1);
}

void ex2(){
    int n;
    scanf("%d",&n);

    int **m = malloc(sizeof(int*) * n);
    if(m == NULL){
        return;
    }
    for(int i = 0; i < n; ++i){
        m[i] = malloc(sizeof(int) * (i + 1));
        if(m[i] == NULL){
            // free tje columns that succeded in allocation
            for(int j = 0; j < i; ++j){
                free(m[j]);
            }
            // then free the array of columns
            free(m);
            return;
        }
    }
    // fill the last row
    for(int col = 0; col < n; ++col){
        m[n-1][col] = col + 1;
    }
    // fill the first column
    for(int row = 0; row < n - 1; ++row){
        m[row][0] = n - row;
    }
    //fill the rest of the matrix
    // it is important to iterate from south-north and west-east
    // because to compute a value, we need the element at south and the element at west
    for(int row = n - 2; row >= 1; --row){
        for(int col = 1; col <= row; ++col){
            m[row][col] = m[row][col - 1] + m[row + 1][col];
        }
    }

    for(int row = 0; row < n; ++row){
        for(int col = 0; col <= row; ++col){
            printf("%d ", m[row][col]);
        }
        printf("\n");
    }
}

int main()
{
    // ex. 3
    int rows;
    int** m = new_bdim("siruri.txt", &rows);
    print_bdim(m, rows);
    sort_bdim(m, rows);
    print_bdim(m, rows);
    int* a = malloc(sizeof(int) * 4);
    if(a == NULL){
        return 0;
    }
    int* b = malloc(sizeof(int) * 4);
    if(b == NULL){
        return 0;
    }
    for(int i = 0; i < 4; ++i){
        b[i] = i;
        a[i] = i + 1;
    }
    merge_arrays(&a, 4, b ,4);
    for(int i = 0; i < 8; ++i){
        printf("%d ",a[i]);
    }

    /* This doesn't work completely for now
    merge_rows(m, rows);
    for(int i = 1; i < m[0][0]; ++i){
        printf("%d ",m[0][i]);
    }
    */
    free_bdim(m, rows);
    return 0;
}
