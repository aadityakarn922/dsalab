exp=input("enter the expression")
arr=exp.split()

def evualatepostfix(arr):
    stack=[]
    for x in arr:
        try:
            stack.append(int(x)) #if numnber
        except:
            b=stack.pop() # if operator:::::
            a=stack.pop()
        
        if x=='+':
            stack.append(a+b)
        elif x=='-':
            stack.append(a-b)
        elif x=='*':
            stack.append(a*b)
        elif x=='/':
            stack.append(a//b)
    return stack[-1]  

print("result =",evualatepostfix(arr))      
        

