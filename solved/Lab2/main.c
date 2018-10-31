#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void to_binary(unsigned int x)
{
    if(x != 0)
    {
        to_binary(x >> 1);
        printf("%d",x & 1);
    }
}

unsigned int nth_byte_of_x(unsigned int x, unsigned int n)
{
    return (x >> (n - 1)) & 1U;
}

int set_nth_byte_of_x(int x,  int n)
{
    unsigned mask = 1U << (n-1);
    x = x | mask;
    return x;
}

int delete_nth_byte_of_x(int x,  int n)
{
    unsigned mask = ~(1U << (n-1));
    x &= ~mask;
    return x;
}

int complement_nth_byte_of_x(int x,  int n)
{
    return x ^(1U << (n-1));
}


void bytes_operations(int x,  int n)
{
    assert(0 <= n && n <= 15);
    printf("\nBitul %d din x : %d",n,nth_byte_of_x(x,n));
    printf("\nAm setat bitul %d din x : %d",n,set_nth_byte_of_x(x,n));
    printf("\nAm sters bitul %d din x : %d",n,delete_nth_byte_of_x(x,n));
    printf("\nAm complementat bitul %d din x : %d",n,complement_nth_byte_of_x(x,n));

}

int copy_bytes(int x,int p, int n,int y)
{
    unsigned mask = (1 << n) - 1;
    unsigned mask_starting_at_p = mask << (p - n);
    unsigned x_with_zeroes = x & ~mask_starting_at_p;
    unsigned y_with_zeroes = y & mask;
    return x_with_zeroes | y_with_zeroes;
}

void binary_to_hex(char* binary,char* hex)
{
    unsigned int num = 0;
    char* bin = binary;
    for(; *bin != '\0'; ++bin)
    {
        unsigned char b = (*bin == '1') ? 1 : 0;
        num = (num << 1) | b;
    }
    sprintf(hex,"%08X", num);
}

/* Not working at the moment */
void hex_to_binary(char* hex, char* binary)
{
    const char bin_dict[16][5] = {"0000", "0001", "0010", "0011",
                                  "0100", "0101", "0110", "0111",
                                  "1000", "1001", "1010", "1011",
                                  "1100","1101","1110","1111"
                                 };
    const char* hex_digits = "0123456789abcdef";
    int index = 0;
    binary = "";
    char* c = hex;
    while(c)
    {
        char* char_found = strchr(hex_digits,*c);
        int index_of_bin = char_found - hex_digits;
        strcat(binary,bin_dict[index_of_bin]);
        ++c;
    }
    binary[index] = '\0';
}

int sum_of_digits(int x)
{
    int sum  = 0 ;
    while(x)
    {
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}


void compute_pairs()
{
    int a,b;
    scanf("%d",&a);
    if(a == 0)
    {
        return;
    }
    while(1)
    {
        scanf("%d",&b);
        if(b == 0)
        {
            break;
        }
        if(a % sum_of_digits(a) == b)
        {
            printf("(%d, %d) ",a,b);
        }
        a = b;
    }
}


void set_bit_n(int n,int* x)
{

    (*x) |= (1<<(n - 1));

}



int main()
{
    /// operatii pe biti
    to_binary(5);
    bytes_operations(5,3);
    printf("\n%d\n",copy_bytes(8,2,2,5));
    printf("\n");

    /// binar - hexazecimal
    printf("Introduceti un numar in binar\n");
    char binary[33],hex[9];
    scanf("%s",binary);
    binary_to_hex(binary,hex);
    printf("%s\n",hex);
    //hex_to_binary(hex,binary);
    //printf("%s\n",binary);

    /// perechi de numere
    printf("Se citesc numere pana se citeste un 0\n");
    compute_pairs();


    return 0;
}
