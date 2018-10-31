#ifndef COD_H_INCLUDED
#define COD_H_INCLUDED

#include <limits.h>
#include <string.h>
#include <stdio.h>
#include "cod.h"

#define PRAG_MINIM 5
#define MEDIA_ADMITERE(student){\
student.medie = 8.0 / 10 * (student.nota_mate + student.nota_info) / 2 + 2.0 / 10 * student.nota_bac; \
}

typedef struct Student{
    char nr_legitimatie[5];
    char nume[31];
    float nota_mate, nota_info, nota_bac;
    float medie;
    int admis, buget;
} Student;

char to_lower(char c);
int compute(int a, int b, char op);
void replace_newline_with_null(char* str);
void read_candidate(Student* arr,unsigned int array_size);
void buget_partition_candidates(Student* arr, unsigned int array_size);
int show_candidates_with_menu(Student* arr, unsigned array_size);
void print_candidate(Student x);
void swap_students(Student *x, Student *y);

/// privates :
// int binary_search_students(Student* arr, unsigned int l, unsigned int r, const char* nume);
// int find_student_by_name(Student* arr,unsigned int array_size, const char* nume);

#endif // COD_H_INCLUDED
