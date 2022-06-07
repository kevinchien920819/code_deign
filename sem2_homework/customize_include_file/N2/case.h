#include<stdio.h>
#define SIZE 10

void bubbleSort(int * const array, const size_t size,int (*compare)(int,int)); 
void swap(int *element1Ptr, int *element2Ptr);
int ascending(int a, int b);
int descending(int a, int b);   