def tailfact(n,a):
    if(n==0 or n==1):
        return a
    else:
        return tailfact(n-1,a*n)
    

b=int(input("enter the number: "))
print(tailfact(b,1))

