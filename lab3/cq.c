#include<stdio.h>
#define true 1
#define false 0
#define MAX 5

struct CirQUE
{
    int FRONT;
    int  REAR;
    int size;
    int data[MAX];
};
int isFull(struct CirQUE *s)
{
    if(s->size==MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int isEMPTY(struct CirQUE *s)
{
    if(s->size==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
void ENQUEUE(struct CirQUE*s,int element)
{
    if (isFull(s))
    {
        printf("the queue is full");
    }
    else
    {
        s->REAR=(s->REAR+1)%MAX;
        s->data[s->REAR]=element;
        s->size=(s->size+1);
    }
    
    
}
int DEQUEUE(struct CirQUE *s)
{
    if (isEMPTY(s))
    {
        printf("Queue Underflow\n");
        return 0;
        
    }
    else
    {
        int element = s->data[s->FRONT];

    s->FRONT = (s->FRONT + 1) % MAX;
    s->size=s->size-1;

    return element;
    }
    

    
}
int checkFRONT(struct CirQUE*s)
{
    if(isEMPTY(s))
    {
        printf("the queue is empty");
        return 0;
    }
    else
    {
        int element=s->data[s->FRONT];
        return element;
    }
    
}
int checkREAR(struct CirQUE*s)
{
    if(isEMPTY(s))
    {
        printf("the queue is empty");
        return 0;
    }
    else
    {
        int element=s->data[s->REAR];
        return element;
    }
    
}
int main()
{
    struct CirQUE q;

    q.FRONT = 0;
    q.REAR = -1;
    q.size = 0;

    ENQUEUE(&q, 10);
    ENQUEUE(&q, 20);
    ENQUEUE(&q, 30);

    printf(" front=%d\n", checkFRONT(&q));
    printf("at rear=%d\n", checkREAR(&q));

    printf("deleted=%d\n", DEQUEUE(&q));

    printf("at front=%d\n", checkFRONT(&q));

    return 0;
}