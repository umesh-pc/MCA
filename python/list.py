
input = input("Enter values separated by spaces: ")
items = input.split()

total = 0

for item in items:
    if item.isalpha():
        print("'%s' is a string or non-integer, skipping." % item)
    else:
       total += float(item)

print("Sum of numeric elements:", total)
