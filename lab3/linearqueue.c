#include<stdio.h>
#define true 1
#define false 0
#define max 10
struct QUEUE
{
    int FRONT;
    int REAR;
    int data[max];
    
};
int isFull(struct QUEUE *s)
{
    if(s->REAR==max-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int isEMPTY(struct QUEUE *s)
{
    if(s->REAR<s->FRONT)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
void ENQUEUE(struct QUEUE *s,int element)
{
    s->REAR+=1;
    s->data[s->REAR]=element;
}
int DEQUEUE(struct QUEUE *s)
{
   int value=s->data[s->FRONT];
   s->FRONT+=1;
   return value;
}
int checkFRONT(struct QUEUE *s)
{
    return s->data[s->FRONT];
}
int checkREAR(struct QUEUE *s)
{
    return s->data[s->REAR];
}
int main()
{
    struct QUEUE q;

    
    q.FRONT = 0;
    q.REAR = -1;

    
    ENQUEUE(&q, 10);
    ENQUEUE(&q, 20);
    ENQUEUE(&q, 30);

    
    printf("Front= %d\n", checkFRONT(&q));
    printf("Rear=%d\n", checkREAR(&q));

    
    printf("Deleted=%d\n", DEQUEUE(&q));
    printf("Deleted= %d\n", DEQUEUE(&q));

    
    printf("Front now= %d\n", checkFRONT(&q));
    printf("Rear now=%d\n", checkREAR(&q));

    return 0;
}