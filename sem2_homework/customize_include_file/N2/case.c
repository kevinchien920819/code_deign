#include"case.h"

int ascending(int a, int b)                                  
{                                                              
   return b < a; // should swap if b is less than a         
}

// determine whether elements are out of order for a descending
// order sort                                               
int descending(int a, int b)                                 
{                                                              
   return b > a; // should swap if b is greater than a      
}
void bubbleSort(int * const work, const size_t size,int (*compare)(int,int))
{
   void swap(int *element1Ptr, int *element2Ptr); // prototype

   unsigned int pass;
   size_t count;
   // loop to control passes
   for (pass = 0; pass < size - 1; ++pass) {

      // loop to control comparisons during each pass
      for (count = 0; count < size - 1; ++count) {

         // swap adjacent elements if theye out of order
         if ((*compare)(work[count], work[count + 1])) {
            swap(&work[count], &work[count + 1]);
         } 
      } 
   } 
}

// swap values at memory locations to which element1Ptr and
// element2Ptr point                                    
void swap(int *element1Ptr, int *element2Ptr)            
{                                                          
   int hold = *element1Ptr;                                
   *element1Ptr = *element2Ptr;                            
   *element2Ptr = hold;                                    
}