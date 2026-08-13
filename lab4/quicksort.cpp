#include<iostream>
#include<cstdlib>
#include<chrono>
using namespace std;
void swap(int *p,int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}
int partition(int A[],int l,int r)
{
    int x=l;
    int y=r;
    int pivot=A[l];
    while(x<y)
    {
        while(A[x]<=pivot and x<=r) {
            x++;
        }
        while(A[y]>pivot and y>=l)
        {
            y--;
        }
        if(x<y) 
        {swap(&A[x],&A[y]);
        }
        else
        {
            swap(&A[l],&A[y]);
        }
        return y;
    }
}



void quicksort(int A[],int l,int r)
{
    if(l<r)
    {
        int p=partition(A,l,r);
        quicksort(A,l,p-1);
        quicksort(A,p+1,r);
    }
}
int main()
{
    int A[]={3,45,8,8,7,4,3,2,1};
    int n=sizeof(A)/sizeof(A[0]);
    quicksort(A,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}