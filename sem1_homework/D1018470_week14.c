#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void reverser(int before[100][100],int after[100][100],int m,int n){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            after[i][j] = before[j][i];
        }
}
int main(){
    int m,n;
    int before[100][100] = {0};
    int  after[100][100] = {0};
    scanf("%d %d",&m,&n);
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++){
            scanf("%d",&before[i][j]);
        }
    reverser(before,after,m,n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(j != m -1)
                printf("%d ",after[i][j]);
            else
                printf("%d",after[i][j]);
        }
    printf("\n");
    }
}