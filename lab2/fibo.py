from timeit import default_timer
def fibo(n):
    
    
    if(n==1 or n==2):
        return 1
    else:
        return fibo(n-1)+fibo(n-2)

c=int(input("enter the number"))

start=default_timer()
x=fibo(c)
print(x)
end=default_timer()
print(f"time taken{(end-start):.6f}")
