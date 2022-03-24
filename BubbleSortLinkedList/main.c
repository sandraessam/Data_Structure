#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
typedef struct LinkedList LinkedList;

struct Node
{
    int Data;
    Node *Prev, *Next;
};
struct LinkedList
{
    Node *Head,*Tail;
};
void swap(int* first,int* second)
{
    int temp;
    temp=*first;
    *first=*second;
    *second=temp;
}
void Swap(LinkedList* List,Node* first,Node* second)
{
    int flag=0;
    Node* current=List->Head;
    while(current!=NULL)
    {
        if(first==current)
        {
            break;
        }
        else if(second==current)
        {
            flag=1;
        }

        current=current->Next;

    }
    if(flag==1)
    {
        swap(&first,&second);
    }
    if(first==List->Head)
    {
        if (second==List->Head)
        {
            List->Head=first;
            second->Next->Prev=first;
        }
        else if(second==List->Tail)
        {
            List->Tail=first;
        }
        else
        {

            second->Next->Prev=first;
        }
        List->Head=second;
    }
    else if(first==List->Tail)
    {
        if (second==List->Head)
        {
            List->Head=first;
            second->Next->Prev=first;
        }
        else if(second==List->Tail)
        {
            List->Tail=first;
        }
        else
        {
            second->Next->Prev=first;
        }
        List->Tail=second;
        first->Prev->Next=second;
    }
    else
    {
        if (second==List->Head)
        {
            List->Head=first;
            second->Next->Prev=first;
        }
        else if(second==List->Tail)
        {
            List->Tail=first;
        }
        else
        {
            second->Next->Prev=first;
        }
        first->Prev->Next=second;
    }




    first->Next=second->Next;
    second->Prev=first->Prev;
    first->Prev=second;
    second->Next=first;
}



void BubbleSort(int* arr,int size)
{
    int index,counter,sorted=0;
    for(counter=0; counter<size-1 && sorted==0; counter++)
    {
        sorted=1;
        for(index=0; index<size-1-counter; index++)
        {
            if(arr[index]>arr[index+1])
            {
                swap(&arr[index],&arr[index+1]);
                sorted=0;
            }
        }

    }
}
Node* createNode (int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); //to put it on heap
    newNode->Data=data;
    newNode->Prev=newNode->Next=NULL;
    return newNode;
}
void Add (LinkedList *list,int data)
{
    Node *newNode = createNode(data);
    if(list->Head == NULL)
    {
        list->Head=list->Tail=newNode;

    }
    else
    {
        list->Tail->Next=newNode;
        newNode->Prev=list->Tail;
        list->Tail=newNode;
    }
}
void Display(LinkedList list)
{
    Node *current = list.Head;
    while(current != NULL)
    {
        printf("%d \t",current->Data);
        current=current->Next;
    }
}
void BubbleSortLinked(LinkedList* List)
{
    Node* index,*counter,* Limit=List->Tail;
    int sorted=0;
    for(counter=List->Head; (counter!= List->Tail)&& sorted==0; counter=counter->Next)
    {
        sorted=1;

        for(index=List->Head; index<Limit; index=index->Next)
        {
            if(index->Data>index->Next->Data)
            {
                swap(index,index->Next);
                sorted=0;
            }
        }
    }
}

int BinarySearch(int data,LinkedList* List,Node** current)
{
    int minIndex=0,maxIndex=0,midIndex,count;
    *current=List->Head;
    while(*current!=List->Tail){
        maxIndex++;
        *current=(*current)->Next;
    }
    while(minIndex<=maxIndex )
    {

        midIndex=(minIndex+maxIndex)/2;
        count=midIndex;
        *current=List->Head;
        while(count!=0)
        {
            *current=(*current)->Next;
            count--;
        }
        if(data==(*current)->Data)
        {
            return midIndex;
        }
        else if(data>(*current)->Data)
        {
            minIndex=midIndex+1;
        }
        else
        {
            maxIndex=midIndex-1;
        }
    }
    *current=NULL;
    return -1;
}
int main()
{
    LinkedList myList;
    myList.Head = myList.Tail = NULL;
    Add(&myList,5);
    Add(&myList,10);
    Add(&myList,14);
    Add(&myList,13);
    Add(&myList,11);
    Display(myList);
    Swap(&myList,(myList.Head->Next),(myList.Head));
    printf("\nSwapped List\n");
    Display(myList);
    BubbleSortLinked(&myList);
    printf("\nSorted List\n");
    Display(myList);
    int index;
    Node* node;
    index= BinarySearch(13,&myList,&node);
    printf("\n");
    if(node==NULL){printf("the number isn't in this list \n");}
    else{printf("the number %d is in index %d\n",node->Data,index);}

    return 0;
}
