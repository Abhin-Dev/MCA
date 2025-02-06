class HappyNumberChecker:
    def __init__(self, number):
        self.number = number

    def is_happy(self):
        def get_next(n):
            # Calculate the sum of the squares of the digits
            return sum(int(digit) ** 2 for digit in str(n))

        seen = set()  # To detect cycles
        current = self.number

        while current != 1 and current not in seen:
            seen.add(current)
            current = get_next(current)

        # If the loop ends with 1, it's a happy number
        return current == 1

# Input from the user
number = int(input("Enter a number to check if it's a happy number: "))

# Create an instance of the HappyNumberChecker class
checker = HappyNumberChecker(number)

# Check and display the result
if checker.is_happy():
    print(f"{number} is a happy number.")
else:
    print(f"{number} is not a happy number.")