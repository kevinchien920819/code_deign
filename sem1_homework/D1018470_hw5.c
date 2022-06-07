#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <ctype.h>
int parity(int);
void is_odd(int);
int id_num(char);
int check_id(void);
void congratulation (void);
void student_notice(char);
int bmi_test (float,float);
int guess_num(int,int);
void bmi_ans(int);
char buffer[7];//operate buffer
char student_number[7];	

int main(){
	

	int id[7];//original student id
	char identity;//d = 大學 e = 進修 m = 碩士 p = 博士 
	int number,sum;//parity_bit = 檢查碼   number = 學號末七碼 
	int week;//週數 
	printf("請輸入身分字號(英文大小寫皆可系統將自動幫您轉換):");
	check_id();

		
	printf("請輸入學號(請輸入全學號，英文大小寫皆可系統將自動幫您轉換):");//input student id 
	scanf("%c%d",&identity,&number);
	identity = toupper(identity);//change lower to upper

	int g;
	for(g= 6;g>=0;g--){
		student_number[g] = number%10;// get all student id
		number = number / 10;
	}

	int i;
	for(i = 0;i <= 5; i++){
		if (i%3==1){
			id[i] = student_number[i];//save student id in id to prevent operate lost the id
			student_number[i] = student_number[i]*7;
			buffer[i] = student_number[i] % 10 + student_number[i] / 10;
		}
		else if (i%3==2){
			id[i] = student_number[i];
			student_number[i] = student_number[i]*6;
			buffer[i] = student_number[i] % 10 + student_number[i] / 10;
		}
		else if (i%3==0){
			id[i] = student_number[i];
			student_number[i] = student_number[i]*8;
			buffer[i] = student_number[i] % 10 + student_number[i] / 10;
		}
}
	int h;
	sum = 0;
	for(h = 0;h<6;h++){
		sum = sum+buffer[h];//plus all of the buffer
	}
	if (parity(sum)== 1){
			printf("welcome ");
			student_notice(identity);
			
	}
		
	else{
		printf("please check your id\n");
		exit(0);
	}
	is_odd(student_number[6]);
	int bmi;
	int guess_bmi;
	float weight;//體重
	float height;//身高
	printf("請輸入身高(m):");
	scanf("%f",&height);
	printf("請輸入體重(kg):");
	scanf("%f",&weight);
	bmi = bmi_test(weight,height);
	do {
		printf("guess what is your bmi!!(data type = int)\n");
		scanf("%d",&guess_bmi);
		guess_num(bmi,guess_bmi);
		if(guess_num(bmi,guess_bmi)==1)
			 printf( "Too low. Try again.\n ");
		else if(guess_num(bmi,guess_bmi)==2)
			 printf( "Too high. Try again.\n ");
		}
	while(guess_num(bmi,guess_bmi)!=0);
	printf("congratulation\n");
	congratulation();
	printf("-----以下是您的BMI結果-----\n");
	bmi_ans(bmi);
	
}
int check_id(void){
	//int idnum[26]={10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33}; //建表法
    char iid[12];
    iid[11]='\0';
    int z=0,tmp,total=0;
    for(z=0;z<11;z++)
        scanf("%c",&iid[z]);
//    if(iid[0]<='z'&& iid[0]>='a') 
//		iid[0]-=32; //小寫轉大寫 

    tmp=id_num(iid[0]);  //將英文字轉成數字
    //tmp=idnum[id[0]-'A'];//將英文字轉成數字<----第二種轉法-建表法
        total=(tmp%10)*9+tmp/10+(iid[1]-'0')*8+(iid[2]-'0')*7+(iid[3]-'0')*6+(iid[4]-'0')*5+(iid[5]-'0')*4+(iid[6]-'0')*3+(iid[7]-'0')*2+(iid[8]-'0')*1;
    if((10-total%10) ==(iid[9]-'0')){
	 
        printf("%s你好\n",iid);
        return 1;
        } 
    else{
	 
        printf("%s泥是黑戶口吧\n",iid);
		exit(0);
        
        } 
    }
int parity(int sum){
	
	int parity_bit = (10 - (sum % 10)) % 10;
	
		if (student_number[6] == parity_bit)
			return 1;
		else
			return 0;
			
}
void is_odd(int student_number){
	if (student_number % 2 ==0)
		printf("you are odd number student\n");
	else
		printf("you are even number student\n");

}
int id_num(char ch){
    switch(ch)
    {
        case 'A': return 10 ;break;   case 'P': return 23; break;
        case 'B': return 11 ;break;   case 'Q': return 24; break;
        case 'C': return 12 ;break;   case 'R': return 25; break;
        case 'D': return 13 ;break;   case 'S': return 26; break;
        case 'E': return 14 ;break;   case 'T': return 27; break;
        case 'F': return 15 ;break;   case 'U': return 28; break;
        case 'G': return 16 ;break;   case 'V': return 29; break;
        case 'H': return 17 ;break;   case 'W': return 32; break;
        case 'I': return 34 ;break;   case 'X': return 30; break;
        case 'J': return 18 ;break;   case 'Y': return 31; break;
        case 'K': return 19 ;break;   case 'Z': return 33; break;
        case 'L': return 20 ;break;   
        case 'M': return 21 ;break;   
        case 'N': return 22 ;break;   
        case 'O': return 35 ;break;
    }
}
void congratulation (void){
char pig[][60]={
    "                        /  `.             ",
    "                      ,'     `.           ",
    "       /`.________   (         :          ",
    "       \\          `. _\\_______  )       ",
    "        \\ `.----._  `.        \"`-.        ",
    "         )  \\     \\   `       ,\"__\\       ",
    "         \\   \\     )    ,--    (/o\\\\     ",
    "     (  _ `.  `---'     ,--.    \\ _)).      ",
    "      `(-',-`----'     ( (O \\    `--,\"`-.   ",
    "        `/              \\ \\__)    ,'   O )  ",
    "        /                `--'     (  O  ,'  ",
    "       (                           `--,'    ",
    "        \\                    `==  _.-'      ",
    "         \\              .____.-;-'          ",
    "   -hrr-  ) `._               /             ",
    "         (    |`-._\\    | ,' /              ",
    "          `.__|__/ \"\\   |'  /               ",
    "                     `._|_,'                "

};
int i ;
    for(i=0;i<=19;i++)
        printf("%s\n",pig[i]);
}
void student_notice(char identity){
	switch (identity){      //case to identity if student and have costomize notivication
        case 'D': 
        printf("FCU bachelor degree student:\n");//college degree
        break;
        case 'E':
        printf("FCU division of continuing education student:\n");
      	break;
        case 'M'://case master
        printf("FCU master degree student:\n");
		break;
        case 'P'://case PHD
        printf("FCU doctor degree student:\n");
        break;
        default:
        printf("can't recognize your id\n"); //can't recognize identity --->end it and ask to try again
        exit(0);
    }
}
int bmi_test (float weight,float height){
	int bmi;
	bmi = weight/(height*height);
	return bmi;
}
int guess_num(int bmi,int guess){
   if (guess == bmi)
      return 0;

   // guess is incorrect; display hint
   if (guess < bmi)
		return 1;
   else
     	return 2;
}

void bmi_ans(int bmi){
	if (bmi>=25)
	printf("請加測Body Fat!");
	else if(bmi>=23&&bmi<25)
	printf("再觀察1個月");
	else if(bmi>=18.5&&bmi<23)
	printf("無須檢查,此為正常範圍");
	else 
	printf("檢查是否營養不良");
}