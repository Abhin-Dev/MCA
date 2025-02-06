from Area import Circle_area
from Area import Square_area
from Area import Rectangle_area
from Area.Volume import Circle_vol
from Area.Volume import Square_vol
from Area.Volume import Rectangle_vol
from Area.Volume.Perimeter import Circle_peri
from Area.Volume.Perimeter import Square_peri
from Area.Volume.Perimeter import Rectangle_peri

print("\n-----Circle-----\n")
r=int(input("Enter Radius : "))
area=Circle_area.area(r)
perimeter=Circle_peri.perimeter(r)
volume=Circle_vol.volume(r)
print(f"\nArea : {area}")
print(f"Perimeter : {perimeter}")
print(f"Volume : {volume}")


print("\n-----Square-----\n")
a=int(input("Enter Length : "))
area=Square_area.area(a)
perimeter=Square_peri.perimeter(a)
volume=Square_vol.volume(a)
print(f"\nArea : {area}")
print(f"Perimeter : {perimeter}")
print(f"Volume : {volume}")


print("\n-----Rectangle-----")
l=int(input("Enter Length : "))
b=int(input("Enter Breadth : "))
h=int(input("Enter Height : "))
area=Rectangle_area.area(l,b)
perimeter=Rectangle_peri.perimeter(l,b)
volume=Rectangle_vol.volume(l,b,h)
print(f"\nArea : {area}")
print(f"Perimeter : {perimeter}")
print(f"Volume : {volume}")