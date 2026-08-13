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
void insertion(int A[],int n)
{
    int j,x;
    for(int i=1;i<n;i++)
    {
        j=i-1;
        x=A[i];
        while(j>-1&&A[j]>x)
        {
            A[j+1]=A[j];
            j--;

        }
        A[j+1]=x;
        
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
    insertion(A,n);
    auto end=chrono::steady_clock::now();
    // display(A,n);
    auto elapsed=chrono::duration_cast<chrono::seconds>(end-start);
    cout<<"function took "<<elapsed.count()<<" s"<<endl;
    
    return 0;
}