#include "cod.h"

int is_prime(int x){
    int rad = sqrt(x);
    int prime = 1;
    for(int i = 2; i <= rad; ++i){
        if(x % i == 0){
            prime = 0;
            break;
        }
    }
    return prime;
}

int nearest_prime(int n){
    int prime;
    for(int i = n - 1; i >= 2; ++i){
        if(is_prime(i)){
            prime = i;
            break;
        }
    }
    int limit = n * n;
    int big_prime;
    for(int i = n; i <= limit; ++i){
            if(is_prime(i)){
                big_prime = i;
                break;
            }
    }
    if(prime - n < big_prime - n){ //if the smaller prime is closer
        return prime;
    }
    else{
        return big_prime;
    }
}

int sumad(int x){
    int sum = 1;
    int limit = x / 2;
    for(int i = 2; i <= limit; ++i){
        if(x % i == 0){
            sum += i;
        }
    }
    return sum;
}

int is_munte(int x){
    int munte = 0;
    if(x / 100 == 0){
        return 0;
    }
    int ld = x % 10;
    x /= 10;
    int lld = x % 10;
    x /= 10;
    if(lld < ld){
        return 0;
    }
    while(x != 0){
        ld = lld;
        lld = x % 10;
        x /= 10;
        if(!munte && lld < ld){
            munte = 1;
        }
        if(munte && lld > ld){
            return 0;
        }
    }
    return munte;
}

int count_digits(int x){
    int count = 0;
    while(x != 0){
        ++count;
        x /= 10;
    }
    return count;
}

void split_in_numbers( long long x, int* odds, int* evens){
    //int count = count_digits(x);
    (*odds) = 0;
    (*evens) = 0;
    int digits[15];
    //keep all the digits in an array because
    // we need to construct the numbers with digits from left to right
    // but we compute the digits from right to left
    for(int i = 0; i < 15; ++i){
        digits[i] = -1;
    }
    // compute the digits
    int index = 0;
    while(x != 0 && index < 15){
        digits[index] = x % 10;
        x /= 10;
        ++index;
    }
    // find the leftmost digit a.k.a the most important digit of the number
    int first_digit_index = 15 - 1;
    while(digits[first_digit_index] == -1){
        --first_digit_index;
    }
    // construct the numbers starting from the leftmost digit
    for(int i = first_digit_index; i >= 0; --i){
        int digit_index = first_digit_index + 1 - i;
        if(digit_index % 2 == 0){ // if even
            (*evens) *= 10;
            (*evens) += digits[i];
        }
        else{   // if odd
            (*odds) *= 10;
            (*odds) += digits[i];
        }
    }
}


int cifra(int n, char digit){

    int digits[9];

    for(int i = 0; i < 9; ++i){
        digits[i] = -1;
    }

    int i = 0;
    while(n != 0){
        int ld = n % 10;
        n /= 10;
        if(ld != digit){
            digits[i] = ld;
        }
        ++i;
    }

    int new_n = 0;
    for(int i = 9 - 1; i >= 0; --i){
        if(digits[i] != -1){
            new_n *= 10;
            new_n += digits[i];
        }
    }

    return new_n;
}


void circular_right(int* arr, int n, int m){
    int aux[m];
    for(int i = 0; i < m; ++i){
        aux[i] = arr[n - m + i];
    }
    // copy first m elements over the last m elements
    for(int i = n - 1; i >=  m; --i){
        arr[i] = arr[i - m];
    }

    //copy the last m elements in the front    for(int i = 0; i < m; ++i){
        arr[i] = aux[i];
    }

}

void fizz_buzz(int n){
    for(int i = 1; i <= n; ++i){
        int fizzbuzzing = 0;
        if(i % 3 == 0){
            printf("Fizz");
            fizzbuzzing = 1;
        }
        if(i % 5 == 0){
            printf("Buzz");
            fizzbuzzing = 1;
        }
        if(!fizzbuzzing){
            printf("%d", i);
        }
        printf(" ");
    }

}

