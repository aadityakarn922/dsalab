#include<stdio.h>
#include<stdlib.h>
struct SLL
{
    int data;
    struct SLL *next;
};
struct SLL *first,*last = NULL;
struct SLL* create_node(int element)
{
    struct SLL *NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    NewNode->data = element;
    NewNode->next = NULL;
    return NewNode;

}
void insert_at_beginning(int element)
{
    struct SLL *NewNode = create_node(element);
    if(first == NULL) //i.e List is Empty
        first = last = NewNode;
    else
    {
        NewNode->next = first;
        first = NewNode;
    }
    printf("%d INSERTED AT BEGINNING\n",element);
}
void insert_at_end(int element)
{
    struct SLL *NewNode = create_node(element);
    if(first == NULL) //i.e List is Empty
        first = last = NewNode;
    else
    {
        last->next = NewNode;
        last = NewNode;
    }
    printf("%d INSERTED AT END\n",element);
}
void traverse()
{
    struct SLL *temp;
    if(first == NULL) //i.e List is Empty
        printf("EMPTY LIST\n");
    else
    {
        temp = first;
        while(temp!=NULL)
        {
            printf("%d | ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    insert_at_beginning(100);
    traverse();
    insert_at_beginning(200);
    traverse();
    insert_at_end(300);
    traverse();
    insert_at_end(400);
    traverse();
    return 0;
}