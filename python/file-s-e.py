import re

# Take file name from user
filename = input("Enter the file name: ")

# Regex pattern: word starting with 's' and ending with 'e'
pattern = re.compile(r"\bs\w*e\b", re.IGNORECASE)

try:
    with open(filename, "r") as file:
        for line in file:
            if pattern.search(line):
                print(line.strip())
except FileNotFoundError:
    print("File not found. Please check the file name.")
