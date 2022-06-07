#include<stdio.h>

int main(){
	char student_number[7];
	char buffer[7];
	int parity_bit,number;
	int sum = 0;
	printf("請輸入學號後七碼:");
	scanf("%d",&number);
	int g;
	for(g= 6;g>=0;g--){
		student_number[g] = number%10;
		number = number/10;
	}
	int i,h;
	for(i = 0;i <= 5; i++){
		if (i%3==1){
			student_number[i] = student_number[i]*7;
			buffer[i] = student_number[i]%10+student_number[i]/10;
		}
		else if (i%3==2){
			student_number[i] = student_number[i]*6;
			buffer[i] = student_number[i]%10+student_number[i]/10;
		}
		else if (i%3==0){
			student_number[i] = student_number[i]*8;
			buffer[i] = student_number[i]%10+student_number[i]/10;
		}
	}
	for(h = 0;h<6;h++){
		sum = sum+buffer[h];
	}
	parity_bit = 10-(sum%10);
	if (parity_bit ==10)
	parity_bit=0;
	if (student_number[6] == parity_bit){
		printf("歡迎逢甲生\n");
	}
	else
	printf("你是輸入錯還是假逢甲人\n");
}

