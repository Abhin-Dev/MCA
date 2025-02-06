print("Program to write multiplication table")
a=int(input("Enter your number :"))
n=int(input("Enter your limit :"))
for i in range(1,n+1,1):
    print(f"{a} x {i} = {a*i}")
