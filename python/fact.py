num=int(input("enter a number to find the factorial of it :"))
fact=1
for i in range(1,num+1):
    fact*=i
print("factorial of the %d is %ld"%(num,fact))
