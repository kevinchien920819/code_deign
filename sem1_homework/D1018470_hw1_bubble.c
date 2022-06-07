#include<stdio.h>

void sortArray(int *nums, int numsSize){//do bubble sort
    for(int go = 0 ; go < numsSize-1; go++){
/*so if the check value is smaller then the going one then change value each other*/
        for(int check = go + 1; check < numsSize;check ++){
            if(nums[check] < nums[go]){
                int temp = nums[check];
                nums[check] = nums[go];
                nums[go] = temp;
            }
        }
    }
    printarray(nums,numsSize);
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
    printf("You are using bubble_sort now!\nPlease enter size of array:");
    int numsSize;
    scanf("%d",&numsSize);//get numbersize;
    unsigned int nums[50000] = {0};//set nums array
    printf("please enter value in array:");
    inputarray(nums,numsSize);//call function to scanf value of array
    sortArray(nums,numsSize);//call fuction to do bubble sort
}