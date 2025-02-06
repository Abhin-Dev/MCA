string=input("Enter your string :")
unique=set(string)
print("")
for i in unique:
    count=0
    for j in string:
        if(i==j):
            count+=1
    print(f"Count of {i} in {string} is {count}")