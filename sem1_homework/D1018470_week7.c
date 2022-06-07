#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
    int n;
    char input[100] = " ";//set 
    scanf("%d\n",&n);
    for (int i = 0; i < n; i++){//do n times
        gets(input);//get string from input
        int abc [26]= {0};//let a to z == 0 (reset it)
        int j  =0;
       while(input[j] !='\0'){
            for(int k = 0;k<26;k++){//check wether string is a to z
                if(input[j] == 'A' + k || input[j] == 'a' + k ){//a to z is a + x(x = int)
                    abc[k]++;
                }
            }
            j++;
        }
        
       
        for(int k = 0;k < 26 ;k++){
            if (abc[k] != 0)//if count != 0, print it
                printf("%c %d\n",'A'+k,abc[k]);
        }
    }

   system("pause");
    
}