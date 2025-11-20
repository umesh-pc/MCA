def reverse_each(items):
    return [item[::-1] for item in items]
items = input("enter items separated by spaces: ").split()
print("the reversed items" ,reverse_each(items))