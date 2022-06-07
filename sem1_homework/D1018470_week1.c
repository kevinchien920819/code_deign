#include<stdio.h>
#include<stdlib.h> 
int main(void){
char string[][12] = {
        "hello,world",
        "hello      ",
        "      world", 
        "he         ",
        "he      r d", 
        "   lo w    ",  
        "    o    ld", 
        "hello,world"
    }; 
	char flag = 0;
	int i;
	for(i=0;i<=7;i++){
		scanf("%c", &flag);
		printf("%s",string[i]);
		
	}
	return 0;


}


