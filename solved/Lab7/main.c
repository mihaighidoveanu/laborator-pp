#include <stdio.h>
#include <stdlib.h>

#include "cod.h"

void pb2(){
    int n;
    scanf("%d" , &n);
    for(int a = 1; a <= n; ++a){
        for(int b = a + 1; b <= n; ++b){
            if(a != b){
                int sa = sumad(a);
                int sb = sumad(b);
                if(a == sb || sa == b){
                    printf(" (%d, %d) ", a, b);
                }
            }
        }
    }
}

void pb3(){
    int a, b;
    scanf("%d %d",&a, &b);
    for(int no = a; no <= b; ++no){
        if(is_munte(no)){
            printf("%d ",no);
        }
    }
}

void pb4(){
    int odds, even;
    long long x;
    scanf("%lld", &x);
    split_in_numbers(x,&odds, &even);
    printf("%d, %d", odds, even);
}


int main()
{
    //printf("%d", nearest_prime(5000));
    //pb2();
    //printf("%d",is_munte(12342));
    //pb4();
    //printf("%d", cifra(929319,9));
    /*int arr[20] = {1,2,3,4,5};
    int n = 5;
    circular_right(arr,5,2);
    for(int i = 0; i < n; ++i){
        printf("%d ",arr[i]);
    }
    printf("\n");*/
    fizz_buzz(100);


    return 0;
}
