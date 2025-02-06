class ArmstrongNumberChecker:
    def __init__(self, number):
        self.number = number

    def is_armstrong(self):
        # Convert the number to a string to easily iterate over digits
        num_str = str(self.number)
        # Get the number of digits
        num_digits = len(num_str)
        # Calculate the sum of digits raised to the power of num_digits
        sum_of_powers = sum(int(digit) ** num_digits for digit in num_str)
        # Check if the sum is equal to the original number
        return sum_of_powers == self.number

# Input from the user
number = int(input("Enter a number to check if it's an Armstrong number: "))

# Create an instance of the ArmstrongNumberChecker class
checker = ArmstrongNumberChecker(number)

# Check and display the result
if checker.is_armstrong():
    print(f"{number} is an Armstrong number.")
else:
    print(f"{number} is not an Armstrong number.")