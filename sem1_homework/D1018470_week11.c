#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct xyz
{
    int x;
    int y;
    int z;
};

int main(){
    int n; // n of trible coordinate
    scanf("%d",&n);
    struct xyz data[100];
    for(int i = 0;i < n; i++)
        scanf("%d %d %d",&data[i].x,&data[i].y,&data[i].z);

    for (int  i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if(data[i].x > data[j].x){
                struct xyz temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
            else if(data[i].x == data[j].x&&data[i].y > data[j].y){
                struct xyz temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
            else if(data[i].x == data[j].x&&data[i].y == data[j].y&&data[i].z > data[j].z){
                struct xyz temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    for (int  i = 0; i < n; i++)
    {
        if(i != n-1)
            printf("%d %d %d\n----------\n",data[i].x,data[i].y,data[i].z);
        else
            printf("%d %d %d",data[i].x,data[i].y,data[i].z);
    }
    
}