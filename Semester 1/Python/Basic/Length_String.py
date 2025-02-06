a=input("Enter the first string :")
b=input("Enter second string :")
c=input("Enter third string :")
if(len(a)>len(b) and len(a)>len(c)):
    print(f"{a} has most no of characters")
    print(f"Charcters :{len(a)}")
elif(len(b)>len(a) and len(b)>len(c)):
    print(f"{b} has most no of characters")
    print(f"Charcters :{len(b)}")
else:
    print(f"{c} has most no of characters")
    print(f"Charcters :{len(c)}")