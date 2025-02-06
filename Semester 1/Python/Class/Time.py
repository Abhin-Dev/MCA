class Time:
    def __init__(self,hour=0,minitue=0,second=0):
        self.h=hour
        self.m=minitue
        self.s=second
        
    def get_time(self):
        self.h=int(input("Enter Hour :"))
        self.m=int(input("Enter Minitue :"))
        self.s=int(input("Enter Second :"))
        
    def __add__(self,other):
        hour=self.h+ other.h
        min=self.m+ other.m
        sec=self.s+ other.s
        
        if(sec>=60):
            min+=1
            sec=sec%60
        if(min>=60):
            hour+=1
            min=min%60
        if(hour>=24):
            hour=hour%24
        
        result=Time(hour,min,sec)
        return result
    
    def display_time(self):
        # """Display time in HH:MM:SS format."""
        print(f"\nTotal Time: {self.h:02d}:{self.m:02d}:{self.s:02d}")
        
        
#     :02d Format Specifier:

# The 02d part specifies how the numbers (hour, minute, second) should be formatted:
# 0: Adds leading zeros if the number has fewer digits than required.
# 2: Ensures the width of the number is at least 2 characters.
# d: Indicates that the value is a decimal integer.
    
time_1=Time()
time_2=Time()

print("\n---First Time--")
time_1.get_time()
print("\n---Second Time---")
time_2.get_time()

time_3=time_1+time_2

time_3.display_time()