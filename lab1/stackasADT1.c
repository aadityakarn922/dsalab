#include <stdio.h>

#define true 1
#define false 0
#define MAX 5

struct STACK {
    int TOS;
    int data[MAX];
};

int isFull(struct STACK *s)
{
    return (s->TOS == MAX - 1) ? true : false;
}

int isEmpty(struct STACK *s)
{
    return (s->TOS == -1) ? true : false;
}

void push(struct STACK *s, int element)
{
    s->data[++(s->TOS)] = element;
}

int pop(struct STACK *s)
{
    return s->data[(s->TOS)--];
}

int main()
{
    int choice, value;
    struct STACK s = {-1};

    do
    {
        printf("\n1. Push\n2. Pop\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(isFull(&s))
                {
                    printf("STACK Overflow\n");
                }
                else
                {
                    printf("Enter element: ");
                    scanf("%d", &value);
                    push(&s, value);
                    printf("%d was pushed\n", value);
                }
                break;

            case 2:
                if(isEmpty(&s))
                {
                    printf("STACK Underflow\n");
                }
                else
                {
                    printf("%d was popped\n", pop(&s));
                }
                break;

            case 3:
                printf("Bye!\n");
                break;

            default:
                printf("Enter only 1, 2 or 3\n");
        }

    } while(choice != 3);

    return 0;
}