import math
print("Program to find roots of a quadratic equation")
a=int(input("Enter the co-efficient of X^2 :"))
b=int(input("Enter the co-efficient of X :"))
c=int(input("Enter the constant :"))
d=(b**2)-(4*a*c)
if(d>0):
    d=math.sqrt(d)
    e=(-b+d)/(2*a)
    f=(-b-d)/(2*a)
    print(f"Real roots are {e} and {f}")
elif(d==0):
    e=(-b)/(2*a)
    print(f"One and only Real root {e}")
else:
    real=-b/(2*a)
    imag=math.sqrt(-d)
    imag=imag/(2*a)
    print(f"Complex roots are {real}+{imag}i and {real}-{imag}i")