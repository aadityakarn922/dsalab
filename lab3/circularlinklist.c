#include<stdio.h>
#include<stdlib.h>

struct CQ{
    int data;
    struct CQ * next;
};
typedef struct CQ Node;
Node *head;

void create(int A[],int n)
{
    int i;
    Node *t,*last;
    head=(Node*)malloc(sizeof(Node));
    head->data=A[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++)
    {
        t=(Node*)malloc(sizeof(Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }

}
void display(Node *p)
{
    if(p==NULL)
    {
        return;
    }
    do
    {
        printf("%d ",p->data);
        p=p->next;

        
    } while (p!=head);
    printf("\n");
    
}

int main()
{
    int A[]={1,3,5,6,7};
    create(A,5);
    display(head);
}