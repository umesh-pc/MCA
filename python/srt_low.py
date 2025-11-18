def arrange_lowercase_first(s):
    lower = ""
    upper = ""

    for ch in s:
        if ch.islower():
            lower += ch
        else:
            upper += ch

    return lower + upper
s=input("enter a string")
print("the arranged string: ",(arrange_lowercase_first(s)))