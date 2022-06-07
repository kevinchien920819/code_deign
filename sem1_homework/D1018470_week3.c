#include<stdio.h>

int main(){
	int a,b;//a = ticket b = drink
	float fee;// define sum of each case
	scanf("%d %d",&a,&b);
	if (a>0&&b>0){//case 1
		fee =300*a+40*b-10;

	}
	if (a>=2){//case 2 
		fee = (300*a+40*b)*0.9;

	}
	if (a>=2&&b>0){//case 3
		fee = (300*a+40*b)*0.85-30; 

	}
	printf("%d",(int)fee);//trun fee into int and print out
	}


