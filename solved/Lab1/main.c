#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_equation(float a, float b, float c) {
    if(a != 1)
        printf("%.1fx^2 ",a);
    else
        printf("x^2 ");
    if(b < 0)
        printf(" %.1fx ", b);
    else
        printf(" + %.1fx ", b);
    if(c < 0)
        printf(" %.1f ", c);
    else
        printf(" + %.1f ", c);
    printf(" = 0\n");

}

void equation(float a, float b, float c) {
    float delta = b * b - 4 * a * c;
    if(delta < 0) {
        printf("Delta negativ \n");
    }
    else if(delta == 0) {
            printf("x = %f \n", - b / (2 * a));
        }
        else {
            float x1 = (- b + sqrt(delta) ) / (2 * a);
            float x2 = (- b - sqrt(delta) ) / (2 * a);
            printf("x1 = %f; x2 = %f \n",x1,x2);
        }
}


int max_of_three(int a, int b, int c) {
    int max_of_two = (a > b) ? a : b;
    int max_of_three = (max_of_two > c ) ? max_of_two : c;
    return max_of_three;
}

void bytes(int n) {
    printf("%d * 8 = %d \n",n, n << 3 );
    printf("%d / 4 = %d \n",n, n >> 2 );
    printf("%d * 10 = %d \n",n, (n << 3) + (n << 1)  );
}

int is_par(int n) {
    return !(n & 1);
}

int main()
{
    /*
    int a = 1, b = -3, c = 1;
    printf("a) \n");
    printf("%+f, ")
    print_equation(a, b, c);
    equation(a, b, c);
    printf("\nb) \n");
    int x = -10, y = -22, z = 0;
    printf("Max of %d, %d, %d: %d \n",x, y, z, max_of_three(x, y, z));
    printf("\nc) \n");
    int n;
    printf("Introdu un intreg de la tastatura : \n");
    scanf("%d",&n);
    bytes(n);
    printf("\nd) \n");
    if(is_par(n))
        printf("%d e par ",n);
    else
        printf("%d nu e par",n);
    */
    int a,b,c;
    scanf("%d,%d, %d",&a,&b,&c);
    printf("%d %d %d",a,b,c);
    return 0;


}
