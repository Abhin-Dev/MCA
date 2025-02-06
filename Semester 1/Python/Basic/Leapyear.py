n=int(input("Enter year :"))
if(n%100==0):
    if(n%400==0):
        print(f"{n} is leap year")
    else:
        print(f"{n} is not leap year")
elif(n%4==0):
    print(f"{n} is leap year")
else:
    print(f"{n} is not leap year")