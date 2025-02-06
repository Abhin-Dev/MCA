print("Program to find sum of first n even numbers")
n=int(input("Enter the value of n :"))
a=(n*2)+1
sum=0
for i in range(0,a,2):
    sum=sum+i
print(f"Sum of first {n} even numbers :{sum}")