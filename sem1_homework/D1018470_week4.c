#include<stdio.h>

int main(){
	int i,j,k;
	int head,body,tail;

	//check input = 0 0 0 or not
	for(i = 0; head != 0 || body != 0 || tail != 0; i++){
          scanf("%d %d %d", &head, &body, &tail);
        //head
        for(i = 0;i < head-1;i++){
        	for(j = head;j > i;j--)
				printf(".");
			//....
			//...
			//..
			//.
			if (i==0)//line 1 have only 1 *
				printf("*");
			else{
				printf("*");
				for(k = 0;k < (i-1)*2+1;k++)
					printf(".");
				printf("*");
				//  *.*
				// *...*
			}
        	for(j = head;j > i;j--)
				printf(".");
			//....
			//...
			//..
			//.
			if (i == head-2){
				printf("\n.");
				for(k = 0;k < head * 2 - 1;k++)
					printf("*");
				printf(".\n");
				break;
			}
		printf("\n");
		}
		 //body
    	for(i = 0;i < body;i++){
    		printf("..");//..
    		for(j = 0;j < head * 2 - 3;j++)
    			printf("*");
    		printf("..\n");
		}
		//tail
		for(i = 0; i < tail ;i++){
			for(j = 0;j < head-1;j++)
				printf(".");
			printf("***");
			for(k = 0;k < head-1;k++)
				printf(".");
			printf("\n");
		}
}

}
