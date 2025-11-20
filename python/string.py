def join_with_dash(lst, index=0):
   
    if not lst:
        return ""

   
    if index == len(lst) - 1:
        return lst[index]

    
    return lst[index] + "-" + join_with_dash(lst, index + 1)



user_input = input("Enter items separated by spaces: ")


items = user_input.split()


result = join_with_dash(items)

print("Joined string:", result)
