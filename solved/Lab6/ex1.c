#include "ex1.h"


void read_at_position(FILE* source, int position, size_t size, void *data){
    if(source == NULL){
        return;
    }
    // multiply position with size to get the number of octets (bytes) that we need to offset
    fseek(source, position * size, SEEK_SET);
    // read one element of given size into data
    fread(data, size, 1, source);
}

void write_at_position(FILE* dest, int position, size_t size, void *data){
    if(dest == NULL){
        return;
    }
    // multiply position with size to get the number of octets (bytes) that we need to offset
    fseek(dest, position * size, SEEK_SET);
    // write one element of given size from data
    fwrite(data, size, 1, dest);
}

int count_elements_in_file(FILE* f,size_t element_size){
    if(f == NULL){
        return 0;
    }
    fseek(f,0L,SEEK_END);
    long nbytes = ftell(f);
    return nbytes / element_size;
}


int get_max_from_file(FILE* f){
    if(f == NULL){
        return -1;
    }
    long no_numbers = count_elements_in_file(f, sizeof(int));
    int max;
    read_at_position(f,no_numbers - 1, sizeof(max), &max);
    return max;
}


void find_frequency_of_max(FILE* f, int* max, int* freq){
    if( f == NULL){
        return;
    }
    long poz = count_elements_in_file(f, sizeof(int));
    (*max) = get_max_from_file(f);
    (*freq) = 0;
    while( poz >= 0){
        int number;
        read_at_position(f,poz - 1, sizeof(max), &number);
        if(number == *max){
            ++(*freq);
        }
        else {
          break;
        }
        --poz;
    }
}

void show_numbers_from_file(FILE* f){
    if(f == NULL){
        return;
    }
    long no_numbers = count_elements_in_file(f, sizeof(int));
    fseek(f,0L,SEEK_SET);
    int i;
    for(i = 0; i < no_numbers; ++ i){
        int number;
        fread(&number,sizeof(int),1,f);
        printf("%d ",number);
    }
    printf("\n");
}

void sort_file(FILE* f){
    if(f == NULL){
        return;
    }
    int no_numbers = count_elements_in_file(f, sizeof(int));
    int no1;
    int no2;
    int size = sizeof(no2); // for convenience
    for(int i = 0; i < (no_numbers - 1); ++i){
        int j;
        for(j = i + 1; j < no_numbers; ++j){
            read_at_position(f,i, size,&no1);
            read_at_position(f,j, size,&no2);
            if(no1 > no2){
                write_at_position(f,i,size,&no2);
                write_at_position(f,j,size,&no1);
            }
        }
    }
}


void generate_numbers(FILE* f, int no_numbers, int limit){
    if(f == NULL){
        return;
    }
    fseek(f,0L,SEEK_SET);
    int i;
    for(i = 0;i < no_numbers; ++i){
        int random = rand();
        int number = random % (2 * limit + 1)  - limit;
        fwrite(&number,sizeof(int),1,f);
    }
}
