#include<stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubble(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
int main()
{
     int arr[]={9,5,4,3,2,2};
    bubble(arr,6);
    for(int i=0;i<6;i++)
    {
        printf("%d ",arr[i]);
    }
}