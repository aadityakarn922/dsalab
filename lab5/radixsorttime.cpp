#include<iostream>
#include<cstdlib>
#include<chrono>
#define MAX 500000
using namespace std;
int getmax(int arr[],int n)
{
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }

    }
    return max;

    
}

void countingsort(int arr[],int n,int pos)
{
    int output[n];
    int count[10]={0};
    for(int i=0;i<n;i++){
        count[(arr[i]/pos)%10]++;


    }
    for(int i=1;i<10;i++)
    {
        count[i]+=count[i-1];

    }
    for(int i=n-1;i>=0;i--)
    {
        int digit=(arr[i]/pos)%10;
        output[--count[digit]]=arr[i];
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=output[i];
    }
}
void radixsort(int arr[],int n)
{
    int max=getmax(arr,n);
    for(int pos=1;max/pos>0;pos*=10)
    {
        countingsort(arr,n,pos);
    }
}
void display(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
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
    radixsort(A,n);
    auto end=chrono::steady_clock::now();
    // display(A,n);
    auto elapsed=chrono::duration_cast<chrono::seconds>(end-start);
    cout<<"function took "<<elapsed.count()<<" s"<<endl;
    
    return 0;
    
}