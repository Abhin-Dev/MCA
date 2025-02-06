class Rectangle:
    def __init__(self,length=0,breadth=0):
        self.length=length
        self.breadth=breadth
        
    def get_elements(self):
        self.length=int(input("Enter Length : "))
        self.breadth=int(input("Enter Breadth : "))
        
    def area(self):
        area=self.length*self.breadth
        return area
        
    def __lt__(self,other):
        if(self.area() < other.area()):
            print("\nSecond rectangle has larger area")
        else:
            print("\nFirst rectangle has larger area")
            
            
rectangle_1=Rectangle()
rectangle_2=Rectangle()
print("\n---First Rectangle---")
rectangle_1.get_elements()
print("\n---Second Rectangle---")
rectangle_2.get_elements()
print(f"\nArea of first Rectangle :{rectangle_1.area()}")
print(f"Area of second Rectangle :{rectangle_2.area()}")

rectangle_1 < rectangle_2