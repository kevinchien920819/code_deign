#include"case.h"
#define SIZE 30
// function main begins program execution
int main(void)
{
   unsigned int frequency[10] = {0}; // initialize array frequency
   
   // initialize array response
   unsigned int response[SIZE] =             
      {6, 7, 8, 4, 8, 7, 8, 2, 8, 2,
       7, 8, 9, 5, 9, 5, 7, 8, 7, 8,
       6, 7, 6, 9, 3, 9, 8, 7, 8,1};

   // process responses
   mean(response);
   median(response);
   mode(frequency, response);
}