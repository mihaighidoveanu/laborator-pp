# Lab 10 - Dinamically allocated arrays and matrices

## Realloc function

```c
// we allocate here a matrix of 2 lines and 4 columns
int **m = (int**)malloc(sizeof(int*) * 2);
for(int i = 0; i < 2; ++i){
	m[i] = (int*)malloc(sizeof(int) * 4);
	m[i][0] = 2;
}
// later in our program, we decide we want 4 lines
m = realloc(m, sizeof(int*) * 4);
printf("%d",m[0][0]); // ---> OUTPUT : 2 ; the old data is kept !!!!!!!!!!!
```

Important to notice is that **realloc** keeps our old lines in the array. From the function's documentation, **realloc** works in two possible ways:
```c 
void *realloc( void *ptr, size_t new_size ) 
```
1. allocating a new memory block of size new_size bytes, **copying memory area** with size equal the lesser of the new and the old sizes, and freeing the old block.
2. expanding or contracting the existing area pointed to by ptr, if possible. The contents of the area remain unchanged up to the lesser of the new and old sizes. If the area is expanded, the contents of the new part of the array are undefined.
