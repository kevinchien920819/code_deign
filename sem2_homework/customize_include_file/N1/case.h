// Fig. 6.16: fig06_16.c
// Survey data analysis with arrays; 
// computing the mean, median and mode of the data.
#include <stdio.h>
#define SIZE 30
#define FREQUENCY_SIZE 11
// function prototypes
void mean(const unsigned int answer[]);
void median(unsigned int answer[]);
void mode(unsigned int freq[], const unsigned int answer[]) ;
void bubbleSort(unsigned int a[]);
void printArray(const unsigned int a[]);

void fre(const unsigned int answer[],unsigned int response[]); 

