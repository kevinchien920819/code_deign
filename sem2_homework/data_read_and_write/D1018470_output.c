#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

int main(){

FILE *ptr;//file pointer
//open file
ptr = fopen("D1018470.dat","rb+");
if(ptr == NULL)
	printf("can't open file\n");
//set the pointer
fseek(ptr ,0 , SEEK_SET);
//protype of reader
char id[10] =  {0};
char bin[50] = {0};
char oct[50] = {0};
char dec[50] = {0};
char hex[50] = {0};
int number;
//read the id
fread(id,sizeof(id),1,ptr);
printf("%s",id);
//read the input number
fread(&number, sizeof(int),1,ptr);
printf("input:%d\n",number);

//inteager to array and change the number system
itoa(number,bin,2);
itoa(number,oct,8);
itoa(number,dec,10);
itoa(number,hex,16);

//set the pointer to file end to write
fseek(ptr,0,SEEK_END);

//print and wirite in file with binary
printf("BIN : %s\n",bin);
fprintf(ptr, "\nBIN : %s\n", bin);

//print and write in file with octal
printf("OCT : ");
for(int i =0 ; i < strlen(bin) - strlen(oct);i++){
	printf(" ");
    fprintf(ptr," ");
}
printf("%s\n",oct);
fprintf(ptr,"%o\n",number);

//print and write in file with decimal
printf("DEC : ");
for(int i =0 ; i < strlen(bin) - strlen(dec);i++){
	printf(" ");
    fprintf(ptr," ");
}
printf("%s\n",dec);
fprintf(ptr,"%d\n",number);

//print and write in file with hexidental
printf("HEX : ");
for(int i =0 ; i < strlen(bin) - strlen(hex);i++){
	printf(" ");
    fprintf(ptr," ");
}
printf("%s\n",hex);
fprintf(ptr,"%x\n",hex);

system("pause");
return 0 ;
}
