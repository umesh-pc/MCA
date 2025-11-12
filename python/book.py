class publisher():
    def __init__(self,name):
        self.__name= name
        

    def get(self):
        return self.__name
        
class book(publisher):
    def __init__(self,name,title,author):
        self.__title=title
        self.__author=author
        super().__init__(name)
        

    def get(self):
        x=super().get()
        return self.__title,self.__author,x
class python(book):
    def __init__(self, name, title, author,price,no_of_pages):
        super().__init__(name, title, author)
        self.__price=price
        self.__no_of_pages=no_of_pages
       

    def get(self):
        n= super().get()
        return self.__price, self.__no_of_pages,n
        

my_python_book = python("Addison-Wesley", "Code Complete 2", "Steve McConnell", 59.99, 960)


details = my_python_book.get()
print(f"Price and Pages: {details}") 
