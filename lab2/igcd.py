from timeit import default_timer
def igcd(a,b):
    if(b==0):
        return a
    else:
        while(b!=0):
            r=a%b
            a=b
            b=r
        return a

x,y=map(int,input("enter the value of a and b").split())
z=igcd(x,y)
start=default_timer()
print(z)   
end=default_timer()
print(f"time taken is{(end-start)}:.6f")
