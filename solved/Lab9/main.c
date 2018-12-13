#include <stdio.h>
#include <stdlib.h>

typedef struct Angajat{
    char cnp[14];
    char* name;
    int age;
    float salary;
} Angajat;

#define NAME_SIZE 20

void print_angajat(Angajat ang){
    printf("Angajatul %s - %s, %d ani, %.2f bani\n", ang.name, ang.cnp, ang.age, ang.salary);
}

int read_angajat(Angajat *ang){
    scanf("%13c",ang->cnp);
    ang->cnp[13] = '\0';
    scanf("%d",&(ang->age));
    scanf("%f ", &(ang->salary));
    ang->name = malloc(sizeof(char) * NAME_SIZE);
    if(ang->name == NULL){
        printf("Eroare la alocare \n");
        return 0;
    }
    fgets(ang->name,NAME_SIZE,stdin); //14 to include the newline also
    // remove the newline from the name
    for(int i = 0; i < NAME_SIZE; ++i){
        if(ang->name[i] == '\n'){
            ang->name[i] = '\0';
        }
    }
    return 1;
}

int save_angajati(){
    FILE* fout = fopen("angajati.bin", "w");
    if(fout == NULL){
        printf("Eroare la deschiderea fisierului angajati.bin\n");
        return 0;
    }
    printf("Numarul angajatilor : \n");
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        Angajat ang;
        read_angajat(&ang);
        fwrite(&ang,sizeof(ang),1,fout);
    }
    fclose(fout);
    return 1;
}


int show_angajat(const char* cnp){
    FILE* fin = fopen("angajati.bin","r");
    if(fin == NULL){
        printf("Eroare la deschiderea fisierului angajati.bin \n");
        return 0;
    }
    while(1){
        Angajat ang;
        ang.name = malloc(sizeof(char) * NAME_SIZE);
        if(ang.name == NULL){
            printf("Eroare la alocarea unui nume pentru angajati\n");
            return 0;
        }
        fread(&ang, sizeof(ang),1, fin);
        if(feof(fin)){
            break;
        }
        print_angajat(ang);
    }
    fclose(fin);
    return 1;
}

int main()
{
    save_angajati();
    show_angajat("1970122295326");
    return 0;
}
