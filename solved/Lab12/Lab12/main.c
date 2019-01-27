#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

char* lcprefix(int n, ...){
    if(n == 0){
        return NULL;
    }
    va_list params;
    va_start(params, n);
    char* s1 = va_arg(params,char*);
    char* prefix = malloc(sizeof(char) * (strlen(s1) + 1));
    strcpy(prefix, s1);
    for(int i = 1; i < n; ++i){
        char *s2 = va_arg(params, char*);
        int index = 0;
        while(s1[index] == s2[index]){
            ++index;
        }
        prefix[index] = '\0';
    }
    va_end(params);
    return prefix;
}

int freq(int x, int n, ...){
    va_list params;
    va_start(params,n);
    int count = 0;
    for(int i = 0; i < n; ++i){
        int y = va_arg(params,int);
        if(y == x){
            ++count;
        }
    }
    va_end(params);
    return count;
}

int are_distinct(int x1, int x2, int x3, int x4){
    return freq(x1, 3, x2, x3, x4);
}

int check_eq(void* a1, void* a2, int n, int m, int dim, int (*eq)(void*, void*) ){
    if(n != m){
        return 0;
    }
    for(int i = 0; i < n; ++i){
        if(! eq( a1 + i * dim, a2 + i * dim)){
            return 0;
        }
    }
    return 1;
}

int eq_int(void* a, void* b){
    int va = *(int*)a;
    int vb = *(int*)b;
    if( va == vb){
        return 1;
    }
    return 0;
}

int eq_char(void* a, void* b){
    char va = *(char*)a;
    char vb = *(char*)b;
    if( va == vb){
        return 1;
    }
    return 0;
}

void copy_int(void* dest, void* src){
    int* pd = (int*)dest;
    int vs = *(int*)src;
    (*pd) = vs;
}

void update(void* arr, int n, int dim, void* x, void* y, int eq(void*, void*), void copy(void*, void*)){
    for(int i = 0; i < n; ++i){
        if( eq(arr + i * dim, x)){
            copy(arr + i * dim, y);
        }
    }
}

int rec_max(int* arr, int n, int* result ){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    if(arr[0] > (*result)){
        (*result) = arr[0];
    }
    return rec_max(arr + 1, n - 1, result);
}

int is_palindrom_str(char* str){
    int len = strlen(str);
    if(len == 1 || len == 0){
        return 1;
    }
    if(str[0] != str[len - 1]){
        return 0;
    }
    else{
        memmove(str, str + 1,strlen(str + 1));
        str[len - 2] = '\0';
        return is_palindrom_str(str);
    }

}

int is_palindrom(unsigned int x){
    char str[20];
    sprintf(str,"%d",x);
    return is_palindrom_str(str);
}


int main()
{
    //printf("%s", lcprefix(4, "Ionel", "Ionelule", "Ionascu", "Imperativ"));
    //printf("%d\n",freq(2,6,1,2,3,2,0,2));
    //printf("%d\n", are_distinct(10,10,10,10));
    /*
    int a1[] = {1,2,3};
    int a2[] = {1,2,3};
    char s1[] = "ana";
    char s2[] = "ana";
    printf("%d\n", check_eq(s1, s2, 3, 3, sizeof(char), eq_char));
    */
    /*int arr[] = {1,0,2,0};

    int x = 0;
    int y = 10;
    update(arr,4,sizeof(int),&x, &y, eq_int, copy_int);
    for(int i = 0; i < sizeof(arr) / sizeof(int); ++i){
        printf("%d ", arr[i]);
    }*/
    /*
    int arr[] = {1,0 ,200, 0};
    int max = -1;
    rec_max(arr, 4, &max);
    printf("%d ", max);
    */
    char str[] = "121";
    printf("%d\n",is_palindrom_str(str));
    printf("%d\n",is_palindrom(121));
    return 0;
}
