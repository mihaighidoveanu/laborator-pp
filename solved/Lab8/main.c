#include <stdio.h>
#include <stdlib.h>

int is_little_endian(){
    int x = 1;
    char *ptr = (char*)&x;
    return *ptr;
}

void pb1(){
    if(is_little_endian()){
        printf("Little Endian\n");
    }
    else{
        printf("Big Endian\n");
    }
}

void pb2(){
    int x = -10;
    unsigned char *ptr = (unsigned char *)&x;
    if(is_little_endian()){
        printf("Little Endian : \n");
        // the octet with the sign bit will be the last, the rest will be printed as unsigned chars
        for(int i = 0; i < sizeof(x) - 1; ++i){
            printf("%d ", *ptr);
            ++ptr;
        }
        printf("%d ", (char) (*ptr));
    }
    else {
        printf("Big Endian : \n");
        // the octet with the sign bit will be the first, the rest will be printed as unsigned chars
        printf("%d ", (char) (*ptr));
        ++ptr;
        for(int i = 1; i < sizeof(x); ++i){
            printf("%d ", *ptr);
            ++ptr;
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int matrix[n][n];
    /*int **matrix = (int**)malloc(sizeof(int*) * n);
    if(!matrix){
        printf("Eroare la alocarea memoriei\n");
        return 0;
    }
    for(int i = 0; i < n; ++i){
        matrix[i] = (int*)malloc(n * sizeof(int));
        if(!matrix[i]){
            printf("Eroare la alocarea memoriei\n");
        }
    }*/
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < n; ++j){
            scanf("%d", &(matrix[i][j]));
        }
    }
    int *ptr = (int*)matrix;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n ; ++j){
            printf("%d ",*ptr);
            ++ptr;
        }
    }
    return 0;
}
