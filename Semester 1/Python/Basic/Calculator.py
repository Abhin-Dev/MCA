def numbers():
    a=int(input("Enter first number :"))
    b=int(input("Enter second number :"))
    return a,b

while(True):
    print("1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Stop")
    c=int(input("Enter your choice:"))
    if(c==1):
        a,b=numbers()
        sum=a+b
        print("Sum :",sum)
    elif(c==2):
        a,b=numbers()
        diff=a-b
        print(f"Difference : {diff}")
    elif(c==3):
        a,b=numbers()
        pro=a*b
        print("Product :",pro)
    elif(c==4):
        a,b=numbers()
        if(b!=0):
            quo=a/b
            print("Quotient :",quo)
        else:
            print("Mathematically division by zero is  infinity")
    elif(c==5):
        print("Exiting...")
        break
    else:
        print("Inavalid choice")