a=0
b=1
num=int(input("enter a number  :"))
for i in range(1,num):
    print(a)
    a,b=b,a+b
    
a=0
b=1
for i in range(1,num):
    a,b=b,a+b
print(a)
