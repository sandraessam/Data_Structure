#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct Tree Tree;

struct Node
{
    int Data;
    Node *Left, *Right;
};

struct Tree
{
    Node *root;
};

Tree* CreateTree()
{
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    tree->root = NULL;

    return tree;
}

Node* CreateNode(int data)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->Data = data;
    node->Left = node->Right = NULL;

    return node;
}

void Add(Tree *tree, int data)
{
    Node *node = CreateNode(data);

    if(tree->root == NULL)
    {
        tree->root = node;
    }
    else
    {
        Node *current = tree->root;
        Node *parent;

        while(current != NULL)
        {
            parent = current;

            if(data > current->Data)
                current = current->Right;
            else
                current = current->Left;
        }

        if(data > parent->Data)
            parent->Right = node;
        else
            parent->Left = node;
    }
}

Node* GetNodeByData(Tree *tree, int data)
{
    Node *current = tree->root;

    while(current != NULL)
    {
        if(data == current->Data)
            return current;

        if(data > current->Data)
            current = current->Right;
        else
            current = current->Left;

    }

    return NULL;
}

Node* GetParent(Tree *tree, Node *node)
{
    Node *parent = tree->root;

    while(parent != NULL)
    {
        if(parent->Left == node || parent->Right == node)
            return parent;

        if(node->Data > parent->Data)
            parent = parent->Right;
        else
            parent = parent->Left;
    }

    return NULL;
}

Node* GetMaxRight(Node *node)
{
    Node *current = node;

    while(current->Right != NULL)
        current = current->Right;

    return current;
}

void Remove(Tree *tree, int data)
{
    Node *node = GetNodeByData(tree, data);

    if(node == NULL)
        return;

    if(node == tree->root)
    {
        if(tree->root->Left == NULL && tree->root->Right == NULL)
        {
            tree->root = NULL;
        }
        else if(tree->root->Right == NULL)
        {
            tree->root = tree->root->Left;
        }
        else if(tree->root->Left == NULL)
        {
            tree->root = tree->root->Right;
        }
        else
        {
            Node *newRoot = tree->root->Left;
            Node *maxRight = GetMaxRight(newRoot);
            maxRight->Right = tree->root->Right;
            tree->root = newRoot;
        }
    }
    else
    {
        Node *parent = GetParent(tree, node);
        Node *newChild;

        if(node->Left == NULL && node->Right == NULL)
        {
            newChild = NULL;
        }
        else if (node->Right == NULL)
        {
            newChild = node->Left;
        }
        else if (node->Left == NULL)
        {
            newChild = node->Right;
        }
        else
        {
            Node *newParent = node->Left;
            Node *maxRight = GetMaxRight(newParent);
            maxRight->Right = node->Right;

            newChild = newParent;
        }

        if(parent->Left == node)
            parent->Left = newChild;
        else
            parent->Right = newChild;
    }

    free(node);
}

void Display(Node *node)
{
    if(node == NULL)
        return;

    Display(node->Left);
    printf("%d \t", node->Data);
    Display(node->Right);
}
int GetMaxRightLevel(Node *node)
{
    Node *current = node;
    int MaxRight=0;

    while(current->Right != NULL)
    {
        current = current->Right;
        MaxRight++;
    }

    return MaxRight;
}
int GetMaxLeftLevel(Node *node)
{
    int MaxLeft=0;
    Node *current=node;
    while(current->Left!=NULL)
    {
        current=current->Left;
        MaxLeft++;
    }
    return MaxLeft;
}
int Count(Node *node,int* max)
{
    static int count=0;
    if(node == NULL)
        return count;
    else
        count++;
    if(*max<count){
        *max=count;
    }
    Count(node->Left,max);
    Count(node->Right,max);
    count--;
}
int GetMaxDepth(Tree *tree)
{
     int max=0;
    Node *node = tree->root;
    if(node == NULL)
        return 0;
    Count(node,&max);
return max;
}

int main()
{
    Tree *tree = CreateTree();

    Add(tree, 50);
    Add(tree, 40);
    Add(tree, 30);
    Add(tree, 45);
    Add(tree, 48);
    Add(tree, 49);
    Add(tree, 60);
    Add(tree, 80);
    Add(tree, 90);


    Display(tree->root);
     printf("\n%d\n",GetMaxDepth(tree));

    return 0;
}
