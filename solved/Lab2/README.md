# [Lab 2](https://github.com/Mihaaai/laborator-pp/blob/master/labs/Lab2.docx)
## Byte operations

## Binary representation of an integer

IDT = Integer Data Type. In this case, IDT refers to the data type of x, the integer we want to make the binary represantion for.
We will use a bit mask:
	We shift a 1 to the left with as many positions as the dimension in bits of x's type.
	This is 8 * sizeof(IDT), becase sizeof gives us size of the type in bytes, and we know one byte occupies 8 bits.
Then we will do binary and (&) between x and the above created mask to obtain the most left bit of x.
If we shift the mask to the right with 1 position and apply the same operation as aboce, we can obtain the bit right to the leftmost bit of x.
We can repeat these two operations until we will obtain the rightmost bit of x. And at this stage, we got all of x's bits from left to right.

```c
unsigned long long m = 1ULL << (8*sizeof(ITD)-1);
unsigned char b;
for(b = 0; b < 8*sizeof(ITD); b++)
{
printf("%u" , (x & m) != 0);
m = m >> 1;
}
```
Quick note :
> Bits are usually ordered from right to left
---------------------------
| Bit   | 7 6 5 4 3 2 1 0 |
| x     | 0 1 0 1 1 1 0 1 |
| m     | 0 0 0 0 1 0 0 0 | 
| x & m | 0 0 0 0 1 0 0 0 |
---------------------------
