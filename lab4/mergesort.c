#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int i,j,k;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
        L[i]=arr[l+i];
        
    }
    for(j=0;j<n2;j++)
    {
        R[j]=arr[m+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1&&j<n2)
    {
        if(arr[i]<=arr[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
                
            
        }
        k++;
        
    }
    while(i<n1) //for remaininng elements
    {
        arr[k]=L[i];
        k++;
        i++;
    }
    while(j<n2) //for remaininng elements
    {
        arr[k]=R[j];
        k++;
        j++;
    }
}
void mergesort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
         mergesort(arr,l,m);
      mergesort(arr,m+1,r);
      merge(arr,l,m,r);

    }

}
int main()
{
    int arr[]={2,4,5,6,7,3,1,4,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}