#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "cod.h"
#include "SparseMatrix.h"

void p1(){
    char c = getchar();
    putchar(to_lower(c));
    printf("\n");
}

void p2(){
    int a,b;
    char op;
    scanf("%d %c %d",&a,&op,&b);
    int result = compute(a,b,op);
    if(result == INT_MAX){
        printf("Nu se poate imparti la 0.");
    }
    else
        if(result == INT_MIN) {
            printf("Trebuie sa alegeti unul din operatorii (+, -, *, /, %%).");
        }
        else {
            printf("Valoarea este %d",result);
        }
}

void p3(){
    unsigned int n;
    printf("Dati numarul de studenti : \n");
    scanf("%d",&n);
    printf("Dati studentii :\n");
    Student arr[n];
    int i;
    for(i = 0;i < n;++i){
        read_candidate(arr,i);
    }
    buget_partition_candidates(arr,n);
    unsigned choice;
    do{
        choice = show_candidates_with_menu(arr,n);
    }while(choice);
}

void p4() {
    SparseMatrix a,b;
    unsigned msize;
    printf("Numarul de elemente nenule ale matricei : \n");
    scanf("%d",&msize);
    a.msize = msize;
    b.msize = msize;
    printf("Introduceti elementele matricei A : linie coloana element  \n");
    readMatrix(&a);
    printf("\nIntroduceti elementele matricei B : linie coloana element \n");
    readMatrix(&b);
    printf("\nMatricea A : ");
    printMatrix(a);
    printf("\nMatricea B : ");
    printMatrix(b);

/* Not working at the moment
    SparseMatrix sumMatrix;
    sumMatrix.msize = msize;
    sum(&a,&b,&sumMatrix);
    */
}

int main()
{
    p3();
    return 0;
}
