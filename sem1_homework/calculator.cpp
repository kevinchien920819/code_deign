#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    char notation = ' ';
    scanf("%d", &a);
    getchar();
    scanf("%c", &notation);
    scanf("%d", &b);

    switch(notation)
    {
        case '+':  //add
            printf("%d", a + b);
            break;
        case '-'://subtraction
            printf("%d",a - b);
            break;
        case '*': //product
            printf("%d",a * b);
            break;
        case '/': //quotient
        	if(a == 0||b== 0)//a=0||b=0  output: ERROR
        	{
        	printf("wrong input\n");
        	break;
			}
			else{	
            printf("%d", a / b);
            break;
			}
        default: // not + - * /  output:ERROR
            printf("Error input\n");
            break;
    }
    
}
