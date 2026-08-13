#include<stdio.h>
#include <stdbool.h>
int binarysearch(int arr[],int n,int key, bool searchfirst)
{
    int low=0;
    int high=n-1,result=-1;

    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==key) 
        {
            result=mid;
            if(searchfirst) high=mid-1;
            else
            {
                low=mid+1;
            }
            
        }
        else if(key<arr[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
                
            
        }
        
        
    }
    return result;
}
int main()
{
    int A[]={1,2,2,4,5,6,6,6,7,7,8};
    int x;
    printf("enter the number");
    scanf("%d",&x);
    int n=sizeof(A)/sizeof(A[0]);
    int firstindex=binarysearch(A,n,x,true);
    if(firstindex==-1)
    {
        printf("no of duplicate of %d is %d",x,0);
    }
    else
    {
        int lastindex=binarysearch(A,n,x,false);
        printf("no of duplicate of %d is %d",x,lastindex-firstindex+1);
    }
    return 0;
    
}