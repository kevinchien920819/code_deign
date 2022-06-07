#include<stdio.h>
#include<stdlib.h>
int main (){

FILE *ptr;//file pointer
//open file
ptr = fopen("D1018470.dat","wb");
	if(ptr == NULL)
		printf("can't open file\n");
//write id in the file
char id[10] = "D1018470\n";
fwrite(id,sizeof(id),1,ptr);
//write number in the file
int number;
scanf("%d",&number);
fwrite(&number,sizeof(int),1,ptr);

system("pause");

}
