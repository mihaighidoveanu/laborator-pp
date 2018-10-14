# Lab 1 
## Structs, scanf, printf and bitwise operators

## Structs
In C language, if we want to declare a variable of a structure type, we need to declare it like this :

``` 
struct Solutie {
    int x1, x2;
};
struct Solutie x; 
``` 

But for brevity and clarity, we can use *typedef* keyword to make an alias for a certain data type.
``` 
typedef struct Solutie Solutie;
Solutie x;
``` 
This way, *struct Solutie* type gets the name of *Solutie*.

For even more brevity,these are two ways to declare a struct type with an alias :

``` 
struct Solutie {
    int x1, x2;
};
typedef struct Solutie Solutie;
Solutie x;
``` 
```
typedef struct Solutie {
	int x1, x2;
} Solutie;
Solutie x;

```

## Byte operations

Because byte operators work on the underlying representation of integers, the way they works depend on the compiler implementation.
As such, applying bitwise operators on signed integers can cause unexpected results because of the way compilers action on the bit sign.
Thus, it is best to use unsigned integers with the bitwise operators.

#### The Microsoft C compiler documentation says that:
Bitwise operations on signed integers work the same as bitwise operations on unsigned integers.

### On-line GCC documentation about the implementation of bitwise operations on signed integers says:
Bitwise operators act on the representation of the value including both the sign and value bits, where the sign bit is considered immediately above the highest-value value bit.

You can find examples and more information [here](https://wiki.sei.cmu.edu/confluence/display/c/INT13-C.+Use+bitwise+operators+only+on+unsigned+operands) .


