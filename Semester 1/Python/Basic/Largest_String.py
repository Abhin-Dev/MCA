a=[]
n=int(input("How many strings do you want to pass:"))
for i in range(n):
    value=input("Enter string :")
    a.append(value)

longest_word=max(a,key=len)
print(f"The longest word is {longest_word}")
print(f"Length of the longest word :{len(longest_word)}")
    