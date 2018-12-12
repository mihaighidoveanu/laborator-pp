#include "bdims.h"

/// creates a new bidimensional structure a.k.a matrix with elements read from a file
int** new_bdim(const char* filename, int* rows){
    FILE* fin = fopen(filename,"r");
    if(fin == NULL){
        printf("Eroare la deschiderea fisierului siruri.txt\n");
        return 0;
    }
    // Because we don't know the number of lines our matrix will have,
    //      we will realocate our matrix on the run
    // We won't reallocate everytime we see a new line because that's inneficient.
    // Instead, we will allocate a buffer of, let's say, 4 lines at the start.(You could choose any number here)
    // And then, when we reach our 5th line, we double our dimension so our matrix can now hold up to 8 lines.
    // When we reach the 9th line, we do the same and double our matrix to 16 lines. And so on, and so forth.
    int no_rows = 4;
    int** m = malloc(sizeof(int*) * no_rows);
    if(m == NULL){
        printf("Eroare la alocarea initiala\n");
        return 0;
    }
    // we start with a current row at index 0
    int current_row = 0;
    while(1){
        // read the number of columns of current line
        int cols;
        fscanf(fin, "%d", &cols);

        // check for eof after read
        if(feof(fin)){
            break;
        }

        // realloc number of rows if necessary
        // e.g. we have no_rows = 4 and current_row reaches 4,
        //          it exceeded the available index because arrays are indexed from 0.
        //          So we need to add some more lines.
        if(current_row > no_rows - 1){
            // create a new matrix with double the number of lines
            // remember that our matrix is an array of pointers
            int** new_m = malloc(sizeof(int*) * no_rows * 2 );
            //check if raellocation succeeded
            if(new_m == NULL){
                break;
            }
            // and assign the new pointers to the old matrix lines
            /// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            // that's how we add more lines and keep the same memory for the elements
            for(int i = 0; i < no_rows; ++i){
                new_m[i] = m[i];
            }
            // update the variable holding the number of lines
            no_rows *= 2;
            // free the old array of pointers to lines
            free(m);
            // give the new array of pointers to lines the same old name m
            m = new_m;
        }
        // for the current row,
        //      allocate the number of columns + 1 (+ 1 for inserting the line size)
        m[current_row] = malloc(sizeof(int) * (cols + 1));

        // check if allocation failed
        if(m[current_row] == NULL){
            printf("Eroare la alocarea liniei %d", current_row);
            // if allocation failed for this row, we must also free the rows that succeeded
            for(int i = 0; i < current_row; ++i){
                free(m[i]);
            }
            // now free the pointer to the matrix (the pointer to the pointers to lines)
            free(m);
            // return a null pointer to let the outside world know that we failed
            return NULL;
        }
        // add the size to the line
        m[current_row][0] = cols;

        // read the column elements from file
        for(int i = 1; i <= cols; ++i){
            fscanf(fin, "%d",&m[current_row][i]);
        }

        //move to the next row
        ++current_row;
    }
    // output the number of rows through the rows parameter
    (*rows) = current_row;

    // return the matrix
    return m;
}

/// prints a bidimensional structure
void print_bdim(int** m, int rows){
    for(int i = 0; i < rows; ++i){
        // we have the size of the line as the first element of the current line
        for(int j = 1; j <= m[i][0]; ++j){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/// function to free a bidimensional structure
void free_bdim(int** m, int rows){
    // extra check for extra safety reasons
    // if someone calls our function with an already freed pointer
    if(m == NULL){
        return;
    }
    // free all the rows
    for(int i = 0; i < rows; ++i){
        //if some of the rows were freed or not initialized at all before
        if(m[i] != NULL){
            free(m[i]);
        }
    }
    //then free the array of rows
    free(m);
}

/// function to compare two integers as in x < y : necessary for qsort
int lesser_than(const void* p1, const void* p2){
    int v1 = *(int*)p1;
    int v2 = *(int*)p2;
    if( v1 > v2){
        return 1;
    }
    if( v1 < v2 ){
        return -1;
    }
    return 0;
}


/// function to compare two rows based on their size
int rows_by_size_asc(const void* p1, const void* p2){
    // p1 is a pointer to a row(an int*). So p1 is an int**.
    // so we cast p1 to an (int**) then take it's value with '*' to take the address of a row.
    int* row1 = *(int**)p1;
    int* row2 = *(int**)p2;
    int rs1 = row1[0]; //size of row 1
    int rs2 = row2[0]; //size of row 2
    if(rs1 > rs2){
        return 1;
    }
    if(rs1 < rs2){
        return -1;
    }
    return 0;
}

/// function to sort the matrix : each row with elements sorted in ascending order
///                             : rows sorted by size in ascending order
void sort_bdim(int** m, int rows){
    for(int i = 0; i < rows; ++i){
        // we start qsort from m[i] + 1, that is &m[i][1].
        // We do that so we don't sort the first element too (the first element is the size of the line)
        qsort(m[i] + 1, m[i][0], sizeof(int), lesser_than);
    }
    qsort(m, rows, sizeof(int*), rows_by_size_asc);
}

/// Function to merge two arrays sorted in ascending order
/// We keep the result in the first array and free the second
/// The result will always be size m + n, because of the merge algorithm
/// @param a : Our first parameter is a pointer to an array (and an array is a pointer to int).
///          That is because :
///                 - We want to reallocate the array, so we need to change it's pointer value
///                 - And to change the pointer's value AND see the change outside this function,
///                     we need to pass to the function the pointer's address and use it to modify the value at that address.
///                                                           (That is, the pointer's value. The starting addres of our array)
///                 - So we need to pass a pointer to our array. So a pointer to a pointer to int.
void merge_arrays(int** a, int m, int* b, int n){
    int* sorted = malloc(sizeof(int) * (m + n));
    if(sorted == NULL)
    {
        return;
    }
    // this is merge sort algorithm taken from
    // https://www.geeksforgeeks.org/merge-two-sorted-arrays/
    int i, a_index, b_index;
    a_index = b_index = 0;
    for (i = 0; i < m + n;){
        if (a_index < m && b_index < n){
            if ( (*a)[a_index] < b[b_index]){
                sorted[i] = (*a)[a_index];
                a_index++;
            }
            else{
                sorted[i] = b[b_index];
                b_index++;
            }
            i++;
        }
        else{
            if (a_index == m){
                for (; i < m + n;){
                    sorted[i] = b[b_index];
                    b_index++;
                    i++;
                }
            }
            else{
                for (; i < m + n;){
                    sorted[i] = (*a)[a_index];
                    a_index++;
                    i++;
                }
            }
        }
    }
    // free the second array
    free(b);
    // free tje first array
    free(*a);
    // keep the allocated new array as the first one
    // we use '*a' because a is 'int**' and we need to put 'sorted' into an 'int*'.
    (*a) = sorted;
}


// this doesn't work completely for now
void merge_rows(int** m, int rows){
    int* first_row = m[0] + 1;
    for(int i = 1; i < rows; ++i){
        int* row = m[i] + 1;
        merge_arrays(&first_row, m[0][0], row, m[i][0]);
        m[0][0] += m[i][0];
        printf("After %d merge - %d elements \n", i, m[0][0]);
        for(int i = 0; i < m[0][0]; ++i){
            printf("%d ", first_row[i]);
        }
        printf("\n");
        free(m[i]); // we freed the row content, but here we also free the element with the size of the row
    }
    int new_row_size = m[0][0];
    m[0] = realloc(m[0], sizeof(int) * (new_row_size + 1));
    if(m[0] == NULL){
        return;
    }
    m[0][0] = new_row_size;
    memcpy(m[0] + 1, first_row, sizeof(int) * new_row_size);
    free(first_row);
}
