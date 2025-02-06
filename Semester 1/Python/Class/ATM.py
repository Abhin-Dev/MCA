class ATM:
    def __init__(self):
        self.__acc_no=396657240
        self.name="Abhin Dev "
        self.balance=10000
        self.pin=2255
        self.type="Savings"
        
        
    def deposit(self):
        n=int(input("\nEnter Your PIN :"))
        if(n==self.pin):
            amount=int(input("\nEnter Amount To Be Deposited :"))
            if(amount>0):
                self.balance+=amount
                status="Success"
            else:
                print("\nDeposit Amount Should Be Greater Than Zero")
                status="Failure"
            self.reciept(amount,status)
        else:
            print("\n      ----Invalid PIN----")
            print("Last Transaction Has Been Cancelled")
            
            
    def reciept(self,amount,status):
        print("\n----Transaction Reciept----")
        print(f"Customer Name      :{self.name}")
        print(f"Transaction Amount :{amount}")
        print(f"Transaction Type   :Card")
        print(f"Transaction Status :{status}")
        print(f"Account Number     :xxxxxx{str(self.__acc_no)[-3:]}")
        print(f"Available  Balance :{self.balance}")
        
        
    def withdraw(self):
        n=int(input("\nEnter Your PIN :"))
        if(n==self.pin):
            amount=int(input("\nEnter Amount To Be Withdrawed :"))
            if(amount<=self.balance):
                self.balance-=amount
                status="Success"
            else:
                print("\n---Insufficient Balance---\n")
                status="Failure"
            self.reciept(amount,status)
        else:
            print("\n      ----Invalid PIN----")
            print("Last Transaction Has Been Cancelled")
            
            
    def change_pin(self):
        n=int(input("\nEnter Your PIN :"))
        if(n==self.pin):
            new=int(input("\nEnter Your New Pin :"))
            if(len(str(new))==4):
                self.pin=new
                print("\n----New PIN Is Successfully Registered----")
            else:
                print("\nNew PIN Should Contain \"ONLY FOUR NUMBERS\"")
                print("Last Transaction Has Been Cancelled")
        else:
            print("\n      ----Invalid PIN----")
            print("Last Transaction Has Been Cancelled")
            
            
    def acc_details(self):
        n=int(input("\nEnter Your PIN :"))
        if(n==self.pin):
            print("\n  ---Account Details---\n")
            print(f"Customer Name      :{self.name}")
            print(f"Account Number     :{self.__acc_no}")
            print(f"Available  Balance :{self.balance}")
            print(f"Account Type       :{self.type}")
        else:
            print("\n      ----Invalid PIN----")
            print("Last Transaction Has Been Cancelled")
        
                       
customer_1=ATM()
print("\n------Welcome To State Bank Of India------")
while(True):
    print("\n1.Account Details\n2.Cash Deposit\n3.Cash Withdraw\n4.Change PIN\n5.Exit")
    choice=int(input("\nSelect Your Choice :"))
    match(choice):
        case 1:
            customer_1.acc_details()
        case 2:
            customer_1.deposit()
        case 3:
            customer_1.withdraw()
        case 4:
            customer_1.change_pin()
        case 5:
            print("\n---Thankyou For Using State Bank Of India---")
            print("              Have A Nice Day")
            break
        case _:
            print("\n   --Invalid Choice---")
            print("Please Select A Valid Option")    
        
    
