#include<stdlib.h>
#include<stdio.h>
//def structure type
typedef struct Node
{
    int data;
    struct Node *next;
}Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
}Queue;

/** initialize your data structure here. */
Queue* Create() {
    Queue *head = malloc(sizeof(Queue));
    head->front = NULL;
    head->rear = NULL;
    return head;
}
/** Inserts an element x into the Queue.*/
void EnQueue(Queue* obj, int x) {
   Node *temp = malloc(sizeof(Node));//make a temp linkes list to store the new data
   temp->data = x;//temp data to x
   temp->next = NULL;//temp next point to null

    //not the first data in queue then the next of the buttom data is temp 
   if(obj->rear != NULL){
       obj->rear->next = temp;
       obj->rear = temp;
   }
   else{
        //if the obj is empty we must define where the front and rear pointer is 
        //because there is no data so x is the first and the last data so front and rear pointer will point at temp 
        obj->front = temp;
        obj->rear = temp;
   }

}
/** Deletes an element from the Queue. If the queue is empty, return -1.*/
int DeQueue(Queue* obj) {
    //check the front has element or not if not return -1
    if(obj->front != NULL){
        //remember the delete element value
        int val = obj->front->data;
        //change the front to next element that means the first value will missing  
        obj->front = obj->front->next;
        //if after dequeue obj will be null then reset the rear pointer
        if(obj->front == NULL)
            obj->rear = NULL;
        //return the delete val
        return val;
         
    }
    else
        return -1;

}
/**Gets the front item from the queue. If the queue is empty, return -1.*/
int GetFront(Queue* obj) {
    //get the first element if there has data or return -1
	if(obj->front != NULL){
        return obj->front->data;
    }
    else
        return -1;
}

//clear the queue
int QueueEmpty(Queue* obj) {
	return (obj->front == NULL); 
}

//print the queue
void QueuePrint(Queue *obj)
{   
    //to prevent the front pointer change place make a temp ndoe 
    Node *temp = obj->front;
    //if there has data print it and move pointer to next element
    while(temp != NULL){
        printf("%d ", temp-> data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Queue* queue = Create();
    int count, num, t;
    scanf("%d", &count);
    while (count--) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d", &num);
            EnQueue(queue, num);
        } else if (t == 2) {
            DeQueue(queue);
        } else if (t == 3) {
            printf("%d\n", GetFront(queue));
            continue;
        } else if (t == 4) {
            printf("%d\n", QueueEmpty(queue));
            continue;
        }
        QueuePrint(queue);
    }
    system("pause");
    return 0;
}