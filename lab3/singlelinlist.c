#include<stdio.h>
#include<stdlib.h>

struct SLL
{
    int data;
    struct SLL *next;
};
typedef struct SLL Node;

Node *first,*last=NULL;

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

void insert_at_begin(int element)
{
    Node *NewNode=create_node(element);
    if(NewNode!=NULL)
    {
        if(first==NULL)
            first=last=NewNode;
        else
        {
            NewNode->next=first;
            first=NewNode;
        }
        printf("%d inserted at beginning\n", element);
    }
}

void insert_at_end(int element)
{
    Node *NewNode=create_node(element);

    if(NewNode!=NULL)
    {
        if(first==NULL)
            first=last=NewNode;
        else
        {
            last->next=NewNode;
            last=NewNode;
        }
        printf("%d inserted at end\n", element);
    }
}

void traverse()
{
    Node *temp;
    if(first==NULL)
    {
        printf("the list is empty\n");
    }
    else
    {
        temp=first;
        printf("List: ");
        while(temp!=NULL)
        {
            printf("%d |",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

void delete_from_start()
{
    Node *temp;
    if(first==NULL)
    {
        printf("the list is empty\n");
    }
    else
    {
        temp=first;
        first=first->next;
        printf("%d deleted from start\n", temp->data);
        free(temp);

        
    }
}

void delete_from_end()
{
    Node *temp;

    if(first==NULL)
    {
        printf("list is empty\n");
        return;
    }

    if(first->next==NULL)   
    {
        printf("%d deleted from end\n", first->data);
        free(first);
        first=last=NULL;
    }
    else
    {
        temp=first;
        while(temp->next!=last)
        {
            temp=temp->next;
        }

        printf("%d deleted from end\n", last->data);
        free(last);
        last=temp;
        last->next=NULL;
    }
}

void insert_at_specificposn(int element,int pos)
{
    Node *temp;

    if(pos<=1 || first==NULL)
    {
        insert_at_begin(element);
        return;
    }

    temp=first;

    for(int i=1;i<pos-1 && temp->next!=NULL;i++)
    {
        temp=temp->next;
    }

    if(temp->next==NULL)
    {
        insert_at_end(element);
    } 
    else
    {
        Node *NewNode=create_node(element);
        NewNode->next=temp->next;
        temp->next=NewNode;
        printf("%d inserted at position %d\n", element, pos);
    }
}

void delete_at_specificposn(int pos)
{
    Node *temp, *ptr;

    if(first==NULL)
    {
        printf("list is empty\n");
        return;
    }

    if(pos==1)
    {
        delete_from_start();
        return;
    }

    temp=first;

    for(int i=1;i<pos-1 && temp->next!=NULL;i++)
    {
        temp=temp->next;
    }

    ptr=temp->next;
    temp->next=ptr->next;

    if(ptr==last)
    {
        last=temp;
    }

    printf("%d deleted from position %d\n", ptr->data, pos);
    free(ptr);
}


int main()
{
    insert_at_begin(3);
    traverse();

    insert_at_begin(8);
    traverse();

    insert_at_end(7);
    traverse();

    insert_at_end(6);
    traverse();

    delete_at_specificposn(3);
    traverse();

    return 0;
}