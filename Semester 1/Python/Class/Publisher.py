class Publisher:
    def __init__(self,pub_name):
        self.__pub_name=pub_name
        
    def display(self):
        print(f"Name of the publisher :{self.__pub_name}")
        
class Book(Publisher):
    def __init__(self,pub_name,book_name,author,no_of_pages):
        super().__init__(pub_name)
        self.book_name=book_name
        self.author=author
        self.no_of_pages=no_of_pages
        
    def display(self):
        print(f"Book Name :{self.book_name}")
        print(f"Author :{self.author}")
        super().display()
        print(f"No of pages :{self.no_of_pages}")
        
class Seller(Book):
    def __init__(self,pub_name,book_name,author,no_of_pages,seller_name,price):
        super().__init__(pub_name,book_name,author,no_of_pages)
        self.seller_name=seller_name
        self.price=price
        
    def display(self):
        super().display()
        print(f"Price :{self.price}")
        print(f"Seller name :{self.seller_name}")
        
book_1=Seller("DC Books","Main Calf","Adolph Hitler",1200,"Aravind K J",650)

book_1.display()