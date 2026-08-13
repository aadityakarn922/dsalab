#include<stdio.h>

void linearsearch(int A[],int n,int key)
{
    int flag=1;
    for(int i=0;i<n;i++)
    {
        if(A[i]==key)
        {
            flag=1;
            printf("element found at index %d",i);
        }
        if(flag==0){
            printf("element not found");
        }
    }
}
int main()
{
    int A[]={2,5,6,7,8,9};
    int x=5;
    int n=sizeof(A)/sizeof(A[0]);
    linearsearch(A,n,x);
    return 0;
}