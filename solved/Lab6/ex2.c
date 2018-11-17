#include "ex2.h"

void split_by_sign(int n, FILE* fin, FILE* positives, FILE* negatives){
    if(fin == NULL){
        return;
    }
    fseek(positives,0L,SEEK_SET);
    fseek(negatives,0L,SEEK_SET);
    for(int i = 0; i < n; ++i){
        int number;
        fscanf(fin,"%d ",&number);
        if(number >= 0){
            fwrite(&number,sizeof(int), 1, positives);
        }
        else{
            fwrite(&number,sizeof(int), 1, negatives);
        }
    }
}


