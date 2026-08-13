from timeit import default_timer
def fact(n):
    if n==0 or n==1:
        return 1
    else:
        return n*fact(n-1)
    
a=int(input("enter the number"))
start=default_timer()
result=fact(a)
end=default_timer()
print("Result is",result)
print(f"time taken is {(end-start):.6f} seconds")


