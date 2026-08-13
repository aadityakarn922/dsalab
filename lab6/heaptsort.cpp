#include<iostream>
#include<chrono>
#include<cstdlib>
#define MAX 500000
using namespace std;

void swap(int *p,int *q){
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;
}
void MAX_HEAPIFY(int A[],int i,int n){
    int l=2*i;
   int R=2*i+1;
   int largest=i;
    if ((l<=n) && A[l]>A[largest]){
       largest =l;
    }
    if ((R<=n) && A[R]>A[largest]){
       largest =R;
    }
    if (largest!=i){
        swap(&A[i],&A[largest]);
        MAX_HEAPIFY(A,largest,n);
    }
}

void build_max_heap(int A[],int n){
    for(int i=n/2;i>=1;i--){
        MAX_HEAPIFY(A,i,n);
    }
}

void heapsort(int A[],int n)
{
    build_max_heap(A,n);
    for (int i=n; i>=2; i--) {
        swap(&A[1], &A[i]);
        MAX_HEAPIFY(A, 1, i - 1);
    }
}

int main(){
    int i,n,A[MAX];
    
    cout<<"Enter the number>> ";
    cin>>n;
    srand(time(0));
    for (i=0;i<n;i++){
        A[i]=rand()%100000;
    }

auto start = chrono::steady_clock::now();
heapsort(A,n);
// display(A, n);

auto end= chrono::steady_clock::now();
auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end-start);
cout << "Function took " << elapsed.count() << " ms" << std::endl;
return 0;
}

