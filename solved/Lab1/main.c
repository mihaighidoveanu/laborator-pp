#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
* Represents the solution of a second degree equation of the form a * x^2 + b * x + c = 0
* @members float x1, float x2 : equation's solutions
*   - solutions are equal if equation's delta is 0
*   - solutions are different if equation's delta > 0
*   - if delta < 0, solutions are undefined and should not be used;
* @members int is_real : flag set to 1 (true) if solutions are not real and set to 0(false) otherwise
*   - One should check the flag is_real before using the struct's solutions, otherwise undefined values will occur
*/
typedef struct Solution  {
    int is_real;
    float x1, x2;
} Solution;
/* The above is equivalent to :
struct Solutie {
    int x1,x2;
}
typedef struct Solutie Solutie;
*/

/**
* Pretty prints an equation of second grade of the form a * x^2 + b * x + c = 0
* @params float a, float b, float c : parameters from the above second grade equation
* @return void; It prints to standard output;
*/
void print_equation(float a, float b, float c){
    if(a != 1)
        printf("%+.1f * x^2 ",a);
    else
        printf("x^2 ");
    if(b < 0)
        printf("%.1fx ", b);
    else
        printf("+ %.1f * x ", b);
    if(c < 0)
        printf("%.1f ", c);
    else
        printf("+ %.1f ", c);
    printf(" = 0\n");
}

/**
* Solves second degree equation of the form a * x^2 + b * x + c = 0, if it has real solutions
* @params float a, float b, float c : parameters from the second degree equation general form
* @return two float solutions  x1 and x2 as members of struct Solution, according to its documentation
*/
Solution solve_equation(float a, float b, float c) {
    float delta = b * b - 4 * a * c;
    Solution X;
    if(delta < 0){
        X.is_real = 0;
        return X;
    }
    else if(delta == 0) {
            X.x1 = X.x2 =  - b / (2 * a);
        }
        else {
            X.x1 = (- b + sqrt(delta) ) / (2 * a);
            X.x2 = (- b - sqrt(delta) ) / (2 * a);
        }
    X.is_real = 1;
    return X;
}

/**
* Computes the maximum of three integers, using only short-hand ifs
* @params int a, int b, int c : the integers to compute the maximum of
* @return the maximum of the three
*/
int max_of_three(int a, int b, int c) {
    int max_of_two = (a > b) ? a : b;
    int max_of_three = (max_of_two > c ) ? max_of_two : c;
    return max_of_three;
}

/**
* computes bytes operations and prints them on standard output
* @param unsigned int n : the integer we perform unsigned operations on
*        - because of differences is compiler's implementation,
*            it is the safest to do byte operations only on unsigned integers
* - it is important to notice that right shifting an odd integer will perform a 'div' operation, not an exact division
*/
void show_bytes_operations(unsigned int n) {
    printf("%d * 8 = %d \n",n, n << 3 );
    printf("%d / 4 = %d \n",n, n >> 2 );
    printf("%d * 10 = %d \n",n, (n << 3) + (n << 1)  );
}

/**
* checks if an integer is even or odd using only bitwise operators
* @param unsigned int n : the integer we check if it is even or odd
*        - because of differences is compiler's implementation,
*            it is the safest to do byte operations only on unsigned integers
*/
int is_even(unsigned int n) {
    return !(n & 1);
}

int main()
{
    int a,b,c;
    printf("Laboratorul 1\n");
    printf("Introduceti toate valorile cerute separate prin spatii, tab sau enter\n");
    /// a)
    printf("a) \n");
    printf("Introduceti parametrii intregi ai ecuatiei de gradul 2\n");
    scanf("%d %d %d",&a,&b,&c);
    print_equation(a, b, c);
    Solution X = solve_equation(a, b, c);
    if(X.is_real) {
        printf("x1 = %.2f, x2 = %.2f",X.x1, X.x2);
    }
    else{
        printf("Ecuatia nu are solutii \n");
    }
    /// b)
    printf("\nb) \n");
    int x,y,z;
    printf("Introduceti 3 intregi dintre care sa calculati maximul\n");
    scanf("%d %d %d",&x,&y,&z);
    printf("Max of %d, %d, %d -> %d \n",x, y, z, max_of_three(x, y, z));
    /// c)
    printf("\nc) \n");
    int n;
    printf("Introdu un intreg pozitiv de la tastatura : \n");
    scanf("%d",&n);
    show_bytes_operations(n);
    /// d)
    printf("\nd) \n");
    int m;
    printf("Introdu un intreg pozitiv de la tastatura : \n");
    scanf("%d",&m);
    if(is_even(m))
        printf("%d e par ",m);
    else
        printf("%d nu e par",m);
    return 0;
}
