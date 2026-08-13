#include<stdio.h>

int iGCD(int a ,int b){
    if(b==0)
    return a;
    else
    {
        while(b!=0)
        {
            int r=a%b;
            a=b;
            b=r;
        }
        return a;
    }
    
}
int main()
{
    int a ,b;
    printf("enter the value of a and b");
    scanf("%d%d",&a,&b);
    iGCD(a,b);
}