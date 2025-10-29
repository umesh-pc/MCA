def rev(n):
    if not len(n) :return ""
    else : return n[-1]+rev(n[:-1])

n=input("enter your full name")
print(n)
print("reversed name",rev(n))    