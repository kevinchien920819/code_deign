#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
void printarray(int*,int);//set function type
void inputarray(int*,int);//set function type
void sort(int*,int);//set function type
int main(){
    int num;
    scanf("%d",&num);
    int score[30] = {0};//declare array
    inputarray(score,num);//call function to input array
    sort(score,num);//do sort
    printarray(score,num);//call function to print array 
    if (score[0] >= 60)//after sort the lowest num will place at score[0] and if score[0]>=60 then all array >= 60
        printf("best case\n");//best case or not
    else{
        int i = num-1;//other to find the most close than 60 in array 
        while (score[i] >= 60)
        {
            i--;
        }
        printf("%d\n",score[i]);//print it out
    }
 
    if (score[num-1] < 60)//after sort the biggest num will place at score[num-1] and if score[num-1] < 60 than all array smaller than 60
        printf("worst case\n");//then print worst case
    else{
        int i = 0;//to find the most close than 60 in array 
        while (score[i] < 60 && i < num -1)
        {
            i++;
        }
        printf("%d\n",score[i]);
    }
    system("pause");
    
}
void printarray(int *score,int n){
    for (int i = 0; i < n; i++)//print array and if score[num-1] then print and \n else print and have a space
        if (i < n-1)
            printf("%d ",score[i]);
        else
            printf("%d",score[i]);
    printf("\n");
}
void inputarray(int *score,int n){
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&score[i]);//input array
    }
}
void sort(int *score,int n){
    for (int i = 0; i < n; i++)
    {
        int temp =0;
        for (int j = i; j < n; j++){
            if(score[j] < score[i]){
                temp = score[i];
                score[i] = score[j];
                score[j] = temp;
            }
        }
        
    }
    
}
