#include <stdio.h>

int upper(int character){
    if (character>=97&&character <= 122)//ascii 'a' =  dec(97) and 'z' = dec(122) 
        return character - 32;//turn in to 'A' to 'Z'
    else
        return character;//if not letter then return character 
} 

int lower(int character){
    if (character>=65&&character <= 90)//ascii 'A' =  dec(65) and 'Z' = dec(90) 
        return character + 32;//turn in to 'a' to 'z' 
    else
        return character;//if not letter then return character 
} 

int string_length(char string[]){
    int counter = 0;//ste counter
    int i = 0;
    while (string[i]!='\0')//get length until no input char
    {
        counter++;//counter counting
        i++;//shift i 
    }
    return counter;//return back 
    
} 

int main(){

 char string[] = "HellO? World!!!/^^";

 printf("%s\n", string);

 printf("string length: %d\n", string_length(string));

 for(int i = 0; i < string_length(string); i++)

{

 printf("%c", upper(string[i]));

}

 printf("\n");

  

 for(int i = 0 ; i < string_length(string) ; i++){

 printf("%c", lower(string[i]));

}

 printf("\n");


}
