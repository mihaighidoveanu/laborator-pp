#include "ex3.h"

void print_source(char* str){
    if(str == NULL){
        return;
    }
    FILE* f;
    f = fopen(str,"r");
    if(f == NULL){
        printf("Eroare la deschiderea fisierului sursa \n");
        return;
    }
    char c;
    while(1){
        c = fgetc(f);
        if(feof(f)){
            break;
        }
        printf("%c",c);
    }
}

void source_without_comments(char *str){
    if(str == NULL){
        return;
    }
    FILE* f;
    f = fopen(str,"r");
    if(f == NULL){
        printf("Eroare la deschiderea fisierului sursa \n");
        return;
    }
    char c, sc;
    int comment_started = 0;
    int big_comment_started = 0;
    int big_comment_ended = 0;
    c = fgetc(f);
    if(c == EOF){
        return;
    }
    while( (sc = fgetc(f)) != EOF){
        if(!comment_started && !big_comment_started){
            if(c == '/'){
                if(sc == '/'){
                    comment_started = 1;
                }
            }
        }
        if(!comment_started && !big_comment_started){
            if(c == '/'){
                if(sc == '*'){
                    big_comment_started = 1;
                }
            }
        }
        if(!comment_started && !big_comment_started){
            fputc(c,stdout);
        }
        if(big_comment_started){
            if(c == '*'){
                if(sc == '/'){
                    big_comment_started = 0;
                    big_comment_ended = 1;
                }
            }
        }
        if(comment_started){
            if(c == '\n'){
                comment_started = 0;
            }
        }
        c = sc;
        if(big_comment_ended){
            c = ' ';
            big_comment_ended = 0;
        }
    }
    fclose(f);
}
