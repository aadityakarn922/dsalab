#include<stdio.h>
#include<stdlib.h>

struct que
{
    int data;
    struct que *next;
};
typedef struct que Node;

Node *front,*rear=NULL;

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
void enqueue(int element)
{
    Node *NewNode=create_node(element);
    if(front==NULL)
    front=rear=NewNode;
    else
    {
        rear->next=NewNode;
        rear=NewNode;
    }
     printf("%d  entered\n",element);
    
       
   
    
}
void dequeue()
{
    Node *temp;
    if(front==NULL)
    {
        printf("queue is empty");
        return;

    }
    else if(front->next==NULL)
    {
        temp=front;
        front=rear=NULL;
        free(temp);
    }
    else
    {
        temp=front;
        front=front->next;
        int val=temp->data;
        free(temp);
        printf("%d removed \n",val);
            
        
    }
    
}
int main()
{
    enqueue(8);
    enqueue(5);
    dequeue();
    return 0;
}