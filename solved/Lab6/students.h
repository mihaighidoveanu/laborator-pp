#ifndef STUDENTS_H_INCLUDED
#define STUDENTS_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "ex1.h"

struct student {
    int id;
    char nume[21];
    char prenume[21];
    float nota;
};

struct student citeste_student();
void creare(char *nume_fisier_binar, int n);
void afisare (char *nume_fisier_binar, char *nume_fisier_text);
void modificare (char *nume_fisier_binar, int id, float nota);
void adaugare (char *nume_fisier_binar, struct student);


#endif // STUDENTS_H_INCLUDED
