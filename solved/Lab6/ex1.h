/* asdasdas
asdasd
asdasdas
aasdasd */
/* */
/******* asdasd
***/
#ifndef EX1_H_INCLUDED
#define EX1_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


void generate_numbers(FILE* f,int no_numbers, int limit);
void show_numbers_from_file(FILE* f);
void sort_file(FILE* f);
void find_frequency_of_max(FILE* f, int* max_number, int* freq);
int count_elements_in_file(FILE* f, size_t element_size);



/// writes one element of given size from the given position in a file
/// positions are indexed starting from 0, as in arrays
/// example : we write an integer as the 4th in a file :
///         int number = 10;
///         write_at_position(f,3,sizeof(int),&number);
/// @param source (File*) = File source
/// @param position (int) = the position that we write the element in the file
/// @param size (size_t) = size of the written element
/// @param data (void *) = the address of the variable we write
///                     - because it is void*, we can read any type of element with this function
///                     - void* is a pointer to anything
void write_at_position(FILE* dest, int position, size_t size_of_elem, void *data);



/// reads one element of given size from the given position in a file
/// positions are indexed starting from 0, as in arrays
/// example : we read the 4th integer in a file f :
///         int number;
///         read_at_position(f,3,sizeof(int),&number);
/// @param source (File*) = File source
/// @param position (int) = ranking of the read element in the file
/// @param size (size_t) = size of a read element
/// @param data (void *) = the address of the variable we read to
///                     - because it is void*, we can read any type of element with this function
///                     - void* is a pointer to anything
void write_at_position(FILE* dest, int position, size_t size_of_elem, void *data);




#endif // EX1_H_INCLUDED
