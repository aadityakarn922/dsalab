#include<stdio.h>

long int tfact(int n,long int accumulator)
{
    if(n==1)
    {
        return accumulator;
    }
    else {
        return tfact(n-1,accumulator*n);
    }
}
int main()
{
    int num;
    printf("enter the number");
    scanf("%d",&num);
   long int res= tfact(num,1);
    printf("the factorial of %d i is %ld",num,res);
    return 0;
}