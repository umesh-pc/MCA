s=input("enter the elements separated with space ").split()
count=0
for n in s:
    if len(n)>=2 and n[0]==n[-1]:
       count+=1
print("number of strings where string length is 2 or more and the first and last characters are same is ...",count)    