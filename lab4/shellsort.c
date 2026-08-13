#include<stdio.h>

void shellsort(int arr[],int n)
{
    int gap,i,j;
    for(gap=n/2;gap>0;gap /=2)
    {
        for(int i=gap;i<n;i++)
        {
            int temp=arr[i];
            j=i;
            while(j>=gap && arr[j-gap]>temp)
            {
                arr[j]=arr[j-gap];
                j=j-gap;
            }
            arr[j]=temp;
        }
    }
}
int main()
{
    printf("enter the number of element");
    int n;
    scanf("%d",&n);

    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    shellsort(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

}