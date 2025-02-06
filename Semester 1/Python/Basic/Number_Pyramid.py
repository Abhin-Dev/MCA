n=int(input("How many numbers do you want in pyramid :"))
for i in range(1,n+1):
    for j in range(1,i+1):
        print(i*j,end=" ")
    print("")