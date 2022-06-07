#include"case.h"
// calculate average of all response values

void mean(const unsigned int answer[])
{

   unsigned int total = 0; // variable to hold sum of array elements

   // total response values
   for (size_t j = 0; j < SIZE; ++j) {
      total += answer[j];
   } 

   printf("The total is %u\nThe mean is %lf\n",total, (double) total / SIZE);
} 

// sort array and determine median element's value
void median(unsigned int answer[])
{

   bubbleSort(answer); // sort array

   printf("%s", "\nThe sorted array is");
   printArray(answer); // output sorted array

   // display median element
   printf("\n\nThe median is %u\n\n",answer[SIZE / 2]);
} 

// determine most frequent response
void mode(unsigned int freq[], const unsigned int answer[])
{

   // initialize frequencies to 0
   for (size_t rating = 1; rating <= 9; ++rating) {
      freq[rating] = 0;
   } 

   // summarize frequencies
   for (size_t j = 0; j < SIZE; ++j) {
      ++freq[answer[j]];
   } 
   printf("%s%11s\n","Response", "Frequency");
   // output results
   unsigned int largest = 0; // represents largest frequency
   unsigned int modeValue = 0; // represents most frequent response
   for (size_t rating = 1; rating <= 9; ++rating) {
      printf("%8u%11u          ", rating, freq[rating]);

      // keep track of mode value and largest frequency value
      if (freq[rating] > largest) {                         
         largest = freq[rating];                              
         modeValue = rating;                                    
      }                                             

      // output histogram bar representing frequency value

      puts(""); // being new line of output
   }
   // output headers for result columns




   // display the mode value

} 

// function that sorts an array with bubble sort algorithm
void bubbleSort(unsigned int a[])
{
   // loop to control number of passes
   for (unsigned int pass = 1; pass < SIZE; ++pass) {

      // loop to control number of comparisons per pass
      for (size_t j = 0; j < SIZE - 1; ++j) {

         // swap elements if out of order
         if (a[j] > a[j + 1]) {
            unsigned int hold = a[j];
            a[j] = a[j + 1];
            a[j + 1] = hold;
         } 
      } 
   } 
} 

// output array contents (20 values per row)
void printArray(const unsigned int a[])
{
   // output array contents
   for (size_t j = 0; j < SIZE; ++j) {

      if (j % 20 == 0) { // begin new line every 20 values
         puts("");
      } 

      printf("%2u", a[j]);
   } 
}
// #define RESPONSES_SIZE 40 // define array sizes
// #define FREQUENCY_SIZE 11
// void fre(const unsigned int answer[],unsigned int response[]){ 
//    int frequency[FREQUENCY_SIZE] = {0};
//    for (size_t answer = 0; answer < SIZE; ++answer) {
//       ++frequency[response[answer]];
//    } 

//    // display results
//    printf("%s%17s\n", "Rating", "Frequency");

//    // output the frequencies in a tabular format
//    for (size_t rating = 1; rating < FREQUENCY_SIZE; ++rating) {
//       printf("%6d%17d\n", rating, frequency[rating]);
//    } 
// }