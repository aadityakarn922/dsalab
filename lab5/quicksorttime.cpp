#include<iostream>
#include<cstdlib>
#include<chrono>
#include<ctime>
#define MAX 500000
using namespace std;
void swap(int *p,int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}
void display(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
int partition(int A[], int l, int r)
{
    int x = l;
    int y = r;
    int pivot = A[l];

    while(x < y)
    {
        while(x <= r && A[x] <= pivot)
        {
            x++;
        }

        while(y >= l && A[y] > pivot)
        {
            y--;
        }

        if(x < y)
        {
            swap(&A[x], &A[y]);
        }
        else
        {
            swap(&A[l], &A[y]);
        }
    }

    return y;
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
    int i,n,A[MAX];
    srand(time(0));
    cout<<"enter n"<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        A[i]=rand()%100000;

    }
    // display(A,n);
    auto start=chrono::steady_clock::now();
    quicksort(A,0,n-1);
    auto end=chrono::steady_clock::now();
    // display(A,n);
    auto elapsed=chrono::duration_cast<chrono::seconds>(end-start);
    cout<<"function took "<<elapsed.count()<<" s"<<endl;
    
    return 0;
    
}