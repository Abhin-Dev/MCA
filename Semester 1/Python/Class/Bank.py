class Bank:
    def __init__(self,name,acc_no,branch_name,acc_type,balance=0):
        self.name=name
        self.acc_no=acc_no
        self.balance=balance
        self.branch_name=branch_name
        self.acc_type=acc_type


    def display(self):
        print(f"Name :{self.name}")
        print(f"Account No :{self.acc_no}")
        print(f"Branch Name :{self.branch_name}")
        print(f"Account Type :{self.acc_type}")
        print(f"Balance :{self.balance}")


    def deposit(self):
        amount=int(input("Enter amount to deposit :"))
        if(amount>0):
            self.balance+=amount
        else:
            print("Enter valid amount !!")


    def withdraw(self):
        amount=int(input("Enter amount to withdraw :"))
        if(self.balance>=amount):
            self.balance-=amount
            print("withdrawal Successful")
        else:
            print("Insufficient Balance")


    def check_balance(self):
        print(f"Balance :{self.balance}")


a=input("Name :")
b=input("Account No:")
c=input("Branch Name :")
d=input("Account Type :")
e=int(input("Balance :"))


customer_1=Bank(a,b,c,d,e)


while(True):
    print("1.Deposit\n2.Withdraw\n3.Check Balance\n4.Display\n5.Stop")
    a=int(input("Which operation do you want :"))
    if(a==1):
        customer_1.deposit()
    elif(a==2):
        customer_1.withdraw()
    elif(a==3):
        customer_1.check_balance()
    elif(a==4):
        customer_1.display()
    elif(a==5):
        print("Exiting....")
        break
    else:
        print("Invalid Choice!!")