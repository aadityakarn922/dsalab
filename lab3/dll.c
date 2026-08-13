#include<stdio.h>
#include<stdlib.h>

struct DLL
{
    int data;
    struct DLL * next;
    struct DLL *prev;


};
typedef struct DLL Node;
Node *first,*last=NULL;

Node * create_node(int element)
{
    Node *Newnode=(Node*)malloc(sizeof(Node));
    if(Newnode!=0)
    {
        Newnode->data=element;
        Newnode->next=NULL;
        Newnode->prev=NULL;
    }
    return Newnode;

}
void forward_traverse()
{
    Node *temp=first;
    if(first==NULL)
    {
        printf("list is empty");
    }
    while(temp!=NULL)
    {
        printf("%d |",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void backward_traverse()
{
     if(first==NULL)
    {
        printf("list is empty");
    }
    Node *temp=last;
    while(temp!=NULL)
    {
        printf("%d |",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}
void insert_atbeginning(int element)
{
    Node *Newnode=create_node(element);
    if(first==NULL)
    {
        first=last=Newnode;
    }
    else
    {
        Newnode->next=first;
        first->prev=Newnode;
        first=Newnode;
    }
    
}
void insert_atend(int element)
{
    Node *Newnode=create_node(element);
    if(first==NULL)
    {
        first=last=Newnode;
    }
    else
    {
        last->next=Newnode;
        Newnode->prev=last;
        last=Newnode;
    }
    
}
void insert_atspecificposn(int pos,int element)

{
    Node *temp=first;
    if(first==NULL)
    {
        printf("list is empty\n");
        return;
    }
    if(pos==1)
    {
        insert_atbeginning(element);
        return;


    }
    for(int i=1;i<pos-1&&temp->next!=NULL;i++)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        insert_atend(element);
        return;
    }
    else
    {
        Node *Newnode=create_node(element);
        Newnode->next=temp->next;
        Newnode->prev=temp;
        temp->next = Newnode;
        (Newnode->next)->prev=Newnode;
       
        
        printf("%d is inserted at position %d: \n",element,pos);

        
    }
    

    

}
void delete_frombeginining()
{
    Node *temp;

   
    if(first==NULL)
    {
        printf("the list is empty");
        return;

    }
    else if(first->next==NULL)
    {
        temp=first;
        first=last=NULL;
        free(temp);

    }
    else
    {
        temp=first;
        first=first->next;
        first->prev=NULL;
        free(temp);
    }
    



}
void delete_formend()
{
    Node *temp;
    if(first==NULL)
    {
        printf("list is empty");
        return;

    }
    else if(first->next==NULL)
    {
        temp=first;
        first=last=NULL;
        free(temp);

    }
    else{
        temp=last;
        last=last->prev;
        last->next=NULL;
        free(temp);
    }
    

}
void delete_fromspecificposn(int pos)
{
    Node *temp=first;
    if(first==NULL)
    {
        printf("list is empty\n");
        return;
    }
    if(pos==1)
    {
        delete_frombeginining();
        return;
        
        

    }
    for(int i=1;i<pos-1&&temp->next!=NULL;i++)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        delete_formend();
        return;
        
    }
    
    
    Node *ptr=temp->next;
    temp->next=ptr->next;
    if(ptr->next!=NULL)
    {
      ptr->next->prev=temp;
        
    }
    else
    {
        
        last=temp;
    }
    int val=ptr->data;
    free(ptr);
    printf("%d is deleted from %d \n",val,pos);
    
        
    
        
    
    

}



int main()
{
    insert_atbeginning(9);
    insert_atbeginning(6);
    insert_atend(45);
    insert_atend(8);
    insert_atspecificposn(4,3);
    insert_atspecificposn(2,7);
    delete_frombeginining();
    delete_formend();
    delete_fromspecificposn(2);

    forward_traverse();
    backward_traverse();

}