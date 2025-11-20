class Book:
    def __init__(self, title, author):
        self.title = title
        self.author = author


# Taking input from the user
title = input("Enter book title: ")
author = input("Enter author name: ")
publisher = input("Enter publisher (leave blank if unknown): ")

# Create book object
book = Book(title, author)

# Add publisher using setattr() only if user enters something
if publisher.strip():
    setattr(book, "publisher", publisher)

# Check and print result
if hasattr(book, "publisher"):
    print(f"{book.title} written by {book.author} is published by {book.publisher}")
else:
    print(f"{book.title} written by {book.author} is publisher Unknown Publisher")
