#include <stdio.h>
#include <stdlib.h>

#define NormalQueue 0
#define QueueShifting 1
#define QueueCircular 2

#define Queue_Method QueueCircular
typedef struct Queue Queue;

struct Queue
{

    int* arr;
    int size,front,rear;
};
Queue* CreateQueue(int size)
{

    Queue*p=(Queue*)malloc(sizeof(Queue));
    p->size=size;
    p->arr=(int*)malloc(size*sizeof(int));
    p->front=p->rear=-1;
    return p;
}
void EnQueue(Queue* que,int data)
{
    if(IsFull(que))
    {
        return;
    }
    if(IsEmpty(que))
        que->front++;
    que->rear++;
    que->arr[que->rear]=data;
}
int DeQueue(Queue* que,int* data)
{
    if(IsEmpty(que))
        return 0;
    *data=que->arr[que->front];
    if(que->front==que->rear)
        que->front=-1;
    else
        que->front++;
    return 1;
}
int IsEmpty(Queue* que)
{
    return que->front==-1  ;
}
int DeQueueShifting(Queue* que,int* data)
{
    int counter=0;
    if(IsEmpty(que))
        return 0;
    *data=que->arr[que->front];
    while(counter!=que->rear)
    {
        que->arr[counter]=que->arr[counter+1];
        counter++;
    }
    que->rear--;
    if(que->rear==-1)
        que->front=-1;
    return 1;
}
void EnQueueCircluar(Queue *que, int data)
{
    if(IsFull(que))
        return;

    if(IsEmpty(que))
        que->front++;

    if(que->rear == que->size-1 && que->front!=0)
    {
        que->rear=0;
    }
    else
    {
        que->rear++;
    }
    que->arr[que->rear]=data;
}

int DeQueueCircluar(Queue *que, int *data)
{
    if(IsEmpty(que))
        return 0;

    *data = que->arr[que->front];

    if(que->front == que->rear)
    {
        que->front = que->rear =-1;
    }
    else
    {
        que->front++;
        if(que->front == que->size)
            que->front =0;
    }

    return 1;
}

int IsFull(Queue *que)
{
    if (que->front==0 )
        return (que->rear == que->size-1) ;
    else
        return (que->front - que->rear == 1);
}

int main()
{
      int num,flag=0;
    Queue* myque= CreateQueue(5);
    #if Queue_Method == QueueCircular
    EnQueueCircluar(myque,5);
    EnQueueCircluar(myque,8);
    EnQueueCircluar(myque,9);
    EnQueueCircluar(myque,1);
    EnQueueCircluar(myque,12);
    DeQueueCircluar(myque,& num);

    EnQueueCircluar(myque,13);
    EnQueueCircluar(myque,15);
    while(flag==0){
    if(DeQueueCircluar(myque,& num))
    {
        printf("%d\n",num);
    }
    else
    {
        flag=1;
    }}
    #elif Queue_Method == QueueShifting
    EnQueue(myque,5);
    EnQueue(myque,8);
    EnQueue(myque,9);
    EnQueue(myque,1);
    EnQueue(myque,12);
    DeQueueShifting(myque,& num);
    EnQueueCircluar(myque,13);
    EnQueueCircluar(myque,15);
     while(flag==0){
    if(DeQueueShifting(myque,& num))
    {
        printf("%d\n",num);
    }
    else
    {
        flag=1;
    }}
    #endif



    return 0;
}
