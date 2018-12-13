#ifndef BDIMS_H_INCLUDED
#define BDIMS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** new_bdim(const char* filename, int* rows);
void print_bdim(int** m, int rows);
void free_bdim(int** m, int rows);
void sort_bdim(int** m, int rows);
void merge_arrays(int** a, int m, int* b, int n);
void merge_rows(int** m, int* rows);

#endif // BDIMS_H_INCLUDED
