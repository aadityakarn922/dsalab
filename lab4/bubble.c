#include<stdio.h>
#include<stdlib.h>

void swap(int arr[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        if(arr[j]>arr[j+1])
        {
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
}

int main()
{
    int arr[6]={3,6,3,7,8,3};
    swap(arr,6);
}