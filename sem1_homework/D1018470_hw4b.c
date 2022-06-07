#include<stdio.h>
#include<stdlib.h>

int main(){
	long int id = 700000;
	int s1,s2,s3,s4,s5,s6,s7;
	int even = 0;
	int odd = 0;
	int i,prity;
	for(i = 0 ; id <=1099999 ; id++){
		s1 = id / 1000000 * 8;
		s2 = id % 1000000 / 100000 * 7;
		s3 = id % 100000 / 10000 * 6;
		s4 = id % 10000 / 1000 * 8;
		s5 = id % 1000 / 100 * 7;
		s6 = id % 100 / 10 * 6;
		s7 = id % 10;
		prity = s1 % 10 + s1 / 10 + s2 % 10 +s2 / 10 + s3 % 10 + s3 / 10 + s4 % 10 + s4 / 10 +s5 % 10 + s5 / 10 + s6 % 10 + s6 / 10 ;
		if ((10-(prity%10))%10 == s7)
			if (id % 2 == 0){
				even ++;
			}
			else{
				odd++;
			}
	}
	printf("odd number:%d\neven number:%d",odd,even);
	system ("pause");
	return 0 ;
}