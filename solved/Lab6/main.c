#include <stdio.h>
#include <stdlib.h>

#include "ex1.h"
#include "ex2.h"
#include "ex3.h"
#include "students.h"


void pb1(){
    const int no_numbers = 10;
    FILE *fout;
    fout = fopen("date.bin","w+b");
    if(fout == NULL){
        printf("Eroare la citirea fisierului");
        return;
    }

    // generate and write the numbers
    int n;
    printf("Dati n \n");
    scanf("%d",&n);
    //generate_numbers(fout,NO_NUMBERS,n);
    fseek(fout,0L,SEEK_SET);
    int i;
    for(i = 0;i < no_numbers; ++i){
        int random = rand();
        int number = random % (2 * n + 1)  - n;
        fwrite(&number,sizeof(int),1,fout);
    }
    printf("Numbers : ");
    show_numbers_from_file(fout);

    // sort
    sort_file(fout);
    printf("Sorted : ");
    show_numbers_from_file(fout);

    // get maximum and its frequency
    int freq, max;
    find_frequency_of_max(fout, &max, &freq);
    printf("Max : %d, appears %d times" , max, freq);

    fflush(fout);
    fclose(fout);
}



void pb2(){
    printf("Se citeste din numere_intregi.txt \n");
    FILE* fin;
    fin = fopen("numere_intregi.txt","r");
    if(fin == NULL){
        printf("Eroare la deschiderea fisierului text\n");
        return ;
    }
    int n;
    fscanf(fin, "%d ",&n);
    FILE *bin_poz, *bin_neg;
    bin_poz = fopen("bin_poz.bin","w+b");
    bin_neg = fopen("bin_neg.bin","w+b");
    if(bin_neg == NULL || bin_poz == NULL){
        printf("Eroare la deschiderea fisierelor binare\n");
        return;
    }
    split_by_sign(n, fin, bin_poz, bin_neg);
    printf("Pozitive : ");
    show_numbers_from_file(bin_poz);
    printf("Negative : ");
    show_numbers_from_file(bin_neg);

}

void pb3(){
    printf("\n---ex2.h with comments : \n");
    print_source("ex2.h");
    printf("\n===================================\n");
    printf("--ex2.h without comments :\n");
    source_without_comments("ex2.h");
}


void pb4(){
    printf("Dati numarul studentilor \n");
    int n;
    scanf("%d", &n);
    printf("Dati %d studenti de la tastatura \n", n);
    creare("students.bin",n);
    printf("\nStudentii sunt : \n");
    afisare("students.bin","students.txt");
    struct student x = {1021, "Tudor" , "Chirila", 7.8};
    printf("\nSe adauga studentul %d %s %s %f \n", x.id, x.nume, x.prenume, x.nota);
    adaugare("students.bin",x);
    printf("\nStudentii sunt : \n");
    afisare("students.bin","students.txt");
    printf("\nSe modifica studentul cu id-ul 1021. I se da nota 10\n");
    modificare("students.bin",1021,10);
    printf("\nStudentii sunt : \n");
    afisare("students.bin","students.txt");

}

void print_menu(){
    printf("\nAlegeti o optiune : \n");

    printf("1. Generare numere aleatoare. Sortarea lor. Afisarea maximului \n");
    printf("2. Separarea numerelor pozitive de negative\n");
    printf("3. Eliminarea comentariilor\n");
    printf("4. Exercitii cu studenti\n");
    printf("0. Exit\n");

}

int main()
{
    int option;
    do{
        print_menu();
        scanf("%d",&option);
        switch(option){
        case 1:
            pb1();
            break;
        case 2:
            pb2();
            break;
        case 3:
            pb3();
            break;
        case 4:
            pb4();
            break;
        case 0:
            break;
        default:
            printf("Alegeti o optiune valida\n");
        }
    }while(option);


    return 0;
}
