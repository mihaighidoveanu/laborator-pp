#include "cod.h"

/// Parameter functions
unsigned isself(Student x){
    return 1;
}

unsigned isbuget(Student x){
    return x.buget;
}

unsigned istaxa(Student x){
    return (x.buget == 0);
}

unsigned isrespins(Student x){
    return (x.admis == 0);
}

int sort_medie_desc(Student x, Student y){
    return y.medie - x.medie;
}

int sort_medie(Student x, Student y){
    return x.medie - y.medie;
}

int sort_alfabetic(Student x, Student y){
    return strcmp(x.nume,y.nume);
}

/// Private functions
void replace_newline_with_null(char* str){
    int i = 0;
    while(str[i] != '\n'){
        ++i;
    }
    str[i] = '\0';
}

int binary_search_students(Student* arr, unsigned int l, unsigned int r, const char* nume){
    if(r < l){
        return -1;
    }
    unsigned mid = l + (r - l) / 2;
    int compare = strcmp(nume,arr[mid].nume);
    if(compare == 0){
        return mid;
    }
    if(compare < 0){
        return binary_search_students(arr, 0, mid - 1, nume);
    }
    return binary_search_students(arr,mid + 1, r, nume);
}

char to_lower(char c){
    if(c - 'A' <= 'Z' - 'A'){ //if c is big letter
        c += 'a' - 'A'; // make c a small letter
    }
    return c;
}

int compute(int a, int b, char op){
    switch(op){
    case '+' :
        return a + b;
    case '-' :
        return a - b;
    case '*' :
        return a * b;
    case '/' :
        if(b == 0){
            return INT_MAX;
        }
        else {
            return a / b;
        }
    case '%' :
        return a % b;
    default:
        return INT_MIN;
        break;
    }
}



void read_candidate(Student* arr,unsigned int array_size){
    char nr_legitimatie[5];
    char nume[31];
    float nota_mate, nota_info, nota_bac;
    scanf("%4s ", nr_legitimatie);
    fgets(nume, 31, stdin);
    replace_newline_with_null(nume);
    scanf("%f %f %f", &nota_mate, &nota_info, &nota_bac);
    Student s;
    strcpy(s.nr_legitimatie, nr_legitimatie);
    strcpy(s.nume, nume);
    s.nota_info = nota_info;
    s.nota_mate = nota_mate;
    s.nota_bac = nota_bac;
#ifdef MEDIA_ADMITERE
    MEDIA_ADMITERE(s);
#endif
#ifdef PRAG_MINIM
    s.admis = s.medie > PRAG_MINIM ? 1 : 0;
#endif
    if(array_size == 0){
        arr[0] = s;
    }
    int index = 0;
    for(;index < array_size; ++index){
        //if our student's name ranks before the current student in array
        if(strcmp(s.nume,arr[index].nume) < 0){
            break;
        }
    }
    // move elements aside to make space for the read student
    int i = array_size;
    for(;i > index; --i){
        arr[i] = arr[i - 1];
    }
    // add the read student
    arr[index] = s;
}

int find_student_by_name(Student* arr, unsigned int array_size,const char* nume){
    return binary_search_students(arr,0,array_size - 1,nume);
}


void print_candidate(Student x){
    printf("Student: %s - %s : %f, %f, %f. Media : %f. Admis : %s. Buget : %s\n",x.nr_legitimatie, x.nume, x.nota_mate,
                x.nota_info, x.nota_bac, x.medie, x.admis ? "Da" : "Nu", x.buget ? "Da" : "Nu");
}

void swap_students(Student *x, Student *y){

    Student aux = (*y);
    (*y) = (*x);
    (*x) = aux;
}


void sort_students(Student* arr, unsigned array_size, int (*sort)()){
    int i,j;
    for(i = 0;i < array_size - 1; ++i){
        for(j = i + 1; j < array_size; ++j){
            if( (*sort)(arr[i],arr[j]) > 0 ){
                Student aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

void print_candidates(Student* arr, unsigned array_size, unsigned (*filter)(), int (*sort)()){
    int i = 0;
    if(sort){
        sort_students(arr,array_size,sort);
    }
    for(;i < array_size; ++i){
        if( (*filter)(arr[i])){
            print_candidate(arr[i]);
        }
    }
}


void print_candidates_menu(){
    printf("Alege optiunea :\n");
    printf("1. Toti candidatii (alfabetic)\n");
    printf("2. Admisi la buget \n");
    printf("3. Admisi la taxa \n");
    printf("4. Respinsi (descrescator dupa medie) \n");
    printf("0. Exit \n");
}

void buget_partition_candidates(Student* arr, unsigned int array_size){
    Student sorted_arr[array_size];
    int i;
    // copy students to sorted array
    for(i = 0; i < array_size; ++i){
        sorted_arr[i] = arr[i];
    }
    // sort students by medie
    sort_students(sorted_arr,array_size,sort_medie_desc);
    // divide by 4 and round down
    int top75 = array_size * 3 / 4;
    printf("Top 75 : %d\n",top75);
    int buget_students = 0;
    for(i = 0; i < array_size; ++i){
        // search for the student in the original array
        int searched = find_student_by_name(arr,array_size,sorted_arr[i].nume);
        if(sorted_arr[i].admis && buget_students < top75){
            ++buget_students;
            arr[searched].buget = 1;
        }
        else {
            arr[searched].buget = 0;
        }
    }
}

int show_candidates_with_menu(Student* arr, unsigned array_size){
    print_candidates_menu();
    unsigned option;
    scanf("%d",&option);
    switch(option){
    case 1 :
        print_candidates(arr, array_size, isself, sort_alfabetic);
        return 1;
    case 2:
        print_candidates(arr, array_size, isbuget, NULL);
        return 2;
    case 3:
        print_candidates(arr, array_size, istaxa, NULL);
        return 3;
    case 4:
        print_candidates(arr, array_size, isrespins, sort_medie_desc);
        return 4;
    case 0:
        return 0;
    default:
        printf("Alege o optiune valida\n");
        return -1;
    }
}
