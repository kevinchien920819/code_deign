#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#define history_len 272 //data from history.txt
#define words_len 2315//data from word.txt
char history[history_len][7];//protype of history array
char words[words_len+1][7];//protype of words array
FILE *historyptr , *wordsptr;//file ptr


//read history.txt into history array
void readhistory(){

historyptr = fopen("history.txt","r");//set the file location and turn to read mode
//if the file can't open ,let user know 
if(fopen("history.txt","r") == NULL)
	printf("history.txt can't open!\n");

else{

	// make memory to store the data
	char *date = malloc(sizeof(char*) * 50);
	char *days = malloc(sizeof(char*) * 10);
	char *answer = malloc(sizeof(char *) * 8);

	int historycount = 0; //the history counter

	//read untill there is no more data
	while(feof(historyptr) == 0){
		fscanf(historyptr,"%s",date);
		fscanf(historyptr,"%s",days);
		fscanf(historyptr,"%s",answer);
		
		//copy answer to history array
		strcpy(history[historycount],answer);
		historycount++;//move the counter
	}

	// free the memory that won't use any more
	free(date);
	free(days);
	free(answer);
}

//close the data ptr
fclose(historyptr);
}


//read words.txt into words array 
void readwords(){

wordsptr =fopen("words.txt","r");//set the file location and turn to read mode
//if the file can't open ,let user know 
if(fopen("words.txt","r")== NULL)
	printf("words.txt can't open!\n");

else{

	// make memory to store the data
	char *cases = malloc(sizeof(char * ) * 30);
	int wordcount = 0;//the words counter

	//copy cases to words array
	while(feof(wordsptr) == 0){
		fscanf(wordsptr,"%s",cases);
		strcpy(words[wordcount],cases);
		wordcount++;
	}
	//free the memory that won't use any more
	free(cases);
	}
fclose(wordsptr);//close the file ptr
}

//compare the history and words if the words have show in history the n remove it 
void compare_string(){

for(int i =1;i < history_len;i++){
	for(int j = 0;j < words_len;j++){
		if(strcasecmp(history[i],words[j]) == 0){
				strcpy(words[j]," ");
			break;
		}

	}
}
}

void printword(){
	int printcounter = 0;
	for(int i = 0 ; i < words_len;i++){
	if(words[i][0] != ' ' && (printcounter+1) % 10!=0){
		printf("%s ",words[i]);
		printcounter++;
	}
	else if(words[i][0] != ' ' && (printcounter+1) % 10==0){
		printf("%s\n",words[i]);
		printcounter = 0;
	}
	}
}
int main(){
//rewind all ptr
rewind(historyptr);
rewind(wordsptr);

readhistory();//read history.txt
readwords();//read words.txt
compare_string();//compare the text
printword();//print the words after compare

char input[6] = {};
char react[6] = {};

int flag;
//do untill the react is ggggg
do{
	//get the wodle guess
	printf("\nplesse input guess in wordle:");
	scanf("%s",input);
	//get wordle reflectiton 
	printf("please input the react of wordle:");
	scanf("%s",react);
	//pending the case of b g y and the special case
	for(int i = 0 ; i < 5;i++){
		int special_case;
		if(react[i] == 'y'){
		int special_case = 0;
			for(int j = 0;j < words_len;j++){
				if(words[j][i] == input[i]){
					strcpy(words[j]," ");
				}
		
			int flag = 0;
			for (int k = 0; k < 5; k++){
                if (words[j][k] == input[i])
                	flag++;
			} 
			if (flag == 0)  
			strcpy(words[j], " ");
			}
			for(int j= 0; j < 5;j++)
				for(int k = 0 ; k < 5 ;k++){
					if(input[j] == input[k] && react[j] == 'y' && react[k] == 'b'){
						special_case = 1;
					}
				}

		}
		else if(react[i] == 'b'){
				if(special_case == 1){
				for(int j = 0;j < words_len;j++){
				if(words[j][i] == input[i]){
					strcpy(words[j]," ");
				}
				}
			}
			for(int j = 0; j < words_len;j++){
				for(int k = 0 ;k <5;k++)
				if(words[j][k] == input[i]){
					strcpy(words[j] , " ");
				}
			}
		}
		else if(react[i] == 'g')
			for(int j =0 ;j < words_len;j++){
				if(words[j][i] != input[i]){
					strcpy(words[j] , " ");
				}
			}
			

		else
		printf("Index %d is a incorrect input.\n", i);
	
	}
//if the words has not replace to blank themn print it
for(int i = 0 ; i < words_len;i++)
	if(words[i][0]!=' ')
		printf("%s ",words[i]);

}while(strcmp("ggggg",react)!=0);

//get the answer
printf("congratulation! you get the answer!\n\n");


system("pause");
return 0 ;

}

