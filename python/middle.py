def middle_three(s):
    if len(s) <= 7 or len(s) % 2 == 0:
      print("String length must be odd and greater than 7")
    else:
      mid = len(s) // 2
      return s[mid - 1 : mid + 2]
   
   
s=input("enter a string")
print("the middle 3 characters are: ",(middle_three(s)))