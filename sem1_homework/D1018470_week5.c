#include<stdio.h>
int cola (int);
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){		//input glass
	printf("%d\n",cola(n));	
	}
 }
 
 int cola(int glass){
 	int temp;
 	int only;
 	int ans = glass;
	while(glass / 3 >=1){//check glass can change new cola
	temp = glass/3; //change glass
	only = glass % 3; //null glass
	glass = temp + only;
	ans = ans + temp;
	if(glass == 2) //check if can borrow one and ans + 1
		ans+=1;
	}
	
	 return ans;
 }
