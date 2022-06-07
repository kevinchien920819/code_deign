#include<stdio.h>

int sortArray(int* nums, int numsSize){
	/*if a value is bigger then key then put it to right side
	and check again whether the key is smaller*/
	for (int go = 1; go < numsSize; go++) {
		int key = nums[go];
		int  check = go - 1;
		while (check >= 0 && nums[check] > key) {
			nums[check + 1] = nums[check];
			check = check - 1;
		}
		nums[check + 1] = key;
	}
    
	printarray(nums,numsSize);//call function printarray
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
    printf("You are using insertion_sort now!\nPlease enter size of array:");
    int numsSize;
    scanf("%d",&numsSize);//get numbersize;
    unsigned int nums[50000] = {0};//set nums array
    printf("please enter value in array:");
    inputarray(nums,numsSize);//call function to scanf value of array
    sortArray(nums,numsSize);//call fuction to do insertion sort

}