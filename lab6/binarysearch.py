import numpy as np
A=np.array([2,4,5,6,68,4,6])

def binarysearch(A,l,r,key):

    if(l>r):
        return -1
    else:
        mid=(l+r)//2
    
        if(A[mid]==key):
            print(f"succesfullfound element at{mid} iindex ")
            return 
    
        elif (A[mid]<key):
            return binarysearch(A,mid+1,r,key)
        else:
            return binarysearch(A,l,mid-1,key)
    

key=int(input("enter numbeer"))
binarysearch(A,0,len(A),key)


