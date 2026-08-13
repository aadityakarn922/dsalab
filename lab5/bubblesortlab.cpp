#include<iostream>
#include<cstdlib>
#include<chrono>
#define MAX 500000
using namespace std;


void swap(int *p ,int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;

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

void bubblesort(int A[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j],&A[j+1]);
            }
        }
    }
}

int main()
{
    int i,n,A[MAX],srand(time(0));
    cout<<"enter n"<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        A[i]=rand()%100000;

    }
    // display(A,n);
    auto start=chrono::steady_clock::now();
    bubblesort(A,n);
    auto end=chrono::steady_clock::now();
    // display(A,n);
    auto elapsed=chrono::duration_cast<chrono::seconds>(end-start);
    cout<<"function took "<<elapsed.count()<<" s"<<endl;
    
    
    return 0;

}