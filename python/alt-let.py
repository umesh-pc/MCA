def display_alternate(text, index=0):
    
    if index >= len(text):
        return

   
    print(text[index], end="")

    
    display_alternate(text, index + 2)



line = input("Enter a line of text: ")

print("Alternate characters:")
display_alternate(line)


print()
