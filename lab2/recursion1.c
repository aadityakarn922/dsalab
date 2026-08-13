#include<stdio.h>
long int fact(int n)
{
    if(n==0||n==1)
    return 1;
    else {
        return n*fact(n-1);
    }
}

int main(){
    int num;
    printf("enter the number");
    scanf("%d",&num);
    printf("the factorial of number %d is %ld",num,fact(num));
    
}
