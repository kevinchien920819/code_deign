#include"case.h"

int main(void)
{
   // initialize array a
   int a[SIZE] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
   
   puts("Data items in original order");

   size_t  i;
   // loop through array a
   for ( i = 0; i < SIZE; ++i) {
      printf("%4d", a[i]);
   } 

   puts("\nData items in ascending order");

   bubbleSort(a, SIZE,ascending); // sort the array
   for (i = 0; i < SIZE; ++i) {
      printf("%4d", a[i]);   
   } 
   puts("");
   puts("\nData items in descending order");
   bubbleSort(a, SIZE,descending); // sort the array
   for (i = 0; i < SIZE; ++i) {
      printf("%4d", a[i]);   
   } 
   puts("");
} 