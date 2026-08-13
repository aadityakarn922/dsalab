#include<stdio.h>

int binarysearch(int arr[],int low,int high,int key)
{
    if(low>high) return -1;
    int mid=(low+high)/2;
    if(arr[mid]==key)
    return mid;
     if(arr[mid] > key)
        return binarysearch(arr, low, mid - 1, key);
    else
       { return binarysearch(arr, mid + 1, high, key);
         
    }
    
}

    

int main()
{
    int A[]={2,3,4,5,6,7,9};
    int x=7;
    int n=sizeof(A)/sizeof(A[0]);
    int result=binarysearch(A,0,n-1,x);
    if(result==-1)
    {
        printf("element not found");
    }
    else
    {
        printf("element found at index %d",result);
        
        
    }
    return 0;
    
}