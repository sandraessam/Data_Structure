#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Queue Queue;
struct Node
{
    int Data;
    Node *Prev, *Next;
};
struct Queue
{

    Node* front;
    Node* rear;
};
Node* createNode (int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); //to put it on heap
    newNode->Data=data;
    newNode->Prev=newNode->Next=NULL;
    return newNode;
}
Queue* CreateQueue(void)
{

    Queue*p=(Queue*)malloc(sizeof(Queue));
    p->front=p->rear=NULL;
    return p;
}
void EnQueue(Queue* que,int data)
{
    Node* node=createNode (data);
    if(IsEmpty(que))
        que->front=node;
    else
        que->rear->Next=node;
    node->Prev=que->rear;
    que->rear=node;
}
int DeQueue(Queue* que,int* data)
{
    if(IsEmpty(que))
        return 0;
    *data=que->front->Data;
    Node* node=que->front;
    que->front=que->front->Next;
    free(node);
    return 1;
}

int IsEmpty(Queue* que)
{
    return que->front==NULL;
}

int main()
{
    Queue* myque= CreateQueue();
    EnQueue(myque,5);
    EnQueue(myque,8);
    EnQueue(myque,9);
    EnQueue(myque,1);
    EnQueue(myque,12);
    int num;
    if(DeQueue(myque,& num))
    {
        printf("%d\n",num);
    }
    else
    {

    }
    return 0;
}
