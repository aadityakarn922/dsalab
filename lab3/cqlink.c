#include <stdio.h>
#include <stdlib.h>

struct CQ
{
    int data;
    struct CQ *next;
};

typedef struct CQ Node;

Node *head = NULL;

int length(Node *p)
{
    int len = 0;

    if (p == NULL)
        return 0;

    do
    {
        len++;
        p = p->next;
    } while (p != head);

    return len;
}

void create_node(int A[], int n)
{
    Node *t, *last;

    head = (Node *)malloc(sizeof(Node));
    head->data = A[0];
    head->next = head;

    last = head;

    for (int i = 1; i < n; i++)
    {
        t = (Node *)malloc(sizeof(Node));
        t->data = A[i];
        t->next = head;
        last->next = t;
        last = t;
    }
}

void display(Node *p)
{
    if (p == NULL)
        return;

    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);

    printf("\n");
}

void insert(Node *p, int index, int x)
{
    Node *t;
    int i;

    if (index < 0 || index > length(head))
        return;

    t = (Node *)malloc(sizeof(Node));
    t->data = x;

    if (index == 0)
    {
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
                p = p->next;

            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;

        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    int A[] = {9, 4, 5, 6, 7};

    create_node(A, 5);

    printf("Original List:\n");
    display(head);

    insert(head, 0, 100);

    printf("After inserting 100 at index 0:\n");
    display(head);

    insert(head, 3, 200);

    printf("After inserting 200 at index 3:\n");
    display(head);

    return 0;
}