#include <stdio.h>

void path_change(int* x_path, int* y_path) //to change the address x and y
{ 
    int temp = *x_path; 
    *x_path = *y_path; 
    *y_path = temp; 
} 
  
/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int sort_array (int *nums, int low, int high) 
{ 
    int pivot = nums[high]; 
    int min_index = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) 
    { 
        if (nums[j] < pivot) 
        { 
            min_index++; // increment index of smaller element 
            path_change(&nums[min_index], &nums[j]); 
        } 
    } 
    path_change(&nums[min_index + 1], &nums[high]); 
    return (min_index + 1); 
} 
  
/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort(int *nums, int low, int high) 
{ 
    if (low < high) 
    { 
        int partitioning_index = sort_array(nums, low, high); 
        quickSort(nums, low, partitioning_index - 1); 
        quickSort(nums, partitioning_index + 1, high); 
    } 
} 

void inputarray(unsigned int *nums,int numsSize){//ask to input array 
    for (int i = 0; i < numsSize; i++)
        scanf("%d",&nums[i]);
}
void printarray(unsigned int *nums ,int numsSize){//call this function to print array
    printf("After sort array:");
    for(int i = 0 ;i < numsSize-1; i++)//if not the last number of the array output "%d " and the last one out put "%d\n"
        printf("%d ",nums[i]);
    printf("%d\n",nums[numsSize-1]);
}

int main(){
    printf("You are using quick_sort now!\nPlease enter size of array:");
    int numsSize;
    scanf("%d",&numsSize);//get numbersize;
    unsigned int nums[50000] = {0};//set nums array
    printf("please enter value in array:");
    inputarray(nums,numsSize);//call function to scanf value of array
    quickSort(nums,0,numsSize-1);//call fuction to do quick sort
    printarray(nums,numsSize);
}