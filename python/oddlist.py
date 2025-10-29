str=input("enter numbers separated by spaces.").split()
for n in str:
    n=int(n)
    if n==237:
        break
    if not n%2 :
        print(n)