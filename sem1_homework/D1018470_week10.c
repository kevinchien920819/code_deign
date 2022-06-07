#include<stdio.h>
#include<stdlib.h>
int fibonacci(int a){//fibonacci fuction 
    if(a == 0)
        return 0;
    else if(a == 1)
        return 1;
    else
        return fibonacci(a-2)+fibonacci(a-1);
}
int main (){
    int times;
    int fib[40] = {0};//set array
    for (int i = 0; i < 40; i++)
        fib[i] = fibonacci(i); //first set fibonacci 
    scanf("%d",&times);
    int a,b;
    for (int i = 0; i < times; i++){
        int flag = 0;//flag set;
        scanf("%d %d",&a,&b);//input a and b
        if (b < a){//change if b < a
            int temp = b;
            b = a;
            a = temp;
        }
        for (int i = 0; i < 40; i++)
        {   
            if(fib[i] >= a && fib[i] <= b){//check if a < fib < b than print the fib
                printf("%d\n",fib[i]);
                flag ++;//and plus flag to calculate
            }

        }
        printf("%d\n",flag);//print flag
        if(i != times -1)
            printf("------\n");//the separate line
    }
    system("pause");
}
