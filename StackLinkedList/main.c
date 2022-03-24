#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
typedef struct Stack Stack;

struct Node
{
    int Data;
    Node *Prev, *Next;
};
struct Stack
{

    Node* top;
};

Node* createNode (int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); //to put it on heap
    newNode->Data=data;
    newNode->Prev=newNode->Next=NULL;
    return newNode;
}
Stack* CreateStack(void)
{

    Stack*p=(Stack*)malloc(sizeof(Stack));
    p->top=NULL;
    return p;
}

void push(Stack* stk,int data)
{
    Node* node=createNode (data);
    if(!IsEmpty(stk))
        stk->top->Next=node;
    node->Prev=stk->top;
    stk->top=node;
}
int pop(Stack* stk,int* data)
{
    if(IsEmpty(stk))
        return 0;
    *data=stk->top->Data;
    Node* node=stk->top;
    stk->top=stk->top->Prev;
    free(node);
    return 1;
}
int IsEmpty(Stack* stk)
{
    return stk->top == NULL;
}
int main()
{
    Stack* mystk= CreateStack();
    push(mystk,5);
    push(mystk,8);
    push(mystk,9);
    int num;
    if(pop(mystk,& num))
    {
        printf("%d\n",num);
    }
    else
    {

    }

    return 0;
}
