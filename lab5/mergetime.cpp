#include<iostream>
#include<cstdlib>
#include<chrono>
#include<ctime>
#define MAX 500000
int B[MAX];
using namespace std;

void merge(int A[], int l, int m, int r);

void mergesort(int A[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;

        mergesort(A, l, m);
        mergesort(A, m + 1, r);

        merge(A, l, m, r);
    }
}

void merge(int A[], int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;



    while(i <= m && j <= r)
    {
        if(A[i] <= A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }

    while(i <= m)
    {
        B[k++] = A[i++];
    }

    while(j <= r)
    {
        B[k++] = A[j++];
    }

    for(k = l; k <= r; k++)
    {
        A[k] = B[k];
    }
}

void display(int A[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;

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
    mergesort(A,0,n-1);
    auto end=chrono::steady_clock::now();
    // display(A,n);
    auto elapsed=chrono::duration_cast<chrono::seconds>(end-start);
    cout<<"function took "<<elapsed.count()<<" s"<<endl;
    
    return 0;
    
}