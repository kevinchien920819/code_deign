//透過BMI測量近一步協助醫生檢定是否有肥胖問題可慮是否加測量度體脂(Body Fat)

#include<stdio.h>
int main(){
float bmi;//BMI
float weight;//體重
float height;//身高
printf("請輸入身高(m):");//輸入身高 單位:公尺
scanf("%f",&height);
printf("請輸入體重(kg):");//輸入體重 單位:公斤
scanf("%f",&weight);
bmi = weight/(height*height);
if (bmi>=25)
printf("請加測Body Fat!");
else if(bmi>=23&&bmi<25)
printf("再觀察1個月");
else if(bmi>=18.5&&bmi<23)
printf("無須檢查,此為正常範圍");
else 
printf("檢查是否營養不良");
}