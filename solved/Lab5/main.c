#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "BigNumbers.h"
#include "Matrix.h"
#include "Utils.h"


int shared_elements(){
    int m,n;
    int fr[4001];
    scanf("%d %d",&m, &n);
    int i = 0;
    for(i = 0; i < 4000; ++i){
        fr[i] = 0;
    }
    //read A set
    for(i = 0; i < m; ++i){
        int Aelem;
        scanf("%d",&Aelem);
        ++fr[Aelem + 2000];
    }
    unsigned no = 0;
    //read  B set and check for shared elements
    for(i = 0;i < n; ++i){
        int Belem;
        scanf("%d",&Belem);
        if(fr[Belem + 2000]){
            ++no;
            fr[Belem + 2000] = 0;
        }
    }

    return no;
}

#define MAX_SIZE 30

int main()
{   
    int no1[MAX_SIZE] = {-1, 2, 2};
    int no2[MAX_SIZE] = {2, 0, 0};
    int result[MAX_SIZE];
    //int rsize = _sum(no1,5,no2,5,result);
    int rsize = sum(no1, 3, no2, 3, result);
    print_arr(result,rsize);

    int no = shared_elements();
    printf("\n Shared : %d ",no);
    return 0;
}
