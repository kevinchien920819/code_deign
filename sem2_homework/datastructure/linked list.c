#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
    int val;
    struct ListNode *next;
}ListNode;
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode head;
    head.next = NULL;
    struct ListNode *h = &head;
    
    if (!list1  && !list2 )
        return NULL;
    if(list1 == NULL)
        return list2;
    if(list2 == NULL)
        return list1;

    while(list1 && list2){
        if(list1 -> val <= list2 -> val){
            h -> next = list1;
            list1 = list1 -> next;
            
        }
        
        else if(list2-> val <= list2 -> val){
            h -> next = list2;
            list2 = list2 -> next;
            
        }
        h = h -> next;
        
    }
    
    if(list1)
        h -> next = list1;
    if(list2)
        h -> next = list2;
    
    return head.next;
}

int main(){
int x;
ListNode* prev;
printf("List1: ");
ListNode * list1 = NULL;
while(scanf("%d",&x) != EOF && x != -1 ){
    ListNode *newdata = (ListNode *)malloc(sizeof(ListNode));
    newdata->next = NULL;
    newdata->val = x;
    if(list1 == NULL){
        list1 = newdata;
    }
    else{
        prev->next = newdata;
    }
    prev = newdata;
}
ListNode * list2 = NULL;
printf("List2: ");
while(scanf("%d",&x) !=EOF && x != -1){
    ListNode *newdata = (ListNode *)malloc(sizeof(ListNode));
    newdata->next = NULL;
    newdata->val = x;
    if(list2 == NULL)
        list2 = newdata;
    else
        prev->next = newdata;
    prev =  newdata;

}
    ListNode* mergedList = mergeTwoLists(list1, list2);

    printf("merge: ");
    while (mergedList != NULL) {
        printf("%d ", mergedList->val);
        mergedList = mergedList->next;
    }
    system("pause");
    return 0;
}
