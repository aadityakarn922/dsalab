#include<iostream>
#include<chrono>
#include<cstdlib>
#define MAX 500000
using namespace std;
void swap(int *p,int *q)
{
    int temp=*p;
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
void selectionsort(int A[],int n)
{
    int least;
    int position;
    for(int i=0;i<n-1;i++)
    {
        least=A[i];
        position=i;
        for(int j=0;j<n;j++)
        {
            if(A[j]<least)
            {
                least=A[j];
                position=j;
            }
        }
        if(i!=position)
        {
            swap(&A[i],&A[position]);
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
    selectionsort(A,n);
    auto end=chrono::steady_clock::now();
    // display(A,n);
    auto elapsed=chrono::duration_cast<chrono::seconds>(end-start);
    cout<<"function took "<<elapsed.count()<<" s"<<endl;
    
    return 0;
}