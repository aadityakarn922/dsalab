#include<stdio.h>

void TOH(int n,char source,char dest,char temp)
{
    if(n==1)
    {
        printf("move disk %d from %c to %c\n",n,source ,dest);
        
    }
    else
    {
        TOH(n-1,source,temp,dest);
        printf("move disc %d from %c to %c\n",n,source,dest);
        TOH(n-1,temp,dest,source);
    }
    
}

int main()
{
    int num;
    printf("enter the number of disk");
    scanf("%d",&num);
    TOH(num,'A','C','B');
    return 0;
}