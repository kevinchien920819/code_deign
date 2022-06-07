#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    FILE *ptr; //set a pointer for file
    char filename[10], buf[100];//the file name and buf
    scanf("%s", filename);
    if ((ptr = fopen(filename, "a+")) == NULL)// open the  file and the mode is r+
        exit(1);//if can't open then quit 
    int type; //1 or 2
    char name[20] = {};//protype for name
    char phone[20] = {};//protype for phone
    char birth[20] = {};//protype for birth
    printf("請問你要 1. 輸出好友名單 2. 新增好友資料:\n");
    printf("===============\n");
    while (scanf("%d", &type) != EOF)//read untill there has no more action
    {
        if (type == 1)
        {
            rewind(ptr);//reset the pointer to the file top
            fscanf(ptr,"%s", name);//read some one's name
            fscanf(ptr,"%s", phone);//read some one's phone
            fscanf(ptr,"%s", birth);//read some one's birth
	    while(feof(ptr)==0){
	        printf("%s的電話是:%s\n",name,phone);
	        printf("%s的生日是:%s\n",name,birth);
            printf("===============\n");
            fscanf(ptr,"%s", name);//read some one's name
            fscanf(ptr,"%s", phone);//read some one's phone
            fscanf(ptr,"%s", birth);//read some one's birth
	    }
        }
        if (type == 2)//type == 2 means wants to add new person's info
        {
	    fseek (ptr,0,SEEK_END);
            printf("請輸入姓名:");
            scanf("%s", name);
            fprintf(ptr, "%s ", name);//write in the file
            printf("請輸入電話號碼:");
            scanf("%s", phone);
	    fprintf(ptr, "%s ", phone); //write in the file 
            printf("請輸入生日:");
            scanf("%s", birth);
            fprintf(ptr, "%s\n", birth);//write in the file
    	}
	    printf("請問你要 1. 輸出好友名單 2. 新增好友資料:\n");
    }
    fclose(ptr);//close the file
}
