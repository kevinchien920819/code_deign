#include<stdio.h>

void path_change(int *check_path, int *go_path)//change path of check and go one
{
	int temp = *check_path;//use temp to change
	*check_path = *go_path;
	*go_path = temp;
}
int* sortArray(int* nums, int numsSize){

	for (int go = 0; go < numsSize-1; go++)
	{
        int min_index = go;
		
        for (int check = go+1; check < numsSize; check++){
		
        	if (nums[check] < nums[min_index]){
					min_index = check;
			}
		}
		path_change(&nums[min_index], &nums[go]);
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
    printf("You are using selection_sort now!\nPlease enter size of array:");
    int numsSize;
    scanf("%d",&numsSize);//get numbersize;
    unsigned int nums[50000] = {0};//set nums array
    printf("please enter value in array:");
    inputarray(nums,numsSize);//call function to scanf value of array
    sortArray(nums,numsSize);//call fuction to do merge sort
}
