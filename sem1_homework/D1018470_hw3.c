#include<stdio.h>
#include<time.h>
#include <ctype.h>

int main(){
	char student_number[7];	
	char buffer[7];//operate buffer
	char id[7];//original student id
	char identity;//d = 大學 e = 進修 m = 碩士 p = 博士 
	int parity_bit,sum,number;//parity_bit = 檢查碼   number = 學號末七碼 
	int week;//週數 
	time_t seconds;//
    seconds = time(NULL);
    week = (seconds / 3600 / 24 -3) / 7 - 2696;//from 1970 1/1 seconds  2696= week from 1970 1/1 to 2021 9/13

	printf("請輸入學號(請輸入全學號，英文大小寫皆可):");//input student id 
	scanf("%c%d",&identity,&number);
	identity = toupper(identity);//change lower to upper
	int g;
	for(g= 6;g>=0;g--){
		student_number[g] = number%10;// get all student id
		number = number/10;
	}
	int i;
	for(i = 0;i <= 5; i++){
		if (i%3==1){
			id[i] = student_number[i];//save student id in id to prevent operate lost the id
			student_number[i] = student_number[i]*7;
			buffer[i] = student_number[i]%10+student_number[i]/10;
		}
		else if (i%3==2){
			id[i] = student_number[i];
			student_number[i] = student_number[i]*6;
			buffer[i] = student_number[i]%10+student_number[i]/10;
		}
		else if (i%3==0){
			id[i] = student_number[i];
			student_number[i] = student_number[i]*8;
			buffer[i] = student_number[i]%10+student_number[i]/10;
		}
	
	}
	int h;
	sum = 0;
	for(h = 0;h<6;h++){
		sum = sum+buffer[h];//plus all of the buffer
	}
	parity_bit = 10-(sum%10);//parity bit = last bit of student id
	if (parity_bit == 10)//parity bit =10  1 will lost because of overflow
	parity_bit = 0;
	if (student_number[6] == parity_bit){//id check
		printf("歡迎逢甲生\n");
	}
	else//if id wrong 
	{
	printf("你是輸入錯還是假逢甲人\n");
	return 0;
	}
	int in_school_year = id[0]*10+id[1];//count the year student enter school
	if (in_school_year<50)//a.d. 1961 fcu start so if before it ----> +100
	in_school_year +=100;
	int graduate_year = in_school_year+4;
	switch (identity){      //case to identity if student and have costomize notivication
        case 'D': 
        printf("逢甲大學生你好:\n");//college degree
        break;
        case 'E':
        printf("逢甲進修生你好:\n");
        printf("你的入學年分:%d\n",in_school_year);
		printf("你的畢業年分:%d\n",graduate_year);
		printf("本周為第%d周",week);
		if (student_number[6]%2==1&&week%2==1)
		printf("你是單號,本周實體上課");
		if (student_number[6]%2==0&&week%2==1)
		printf("你是雙號,本周線上上課");
		if (student_number[6]%2==1&&week%2==2)
		printf("你是單號,本周線上上課");
		if (student_number[6]%2==0&&week%2==2)
		printf("你是雙號,本周實體上課");
        return 0;
        case 'M'://case master
        printf("逢甲碩士生你好:\n");
        printf("你的入學年分:%d\n",in_school_year);
		printf("你的畢業年分:%d\n",graduate_year);
		printf("本周為第%d周",week);
		if (student_number[6]%2==1&&week%2==1)
		printf("你是單號,本周實體上課");
		if (student_number[6]%2==0&&week%2==1)
		printf("你是雙號,本周線上上課");
		if (student_number[6]%2==1&&week%2==2)
		printf("你是單號,本周線上上課");
		if (student_number[6]%2==0&&week%2==2)
		printf("你是雙號,本周實體上課");
		return 0;
        case 'P'://case PHD
        printf("逢甲博士生你好:\n");
        printf("你的入學年分:%d\n",in_school_year);
		printf("你的畢業年分:%d\n",graduate_year);
		printf("本周為第%d周",week);
		if (student_number[6]%2==1&&week%2==1)
		printf("你是單號,本周實體上課");
		if (student_number[6]%2==0&&week%2==1)
		printf("你是雙號,本周線上上課");
		if (student_number[6]%2==1&&week%2==2)
		printf("你是單號,本周線上上課");
		if (student_number[6]%2==0&&week%2==2)
		printf("你是雙號,本周實體上課");
        return 0;
        default:
        printf("無法辨認身份請重新輸入\n"); //can't recognize identity --->end it and ask to try again
        return 0;
    }
	printf("你的入學年分:%d\n",in_school_year);
	printf("你的畢業年分:%d\n",graduate_year);
	printf("你的入學方式為:");
	if (id[2]>=0&&id[2]<=4)
		printf("特殊選材//繁星推薦//海外申請\n");
	else if (id[2]>=5&&id[2]<=8)
		printf("申請入學//四技二專徵選\n");
	else if (id[2]==9)
		printf("考試入學\n");

    printf("本周為第%d周",week);
	if (student_number[6]%2==1&&week%2==1)
	printf("你是單號,本周實體上課");
	if (student_number[6]%2==0&&week%2==1)
	printf("你是雙號,本周線上上課");
	if (student_number[6]%2==1&&week%2==2)
	printf("你是單號,本周線上上課");
	if (student_number[6]%2==0&&week%2==2)
	printf("你是雙號,本周實體上課");
	}
		

