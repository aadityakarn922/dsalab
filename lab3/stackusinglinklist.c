#include<stdio.h>
#include<stdlib.h>

struct SLL
{
    int data;
    struct SLL *next;
};
typedef struct SLL Node;

Node *top;

Node * create_node(int element)
{
    Node *NewNode=(Node*)malloc(sizeof(Node));
    if(NewNode!=NULL)
    {
        NewNode->data=element;
        NewNode->next=NULL;
    }
    return NewNode;
}
void push(int element)
{
    Node *Newnode=create_node(element);
    if(top==NULL)
    {
        top=Newnode;

    }
    else
    {
        Newnode->next=top;
        top=Newnode;
    }
    printf("%d was pushed \n",element);
    
}
void pop()
{
    Node *temp;
    if(top==NULL)
    {
        printf("stack underflow");
    }
    else if(top->next==NULL)
    {
        temp=top;
        top=NULL;
        free(temp);
        
    }
    else
    {
        temp=top;
        top=top->next;
        int val=temp->data;
        free(temp);
        printf("%d was popped\n",val);
    }

    
}
int main()
{
    push(4);
    push(8);
    pop();
}