#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

int p1(const char* filename){
    FILE *fin = fopen(filename,"a+");
    if(fin == NULL){
        perror("Eroare la deschiderea fisierului de intrare: ");
        return errno;
    }
    char letter;
    fscanf(fin, "%c ", &letter);
    letter = tolower(letter);
    FILE *fout = fopen("result1.txt", "w");
    if(fout == NULL){
        perror("Eroare la deschiderea fisierului de iesire: ");
        return errno;
    }
    char c;
    /*while( (c = fgetc(fin)) != EOF){
        if(tolower(c) != letter){
            fputc(c,fout);
        }
    }*/
    char* buffer;
    int buffer_size = 100;
    buffer = malloc(buffer_size * sizeof(char));
    if(buffer == NULL){
        perror("Eroare la alocarea buffer-ului de caractere :");
        return errno;
    }
    int index = 0;
    while( (c = fgetc(fin)) != EOF){
        if(tolower(c) != letter){
            buffer[index] = c;
            ++index;
            // if next index exceeds current buffer size
            if(index == buffer_size){
                char* temp = realloc(buffer, buffer_size * 2);
                if(temp == NULL){
                    perror("Eroare la realocarea buffer-ului de caractere :");
                    return errno;
                }
                buffer = temp;
                buffer_size *= 2;
            }
        }
    }
    buffer[index] = '\0';
    fseek(fin,0L,SEEK_END);
    fprintf(fin,"\n%s",buffer);
    fclose(fin);
    fclose(fout);
    return 1;
}

int p2(const char* filename){
    FILE *fin = fopen(filename,"r");
    if(fin == NULL){
        perror("Eroare la deschiderea fisierului de intrare: ");
        return errno;
    }
    char letter, new_letter;
    fscanf(fin, "%c %c ", &letter, &new_letter);
    letter = tolower(letter);
    new_letter = tolower(new_letter);
    printf("%c %c", letter, new_letter);
    char buffer[500];
    fgets(buffer,500,fin);
    for(int i = 0; i < 500; ++i){
        if(buffer[i] == letter){
            buffer[i] = new_letter;
        }
    }
    freopen(filename,"w",fin);
    fprintf(fin,"%s",buffer);
    fclose(fin);
    return 1;
}

int p3(const char* filename){
    FILE *fin = fopen(filename, "r+");
    if(fin == NULL){
        perror("La deschiderea fisierului :");
        return errno;
    }
    char c;
    while( (c = fgetc(fin)) != EOF){
        fseek(fin,-1L, SEEK_CUR);
        if(islower(c)){
            c = toupper(c);
            printf("%c",fputc(c,fin));
        }
        else {
            if(isupper(c)){
                c = tolower(c);
                printf("%c",fputc(c,fin));
            }
            else{
                fseek(fin, 1L, SEEK_CUR);
            }
        }
        fseek(fin,0L,SEEK_CUR);
    }
    fflush(fin);
    fclose(fin);
    return 1;
}

int p4(const char* filename){
        FILE *fin = fopen(filename, "r");
    if(fin == NULL){
        perror("La deschiderea fisierului :");
        return errno;
    }
    FILE *fout = fopen("result4.txt", "w");
    if(fout == NULL){
        perror("La deschiderea fisierului : ");
        return errno;
    }
    int upper[26];
    int lower[26];
    for(int i = 0; i < 26; ++i){
        upper[i] = 0;
        lower[i] = 0;
    }
    char c;
    while( (c = fgetc(fin)) != EOF){
        if(islower(c)){
            ++lower[c - 'a'];
        }
        else{
            if(isupper(c)){
                ++upper[c - 'A'];
            }
        }
    }
    // find max
    int max = 0;
    for(int i = 0; i < 26; ++i){
        if(lower[i] > max){
            max = lower[i];
        }
        if(upper[i] > max){
            max = upper[i];
        }
    }
    // show max letters
    printf("Max appearances - %d : ", max);
    for(int i = 0; i < 26; ++i){
        if(lower[i] == max){
            printf("%c ",i + 'a');
            fprintf(fout, "%c ", i + 'a');
        }
        if(upper[i] == max){
            printf("%c ", i + 'A');
            fprintf(fout, "%c ", i + 'A');
        }
    }
    fclose(fin);
    fclose(fout);
    return 1;
}

void p5(const char* filename){
        FILE *fin = fopen(filename, "r");
    if(fin == NULL){
        perror("Eroare la deschiderea fisierului : ");
        return errno;
    }
    FILE *fout = fopen("output.txt", "w");
    if(fout == NULL){
        perror("Eroare la deschiderea fisierului : ");
        return errno;
    }
    char word[100];
    scanf("%100s", word);

    /*fseek(fin, 0L, SEEK_END);
    long fsize = ftell(fin);
    fseek(fin, 0L, SEEK_SET);
    char *buffer = malloc(sizeof(char) * (fsize + 1));
    if(buffer == NULL){
        perror("Eroare la alocarea de memorie : ");
        return errno;
    }*/
    char buffer[100];
    while(1){
        fscanf(fin, "%s", buffer);
        if(feof(fin)){
            return 0;
        }
        if(strstr(buffer, word)){
            printf("%s ", buffer);
        }
    }
}

int main()
{
    p4("input4.txt");
    return 0;
}
