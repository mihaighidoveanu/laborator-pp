int binary_search(int* arr, int val, unsigned a_size){
    int low = 0;
    int high = a_size - 1;

    while(low <= high){
        int mid = low + (high - low) / 2; // (high + low) / 2, but avoiding overflow when doing sums
        int midVal = arr[mid];

        if (midVal < val){
            low = mid + 1;
        }
        else if (midVal > val) {
            high = mid - 1;
            }
        else{
            return mid; // val found
        }
    }
    return -1;  // val not found.
}

void swap(int* a, int* b){
    int temp = (*a);
    (*a) = (*b);
    (*b) = temp;
}

void reverse_arr(int* x, unsigned a_size){
    int left = 0, right = a_size - 1;

    while (left < right){
        swap(&x[left], &x[right]);
        ++left;
        --right;
    }

}

// Function to print the matrix
void displayMatrix(int **mat, unsigned rows, unsigned columns)
{
    int i,j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
            printf("%2d ", mat[i][j]);

        printf("\n");
    }
    printf("\n");
}

void print_arr(int* x, unsigned a_size){
    int i = 0;
    for(;i < a_size; ++i){
        printf("%d ",x[i]);
    }
    printf("\n");
}
