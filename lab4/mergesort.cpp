#include<iostream>
#define MAX 100000
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

    int B[MAX];

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

int main()
{
    int A[] = {8,7,4,3,2,4,3,1};
    int n = sizeof(A)/sizeof(A[0]);

    mergesort(A, 0, n-1);

    for(int i=0; i<n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}