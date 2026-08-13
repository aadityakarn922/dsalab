#include<stdio.h>

void insertion(int arr[],int n)
{
    int j,x;
    for(int i=1;i<n;i++)
    {
        j=i-1;
        x=arr[i];
        while(j>-1&&arr[j]>x)
        {
            arr[j+1]=arr[j];
            j--;

        }
        arr[j+1]=x;
        
    }
}
int main()
{
    int arr[]={9,5,4,3,2,2};
    insertion(arr,6);
    for(int i=0;i<6;i++)
    {
        printf("%d ",arr[i]);
    }
}