def GCD(a,b):
    if(b==0):
        return a
    else:
        return (b,a%b)


x,y=map(int ,input("enter the value of a and b").split())
print(GCD(x,y))   