#include "students.h"

struct student citeste_student(){
    struct student x;
    scanf("%d", &x.id);
    scanf("%20s", x.nume);
    scanf("%s", x.prenume);
    scanf("%f", &x.nota);
    return x;
}

void creare(char *nume_fisier_binar, int n){
    FILE *fout;
    fout = fopen(nume_fisier_binar,"wb");
    if(fout == NULL){
        printf("Eroare la deschiderea fisierului %s", nume_fisier_binar);
        return;
    }
    for(int i = 0; i < n; ++i){
        struct student x = citeste_student();
        fwrite(&x,sizeof(x),1,fout);
    }
    fclose(fout);
}


void afisare (char *nume_fisier_binar, char *nume_fisier_text){
    FILE *bin = fopen(nume_fisier_binar,"rb");
    if(bin == NULL){
        printf("Eroare la deschiderea fisierului %s", nume_fisier_binar);
        return;
    }
    FILE *txt = fopen(nume_fisier_text,"w+");
    if(txt == NULL){
        printf("Eroare la deschiderea fisierului %s", nume_fisier_text);
        return;
    }
    struct student x;
    int no_students = count_elements_in_file(bin,sizeof(struct student));
    fseek(bin,0L,SEEK_SET);
    for(int i = 0; i < no_students; ++i){
        fread(&x,sizeof(x),1,bin);
        //printf("Studentul : %d %s %s %f\n",x.id,x.nume, x.prenume, x.nota);
        fprintf(txt,"%d %s %s %f\n",x.id, x.nume, x.prenume, x.nota);
    }
    fseek(txt,0L,SEEK_SET);
    char student[100];
    while(fgets(student,100,txt)){
        student[strcspn(student,"\n")] = '\0';
        printf("Studentul %s \n",student);
    }
    /* O alta varianta :
    while(fread(&x,sizeof(x),1,bin) == 1){
        printf("Studentul : %d %s %s %f\n",x.id,x.nume, x.prenume, x.nota);
        fprintf(txt,"%d %s %s %f\n",x.id, x.nume, x.prenume, x.nota);
    }
    */
    fclose(bin);
    fclose(txt);
}

void modificare (char *nume_fisier_binar, int id, float nota){
    FILE *f = fopen(nume_fisier_binar,"r+b");

    int found_student = 0;
    struct student x;
    fpos_t position;
    fgetpos(f,&position);

    while(fread(&x,sizeof(x),1,f) == 1){
        //printf("Studentul : %d %s %s %f\n",x.id,x.nume, x.prenume, x.nota);
        if(x.id == id){
            found_student = 1;
            break;
        }
        fgetpos(f, &position);
    }
    if(!found_student){
        printf("Nu am gasit niciun student cu id-ul respectiv\n");
        return;
    }
    fsetpos(f,&position);
    x.nota = nota;
    fwrite(&x,sizeof(x),1,f);
    //fseek(f,-sizeof(x),SEEK_CUR);
    //struct student y;
    //fread(&y,sizeof(y),1,f);
    //printf("\nAm modificat Studentul : %d %s %s %f\n",x.id,x.nume, x.prenume, x.nota);
    fclose(f);
}

void adaugare (char *nume_fisier_binar, struct student s){
    FILE *f = fopen(nume_fisier_binar,"ab");
    if(f == NULL){
        printf("Eroare la deschiderea fisierului %s.\n",nume_fisier_binar);
        return;
    }

    fseek(f,0L,SEEK_END);
    fwrite(&s,sizeof(s),1,f);
    fclose(f);

}
